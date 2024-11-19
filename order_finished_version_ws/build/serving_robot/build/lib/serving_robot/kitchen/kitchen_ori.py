# Copyright 2021 OROCA
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# from ros_study_msgs.action import ArithmeticChecker
# from ros_study_msgs.msg import ArithmeticArgument
from ros_study_msgs.srv import OrderCustomer
from ros_study_msgs.msg import MoveRobot
# from rclpy.action import ActionServer
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.node import Node
from rclpy.qos import QoSDurabilityPolicy
from rclpy.qos import QoSHistoryPolicy
from rclpy.qos import QoSProfile
from rclpy.qos import QoSReliabilityPolicy

import sys
import threading
import subprocess, os

from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import *

import rclpy
from rclpy.action import ActionClient
from geometry_msgs.msg import PointStamped
from geometry_msgs.msg import Point, Quaternion
from nav2_msgs.action import NavigateToPose
from nav2_msgs.srv import SetInitialPose
from rclpy.action.client import GoalStatus


import sqlite3
import sqlite3,uuid
from datetime import datetime


class KitchenNode(Node):

    def __init__(self, runner):
        super().__init__('kitchen_display')
        self.runner = runner
        self.num = self.runner.num
        # self.order_list = []
        # self.request_list = []

        self.menu_nums = []
        self.quantity_num = []
        self.table_number = 0
        self.order_round = 0


        self.menu = ['', '콩나물 국밥', '돼지 국밥', '순대 국밥', '설렁탕']
        self.robot_command_list = ['move to table 1','move to table 2','move to table 3',
                                       'move to table 4','move to table 5','move to table 6',
                                       'move to table 7','move to table 8','move to table 9',
                                       'move to table', 'move to kitchen']  
        self.price= [0,4000, 5000, 5500, 7000]
        self.callback_group = ReentrantCallbackGroup()

        self.declare_parameter('qos_depth', 10)
        qos_depth = self.get_parameter('qos_depth').value

        QOS_RKL10V = QoSProfile(
            reliability=QoSReliabilityPolicy.RELIABLE,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=qos_depth,
            durability=QoSDurabilityPolicy.TRANSIENT_LOCAL)

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

    def get_order_kitchen(self, request, response):
        #requset_list 내용: [self.menu_num, self.quantity_num, self.table_number, self.price, self.sales]
        #self.request_list[0] = self.menu_num
        # self.request_list = request.request_list
        
        self.menu_nums = request.menu_num # 메뉴 번호 리스트
        self.quantity_num = request.quantity_num  # 수량 리스트
        self.table_number = request.table_number
        self.order_round = request.order_round
        self.insert_DB(self.menu_nums, self.quantity_num)



        response.order_check = 1
        self.get_logger().info(f"Order check value: {response.order_check}")
        # self.order_list += [self.menu_nums]*
        self.get_logger().info('메뉴 번호 리스트: {}'.format(self.menu_nums))
        self.get_logger().info('메뉴 수량 리스트: {}'.format(self.quantity_num))
        self.get_logger().info('테이블 넘버: {}'.format(self.table_number))
        # self.get_logger().info("요리 순서: " + " >> ".join(map(str,self.order_list)))
        self.get_logger().info('주문번호: {}'.format(self.order_round))
        
        print()
        return response
    
    def get_move_robot(self, msg):
        self.topic_move_robot = msg.topic_move_robot#1 혹은 2의 값
        if self.topic_move_robot == 10:#move to origin
            self.navigate_to_pose_send_goal(10)
        elif self.topic_move_robot == 9:#move to kitchen
            self.navigate_to_pose_send_goal(9)
        elif 0 <= self.topic_move_robot <= 8:
            self.navigate_to_pose_send_goal(self.topic_move_robot)
        else:
            self.get_logger().error('올바른 입력을 받지 못했습니다.')
        self.get_logger().info('받은 로봇 명령: {}'.format(self.robot_command_list[self.topic_move_robot]))    

    #example.py 이식
    def input_gui(self):
        self.gui = self.runner.gui
        
        # # create Topic Subscriber
        # self.clicked_point_subscriber = self.create_subscription(
        #     PointStamped,
        #     "clicked_point",
        #     self.clicked_point_callback,
        #     10
        #     )
        
        # create Service Clinet
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
        self.set_initial_pose(*self.runner.init_pose)

    #example.py 이식
    # Service client SET INIT POSE ESTIMATE
    def set_initial_pose(self, x,y,z,w):
        req = SetInitialPose.Request()
        req.pose.header.frame_id = 'map'
        req.pose.pose.pose.position = Point(x=x, y=y, z=0.0)
        req.pose.pose.pose.orientation = Quaternion(x=0.0, y=0.0, z=z, w=w)
        req.pose.pose.covariance = [0.1, 0.0, 0.0, 0.0, 0.0, 0.1,
                              0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                              0.0, 0.0, 0.1, 0.0, 0.0, 0.0,
                              0.0, 0.0, 0.0, 0.01, 0.0, 0.0,
                              0.0, 0.0, 0.0, 0.0, 0.01, 0.0,
                              0.0, 0.0, 0.0, 0.0, 0.0, 0.01]

        future = self.set_initial_pose_service_client.call_async(req)
        
        if future.result() is not None:
            message = "[INFO] Initial pose set successfully"
        else:
            message = "[WARN] Failed to set initial pose"
            
        self.gui.textBrowser.setText(message)
        
        return future.result()

    #example.py 이식
    ## Action client NAVIGATE      
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
        goal_msg.pose.pose.position.x = self.runner.goal_poses[i][0]
        goal_msg.pose.pose.position.y = self.runner.goal_poses[i][1]
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
    
    #example.py 이식
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





