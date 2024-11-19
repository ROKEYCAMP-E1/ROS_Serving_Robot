import sys,os
import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from rclpy.action.client import GoalStatus
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.qos import QoSDurabilityPolicy, QoSHistoryPolicy, QoSProfile, QoSReliabilityPolicy
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import *
from PyQt5 import uic

from ros_study_msgs.srv import OrderCustomer
from ros_study_msgs.msg import MoveRobot#추가
import threading
import sqlite3,uuid
from datetime import datetime
import subprocess
from PyQt5.QtWidgets import QApplication, QWidget
from geometry_msgs.msg import PointStamped
from geometry_msgs.msg import Point, Quaternion
from nav2_msgs.action import NavigateToPose
from nav2_msgs.srv import SetInitialPose

class KitchenNode(Node):
    def __init__(self,gui=None):
        super().__init__('kitchen_display')
        self.gui = gui

        # Order-related attributes
        self.order_list = []
        self.menu = ['', '콩나물 국밥', '돼지 국밥', '순대 국밥', '설렁탕']
        self.price = [0, 4000, 5000, 5500, 7000]
        self.robot_command_list = ['move to table 1', 'move to table 2', 'move to table 3',
                                'move to table 4', 'move to table 5', 'move to table 6',
                                'move to table 7', 'move to table 8', 'move to table 9',
                                'move to table', 'move to kitchen']
        self.init_pose = [-2.0, -0.5, 0.0, 1.0]
        self.goal_poses = [
            [1.6, 1.0], [1.6, 0.0], [1.6, -1.0],
            [0.5, 1.0], [0.5, 0.0], [0.5, -1.0],
            [-0.6, 1.0], [-0.6, 0.0], [-0.6, -1.0],
            [-1.4, 1.8], [-2.0, -0.5]
        ]
        # ROS2 Callback Group and QoS Profile
        self.callback_group = ReentrantCallbackGroup()
        self.declare_parameter('qos_depth', 10)
        qos_depth = self.get_parameter('qos_depth').value
        QOS_RKL10V = QoSProfile(
            reliability=QoSReliabilityPolicy.RELIABLE,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=qos_depth,
            durability=QoSDurabilityPolicy.TRANSIENT_LOCAL)

        # Service to receive orders
        self.order_service_server = self.create_service(
            OrderCustomer,
            'order',
            self.get_order_kitchen,
            callback_group=self.callback_group)

        self.moverobot_topic_subscriber = self.create_subscription(
            MoveRobot,
            'move_robot',
            self.get_move_robot,
            QOS_RKL10V,
            callback_group=self.callback_group)
        
        self.set_initial_pose_service_client = self.create_client(
            SetInitialPose, 
            '/set_initial_pose'
            )
        
        # create Action Client
        self.navigate_to_pose_action_client = ActionClient(
            self, 
            NavigateToPose, 
            "navigate_to_pose")
        
        # Init function
        while not self.set_initial_pose_service_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service /set_initial_pose not available, waiting again...')
        self.set_initial_pose(*self.init_pose)

    def get_order_kitchen(self, request, response):
        menu_nums = list(request.menu_num)
        quantity_nums = list(request.quantity_num)
        table_number = request.table_number
        order_round = request.order_round

        # Pair menu items with quantities
        items = list(zip(menu_nums, quantity_nums))

        # Log the order details
        for menu_num, quantity in items:
            self.get_logger().info('{} {}개 주문~!'.format(self.menu[menu_num], quantity))
        self.get_logger().info('주문 완료 테이블 번호: {}'.format(table_number))

        # Pass data to GUI for display
       
         
        # Insert order into the database
        self.insert_DB(menu_nums, quantity_nums)

        if self.gui:
            self.gui.display_order(table_number, items, order_round)
            QMetaObject.invokeMethod(
                self.gui,
                "display_order",
                Qt.QueuedConnection,
                Q_ARG(int, table_number),
                Q_ARG(list, items),
                Q_ARG(int, order_round)
            )

        response.order_check = 1  # Indicate order received
        return response

    def get_move_robot(self, msg):
        self.topic_move_robot = msg.topic_move_robot
        if self.topic_move_robot in range(10):
            self.update_robot_status(self.robot_command_list[self.topic_move_robot])
        else:
            self.get_logger().error('올바른 입력을 받지 못했습니다.')

    def set_initial_pose(self, x, y, z, w):
        # Set initial pose logic here
        # Call the ROS2 service '/set_initial_pose'
        request = SetInitialPose.Request()
        request.pose.header.frame_id = "map"
        request.pose.pose.pose.position.x = x
        request.pose.pose.pose.position.y = y
        request.pose.pose.pose.position.z = 0.0

        request.pose.pose.pose.orientation.x = 0.0
        request.pose.pose.pose.orientation.y = 0.0
        request.pose.pose.pose.orientation.z = z
        request.pose.pose.pose.orientation.w = w

        future = self.set_initial_pose_service_client.call_async(request)
        rclpy.spin_until_future_complete(self, future)

        if future.result() is not None:
            self.get_logger().info("Initial pose set successfully.")
        else:
            self.get_logger().error("Failed to set initial pose.")
        
    def navigate_to_pose_send_goal(self, i):
        wait_count = 1
        while not self.navigate_to_pose_action_client.wait_for_server(timeout_sec=0.1):
            if wait_count > 3:
                message = "[WARN] Navigate action server is not available."
                self.gui.textBrowser.append(message)
                return False
            wait_count += 1
            
        goal_msg = NavigateToPose.Goal()
        goal_msg.pose.header.frame_id = "map"
        goal_msg.pose.pose.position.x = self.goal_poses[i][0]
        goal_msg.pose.pose.position.y = self.goal_poses[i][1]
        goal_msg.pose.pose.position.z = 0.0
        goal_msg.pose.pose.orientation.x = 0.0
        goal_msg.pose.pose.orientation.y = 0.0
        goal_msg.pose.pose.orientation.z = 0.0
        goal_msg.pose.pose.orientation.w = 1.0

        self.send_goal_future = self.navigate_to_pose_action_client.send_goal_async(
            goal_msg,
            feedback_callback=self.navigate_to_pose_action_feedback)
        self.send_goal_future.add_done_callback(self.navigate_to_pose_action_goal)
        
        return True   
    
    def navigate_to_pose_action_goal(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            message = "[WARN] Action goal rejected."
            self.gui.textBrowser.append(message)
            return

        message = "[INFO] Action goal accepted."
        self.gui.textBrowser.append(message)
        self.action_result_future = goal_handle.get_result_async()
        self.action_result_future.add_done_callback(self.navigate_to_pose_action_result)
    
    #example.py 이식
    def navigate_to_pose_action_feedback(self, feedback_msg):
        action_feedback = feedback_msg.feedback
        # self.get_logger().info("Action feedback: {0}".format(action_feedback))
    
    #example.py 이식
    def navigate_to_pose_action_result(self, future):
        action_status = future.result().status
        action_result = future.result().result
        if action_status == GoalStatus.STATUS_SUCCEEDED:

            message = "[INFO] Action succeeded!."
            self.gui.textBrowser.append(message)

        else:
            message = f"[WARN] Action failed with status: {action_status}"
            self.gui.textBrowser.append(message)


    def go_button_clicked(self, i):
        self.node.navigate_to_pose_send_goal(i)


    def insert_data(self, conn, cursor, datetime_value, uuid_value, menu_name, quantity, total_price):
        insert_query = '''
        INSERT INTO customer_order (datetime, uuid, menu_name, quantity, total_price)
        VALUES (?, ?, ?, ?, ?)
        '''
        cursor.execute(insert_query, (datetime_value, uuid_value, menu_name, quantity, total_price))
        conn.commit()

    def insert_DB(self, menu_nums, quantity_nums):
        conn = sqlite3.connect('order.db')
        cursor = conn.cursor()
        datetime_value = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

        for menu_num, quantity in zip(menu_nums, quantity_nums):
            if menu_num < 1 or menu_num >= len(self.menu):
                continue
            menu_name = self.menu[menu_num]
            price = self.price[menu_num]
            total_price = price * quantity
            uuid_value = str(uuid.uuid4())
            self.insert_data(conn, cursor, datetime_value, uuid_value, menu_name, quantity, total_price)

        conn.close()
        print("데이터가 성공적으로 삽입되었습니다.")

    def open_database(self):
        db_path = "/home/kimdahun/order_v8_ws/order.db"
        if os.path.exists(db_path):
            try:
                subprocess.run(["sqlitebrowser", db_path], check=True)
            except FileNotFoundError:
                print("sqlitebrowser 프로그램이 설치되어 있지 않습니다.")
            except Exception as e:
                print(f"데이터베이스를 여는 중 오류가 발생했습니다: {e}")
        else:
            print(f"{db_path} 데이터베이스 파일을 찾을 수 없습니다.")

    def display_order(self, table_number, items, order_round):
        round_table_widgets = {
            1: self.gui.tableWidget,
            2: self.gui.tableWidget_2,
            3: self.gui.tableWidget_3,
            4: self.gui.tableWidget_4,
            5: self.gui.tableWidget_5,
            6: self.gui.tableWidget_6,
        }

        target_table = round_table_widgets.get(order_round)
        if target_table is None:
            print(f"주문 차수 {order_round}에 해당하는 테이블이 없습니다.")
            return

        for menu_num, quantity in items:
            menu_name = self.menu[menu_num]
            row_position = target_table.rowCount()
            target_table.insertRow(row_position)
            target_table.setItem(row_position, 0, QTableWidgetItem(str(table_number)))
            target_table.setItem(row_position, 1, QTableWidgetItem(menu_name))
            target_table.setItem(row_position, 2, QTableWidgetItem(str(quantity)))

    def clear_and_shift_orders(self, index):
        table_widgets = [
            self.gui.tableWidget, self.gui.tableWidget_2, self.gui.tableWidget_3,
            self.gui.tableWidget_4, self.gui.tableWidget_5, self.gui.tableWidget_6
        ]

        table_widgets[index].clearContents()
        table_widgets[index].setRowCount(0)

        for i in range(index, len(table_widgets) - 1):
            self.copy_table_contents(table_widgets[i + 1], table_widgets[i])
            table_widgets[i + 1].clearContents()
            table_widgets[i + 1].setRowCount(0)

    def copy_table_contents(self, source_table, dest_table):
        dest_table.setRowCount(source_table.rowCount())
        dest_table.setColumnCount(source_table.columnCount())
        for row in range(source_table.rowCount()):
            for col in range(source_table.columnCount()):
                item = source_table.item(row, col)
                if item:
                    dest_table.setItem(row, col, QTableWidgetItem(item.text()))

    def update_robot_status(self, status_message):
        self.robotstatus.setText(status_message)

    def show_control_ui(self):
        """Show the Control UI."""
        self.control_ui.show()



    

class KitchenUI(QMainWindow):
    def __init__(self,node):
        super().__init__()
        uic.loadUi("kitchenlist.ui", self)
        
        self.node = node  # Store the KitchenNode reference
        self.control_ui = ControlUI(node)
        self.pushButton_7.clicked.connect(self.show_control_ui)

        self.menu = ['', '콩나물 국밥', '돼지 국밥', '순대 국밥', '설렁탕']
        self.price = [0, 4000, 5000, 5500, 7000]

        # Connect buttons to handlers
        self.pushButton.clicked.connect(lambda: self.clear_and_shift_orders(0))
        self.pushButton_2.clicked.connect(lambda: self.clear_and_shift_orders(1))
        self.pushButton_3.clicked.connect(lambda: self.clear_and_shift_orders(2))
        self.pushButton_4.clicked.connect(lambda: self.clear_and_shift_orders(3))
        self.pushButton_5.clicked.connect(lambda: self.clear_and_shift_orders(4))
        self.pushButton_6.clicked.connect(lambda: self.clear_and_shift_orders(5))

        self.DB.clicked.connect(self.open_database)

    def insert_data(self, conn, cursor, datetime_value, uuid_value, menu_name, quantity, total_price):
        insert_query = '''
        INSERT INTO customer_order (datetime, uuid, menu_name, quantity, total_price)
        VALUES (?, ?, ?, ?, ?)
        '''
        cursor.execute(insert_query, (datetime_value, uuid_value, menu_name, quantity, total_price))
        conn.commit()

    def insert_DB(self, menu_nums, quantity_nums):
        conn = sqlite3.connect('order.db')
        cursor = conn.cursor()
        datetime_value = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

        for menu_num, quantity in zip(menu_nums, quantity_nums):
            if menu_num < 1 or menu_num >= len(self.menu):
                continue
            menu_name = self.menu[menu_num]
            price = self.price[menu_num]
            total_price = price * quantity
            uuid_value = str(uuid.uuid4())
            self.insert_data(conn, cursor, datetime_value, uuid_value, menu_name, quantity, total_price)

        conn.close()
        print("데이터가 성공적으로 삽입되었습니다.")

    def open_database(self):
        db_path = "/home/kimdahun/order_v8_ws/order.db"
        if os.path.exists(db_path):
            try:
                subprocess.run(["sqlitebrowser", db_path], check=True)
            except FileNotFoundError:
                print("sqlitebrowser 프로그램이 설치되어 있지 않습니다.")
            except Exception as e:
                print(f"데이터베이스를 여는 중 오류가 발생했습니다: {e}")
        else:
            print(f"{db_path} 데이터베이스 파일을 찾을 수 없습니다.")

    def display_order(self, table_number, items, order_round):
        round_table_widgets = {
            1: self.tableWidget,
            2: self.tableWidget_2,
            3: self.tableWidget_3,
            4: self.tableWidget_4,
            5: self.tableWidget_5,
            6: self.tableWidget_6,
        }

        target_table = round_table_widgets.get(order_round)
        if target_table is None:
            print(f"주문 차수 {order_round}에 해당하는 테이블이 없습니다.")
            return

        for menu_num, quantity in items:
            menu_name = self.menu[menu_num]
            row_position = target_table.rowCount()
            target_table.insertRow(row_position)
            target_table.setItem(row_position, 0, QTableWidgetItem(str(table_number)))
            target_table.setItem(row_position, 1, QTableWidgetItem(menu_name))
            target_table.setItem(row_position, 2, QTableWidgetItem(str(quantity)))

    def clear_and_shift_orders(self, index):
        table_widgets = [
            self.tableWidget, self.tableWidget_2, self.tableWidget_3,
            self.tableWidget_4, self.tableWidget_5, self.tableWidget_6
        ]

        table_widgets[index].clearContents()
        table_widgets[index].setRowCount(0)

        for i in range(index, len(table_widgets) - 1):
            self.copy_table_contents(table_widgets[i + 1], table_widgets[i])
            table_widgets[i + 1].clearContents()
            table_widgets[i + 1].setRowCount(0)

    def copy_table_contents(self, source_table, dest_table):
        dest_table.setRowCount(source_table.rowCount())
        dest_table.setColumnCount(source_table.columnCount())
        for row in range(source_table.rowCount()):
            for col in range(source_table.columnCount()):
                item = source_table.item(row, col)
                if item:
                    dest_table.setItem(row, col, QTableWidgetItem(item.text()))

    def update_robot_status(self, status_message):
        self.robotstatus.setText(status_message)

    def show_control_ui(self):
        """Show the Control UI."""
        self.control_ui.show()


class ControlUI(QMainWindow):
    def __init__(self, node, parent=None):
        super(ControlUI,self).__init__(parent)
        uic.loadUi("control.ui", self)
        self.node = node
        self.init_pose = [-2.0, -0.5, 0.0, 1.0]
        self.goal_poses = [[1.6,1.0],[1.6,0.0],[1.6,-1.0],
                        [0.5,1.0],[0.5,0.0],[0.5,-1.0],
                        [-0.6,1.0],[-0.6,0.0],[-0.6,-1.0],
                        [-1.4,1.8],[-2.0,-0.5]]
        self.num = len(self.goal_poses)
        self.setting_poses = [True for i in range(self.num)]

    
        self.pushButton_1.clicked.connect(lambda: self.go_button_clicked(0))
        self.pushButton_2.clicked.connect(lambda: self.go_button_clicked(1))
        self.pushButton_3.clicked.connect(lambda: self.go_button_clicked(2))
        self.pushButton_4.clicked.connect(lambda: self.go_button_clicked(3))
        self.pushButton_5.clicked.connect(lambda: self.go_button_clicked(4))
        self.pushButton_6.clicked.connect(lambda: self.go_button_clicked(5))
        self.pushButton_7.clicked.connect(lambda: self.go_button_clicked(6))
        self.pushButton_8.clicked.connect(lambda: self.go_button_clicked(7))
        self.pushButton_9.clicked.connect(lambda: self.go_button_clicked(8))
        self.pushButton_10.clicked.connect(lambda: self.go_button_clicked(9))
        self.pushButton_11.clicked.connect(lambda: self.go_button_clicked(10))



    def navigate_to_pose_send_goal(self, i):
        wait_count = 1
        while not self.navigate_to_pose_action_client.wait_for_server(timeout_sec=0.1):
            if wait_count > 3:
                message = "[WARN] Navigate action server is not available."
                # self.gui.textBrowser.append(message)
                return False
            wait_count += 1
            
        goal_msg = NavigateToPose.Goal()
        goal_msg.pose.header.frame_id = "map"
        goal_msg.pose.pose.position.x = self.goal_poses[i][0]
        goal_msg.pose.pose.position.y = self.goal_poses[i][1]
        goal_msg.pose.pose.position.z = 0.0
        goal_msg.pose.pose.orientation.x = 0.0
        goal_msg.pose.pose.orientation.y = 0.0
        goal_msg.pose.pose.orientation.z = 0.0
        goal_msg.pose.pose.orientation.w = 1.0

        self.send_goal_future = self.navigate_to_pose_action_client.send_goal_async(
            goal_msg,
            feedback_callback=self.navigate_to_pose_action_feedback)
        self.send_goal_future.add_done_callback(self.navigate_to_pose_action_goal)
        
        return True   
    
    def navigate_to_pose_action_goal(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            message = "[WARN] Action goal rejected."
            # self.gui.textBrowser.append(message)
            return

        message = "[INFO] Action goal accepted."
        # self.gui.textBrowser.append(message)
        self.action_result_future = goal_handle.get_result_async()
        self.action_result_future.add_done_callback(self.navigate_to_pose_action_result)
    
    #example.py 이식
    def navigate_to_pose_action_feedback(self, feedback_msg):
        action_feedback = feedback_msg.feedback
        # self.get_logger().info("Action feedback: {0}".format(action_feedback))
    
    #example.py 이식
    def navigate_to_pose_action_result(self, future):
        action_status = future.result().status
        action_result = future.result().result
        if action_status == GoalStatus.STATUS_SUCCEEDED:

            message = "[INFO] Action succeeded!."
            # self.gui.textBrowser.append(message)

        else:
            message = f"[WARN] Action failed with status: {action_status}"
            # self.gui.textBrowser.append(message)


    def go_button_clicked(self, i):
        self.node.navigate_to_pose_send_goal(i)

def main(args=None):
    rclpy.init(args=args)

    app = QApplication(sys.argv)

    # Create the KitchenUI first
    kitchen_node = KitchenNode()

    # Create the ROS2 Node and link it to the GUI
    kitchen_ui = KitchenUI(kitchen_node)
    control_ui = ControlUI(kitchen_node)
    kitchen_ui.control_ui = control_ui
    kitchen_ui.show()

    # Start ROS2 in a separate thread
    ros_thread = threading.Thread(target=rclpy.spin, args=(kitchen_node,),daemon=True)
    ros_thread.start()

    app.exec_()

    # Shutdown ROS2
    kitchen_node.destroy_node()
    rclpy.shutdown()
    ros_thread.join()


if __name__ == "__main__":
    main()