# import rclpy
# from rclpy.executors import MultiThreadedExecutor

# def main(args=None):
#     rclpy.init(args=args)
#     try:
#         kitchen = KitchenNode()
#         executor = MultiThreadedExecutor(num_threads=4)
#         executor.add_node(kitchen)
#         try:
#             executor.spin()
#         except KeyboardInterrupt:
#             kitchen.get_logger().info('Keyboard Interrupt (SIGINT)')
#         finally:
#             executor.shutdown()
#             kitchen.destroy_node()
#     finally:
#         rclpy.shutdown()


# if __name__ == '__main__':
#     main()

###############################example.py이식####################

    
class GUI():
    def __init__(self, runner):
        self.runner = runner
        self.node = self.runner.node
        self.create_gui()
        
    def create_gui(self):
        self.num = self.runner.num
        
        self.app = QApplication(sys.argv)
        self.window = QMainWindow()
        
        self.window.setWindowTitle(QCoreApplication.translate("MainWindow", u"MainWindow", None))
        self.window.resize(420, 470+150)
        self.centralwidget = QWidget(self.window)
        self.centralwidget.setObjectName(u"centralwidget")
        
        # self.getButtons = [None for i in range(self.num)]
        # self.getButtons_geo = [19, 20, 51, 23]
        # for i in range(self.num):
        #     self.getButtons[i] = QPushButton(self.centralwidget)
        #     self.getButtons[i].setObjectName(f"getButton_{i}")
        #     self.getButtons[i].setGeometry(QRect(*self.getButtons_geo))
        #     self.getButtons[i].setText(QCoreApplication.translate("MainWindow", f"get{i}", None))
        #     self.getButtons[i].clicked.connect(lambda checked, i=i: self.get_button_clicked(i))
        #     self.getButtons_geo[1] +=40
            
        # self.labels = [None for i in range(self.num)]
        # self.labels_geo = [90, 20, 131, 23]
        # for i in range(self.num):
        #     self.labels[i] = QLabel(self.centralwidget)
        #     self.labels[i].setObjectName(f"label_{i}")
        #     self.labels[i].setGeometry(QRect(*self.labels_geo))
        #     self.labels[i].setText(QCoreApplication.translate("MainWindow", "x= 0.0, y= 0.0", None))
        #     self.labels_geo[1] +=40
        
        self.goButtons_geo = [50, 50, 100, 50] 
        self.goButtons = [None for i in range(12)]

        # 버튼 위치와 크기 설정
         # X, Y, 너비, 높이

        # 버튼 0
        self.goButtons[0] = QPushButton(self.centralwidget)
        self.goButtons[0].setObjectName("goButton_0")
        self.goButtons[0].setGeometry(QRect(self.goButtons_geo[0], self.goButtons_geo[1], self.goButtons_geo[2], self.goButtons_geo[3]))
        self.goButtons[0].setText(QCoreApplication.translate("MainWindow", "table 1", None))
        self.goButtons[0].clicked.connect(lambda checked, i=0: self.go_button_clicked(i))

        # 버튼 1
        self.goButtons[1] = QPushButton(self.centralwidget)
        self.goButtons[1].setObjectName("goButton_1")
        self.goButtons[1].setGeometry(QRect(self.goButtons_geo[0] + self.goButtons_geo[2] + 10, self.goButtons_geo[1], self.goButtons_geo[2], self.goButtons_geo[3]))
        self.goButtons[1].setText(QCoreApplication.translate("MainWindow", "table 2", None))
        self.goButtons[1].clicked.connect(lambda checked, i=1: self.go_button_clicked(i))

        # 버튼 2
        self.goButtons[2] = QPushButton(self.centralwidget)
        self.goButtons[2].setObjectName("goButton_2")
        self.goButtons[2].setGeometry(QRect(self.goButtons_geo[0] + (self.goButtons_geo[2] + 10) * 2, self.goButtons_geo[1], self.goButtons_geo[2], self.goButtons_geo[3]))
        self.goButtons[2].setText(QCoreApplication.translate("MainWindow", "table 3", None))
        self.goButtons[2].clicked.connect(lambda checked, i=2: self.go_button_clicked(i))

        # 버튼 3
        self.goButtons[3] = QPushButton(self.centralwidget)
        self.goButtons[3].setObjectName("goButton_3")
        self.goButtons[3].setGeometry(QRect(self.goButtons_geo[0], self.goButtons_geo[1] + self.goButtons_geo[3] + 10, self.goButtons_geo[2], self.goButtons_geo[3]))
        self.goButtons[3].setText(QCoreApplication.translate("MainWindow", "table 4", None))
        self.goButtons[3].clicked.connect(lambda checked, i=3: self.go_button_clicked(i))

        # 버튼 4
        self.goButtons[4] = QPushButton(self.centralwidget)
        self.goButtons[4].setObjectName("goButton_4")
        self.goButtons[4].setGeometry(QRect(self.goButtons_geo[0] + self.goButtons_geo[2] + 10, self.goButtons_geo[1] + self.goButtons_geo[3] + 10, self.goButtons_geo[2], self.goButtons_geo[3]))
        self.goButtons[4].setText(QCoreApplication.translate("MainWindow", "table 5", None))
        self.goButtons[4].clicked.connect(lambda checked, i=4: self.go_button_clicked(i))

        # 버튼 5
        self.goButtons[5] = QPushButton(self.centralwidget)
        self.goButtons[5].setObjectName("goButton_5")
        self.goButtons[5].setGeometry(QRect(self.goButtons_geo[0] + (self.goButtons_geo[2] + 10) * 2, self.goButtons_geo[1] + self.goButtons_geo[3] + 10, self.goButtons_geo[2], self.goButtons_geo[3]))
        self.goButtons[5].setText(QCoreApplication.translate("MainWindow", "table 6", None))
        self.goButtons[5].clicked.connect(lambda checked, i=5: self.go_button_clicked(i))

        # 버튼 6
        self.goButtons[6] = QPushButton(self.centralwidget)
        self.goButtons[6].setObjectName("goButton_6")
        self.goButtons[6].setGeometry(QRect(self.goButtons_geo[0], self.goButtons_geo[1] + (self.goButtons_geo[3] + 10) * 2, self.goButtons_geo[2], self.goButtons_geo[3]))
        self.goButtons[6].setText(QCoreApplication.translate("MainWindow", "table 7", None))
        self.goButtons[6].clicked.connect(lambda checked, i=6: self.go_button_clicked(i))

        # 버튼 7
        self.goButtons[7] = QPushButton(self.centralwidget)
        self.goButtons[7].setObjectName("goButton_7")
        self.goButtons[7].setGeometry(QRect(self.goButtons_geo[0] + self.goButtons_geo[2] + 10, self.goButtons_geo[1] + (self.goButtons_geo[3] + 10) * 2, self.goButtons_geo[2], self.goButtons_geo[3]))
        self.goButtons[7].setText(QCoreApplication.translate("MainWindow", "table 8", None))
        self.goButtons[7].clicked.connect(lambda checked, i=7: self.go_button_clicked(i))

        # 버튼 8
        self.goButtons[8] = QPushButton(self.centralwidget)
        self.goButtons[8].setObjectName("goButton_8")
        self.goButtons[8].setGeometry(QRect(self.goButtons_geo[0] + (self.goButtons_geo[2] + 10) * 2, self.goButtons_geo[1] + (self.goButtons_geo[3] + 10) * 2, self.goButtons_geo[2], self.goButtons_geo[3]))
        self.goButtons[8].setText(QCoreApplication.translate("MainWindow", "table 9", None))
        self.goButtons[8].clicked.connect(lambda checked, i=8: self.go_button_clicked(i))

        # 버튼 9
        self.goButtons[9] = QPushButton(self.centralwidget)
        self.goButtons[9].setObjectName("goButton_9")
        self.goButtons[9].setGeometry(QRect(self.goButtons_geo[0], self.goButtons_geo[1] + (self.goButtons_geo[3] + 10) * 3, 155, self.goButtons_geo[3]))
        self.goButtons[9].setText(QCoreApplication.translate("MainWindow", "kitchen(주방 호출)", None))
        self.goButtons[9].clicked.connect(lambda checked, i=9: self.go_button_clicked(i))

        # 버튼 10
        self.goButtons[10] = QPushButton(self.centralwidget)
        self.goButtons[10].setObjectName("goButton_10")
        self.goButtons[10].setGeometry(QRect(self.goButtons_geo[0] + self.goButtons_geo[2] + 65, self.goButtons_geo[1] + (self.goButtons_geo[3] + 10) * 3, 155, self.goButtons_geo[3]))
        self.goButtons[10].setText(QCoreApplication.translate("MainWindow", "origin(원점 호출)", None))
        self.goButtons[10].clicked.connect(lambda checked, i=10: self.go_button_clicked(i))

        #데이터 베이스 조회 버튼
        self.goButtons[11] = QPushButton(self.centralwidget)
        self.goButtons[11].setObjectName("goButton_12")
        self.goButtons[11].setGeometry(QRect(self.goButtons_geo[0], self.goButtons_geo[1] + (self.goButtons_geo[3] + 10) * 3 + 60 + 150, 320, self.goButtons_geo[3]))
        self.goButtons[11].setText(QCoreApplication.translate("MainWindow", "데이터베이스 조회", None))
        self.goButtons[11].clicked.connect(lambda checked: self.open_database())


        self.textBrowser = QTextBrowser(self.centralwidget)
        self.textBrowser.setObjectName(u"textBrowser")
        self.textBrowser.setGeometry(QRect(self.goButtons_geo[0], self.goButtons_geo[1] + self.goButtons_geo[3] + 190, 320, 140))

        self.window.setCentralWidget(self.centralwidget)
    #example.py 이식
    # def get_button_clicked(self, i):
    #     self.runner.setting_poses[i] = True

    #example.py 이식
    def go_button_clicked(self, i):
        self.node.navigate_to_pose_send_goal(i)

    def open_database(self):
        db_path = "/home/rokey/2W/order_v9_good_ws/order_v8_good_ws/order.db"
        if os.path.exists(db_path):
            try:
                subprocess.run(["sqlitebrowser", db_path], check=True)
            except FileNotFoundError:
                print("sqlitebrowser 프로그램이 설치되어 있지 않습니다.")
            except Exception as e:
                print(f"데이터베이스를 여는 중 오류가 발생했습니다: {e}")
        else:
            print(f"{db_path} 데이터베이스 파일을 찾을 수 없습니다.")


class RUNNER():
    def __init__(self):
        # setting
        self.num = 11
        self.init_pose = [-2.0, -0.5, 0.0, 1.0] # pose:x,y orient:z,w

        # init
        self.goal_poses = [[1.6,1.0],[1.6,0.0],[1.6,-1.0],
                           [0.5,1.0],[0.5,0.0],[0.5,-1.0],
                           [-0.6,1.0],[-0.6,0.0],[-0.6,-1.0],
                           [-1.4,1.8],[-2.0,-0.5]
                           ]
        self.setting_poses = [True for i in range(self.num)]
    
        self.node = KitchenNode(self)
        self.gui = GUI(self)
        self.node.input_gui()
        
    def run(self):
        self.ros_thread = threading.Thread(target=self.run_node, daemon=True)
        self.ros_thread.start()

        self.gui.window.show()
        sys.exit(self.gui.app.exec_())
        
    def run_node(self):
        try:
            rclpy.spin(self.node)
        finally:
            self.node.destroy_node()

def main():
    rclpy.init()
    runner = RUNNER()
    
    try:
        runner.run()
    finally:
        rclpy.shutdown()
    
    
if __name__ == '__main__':
    main()