import sys
import rclpy
from rclpy.node import Node
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.qos import QoSDurabilityPolicy, QoSHistoryPolicy, QoSProfile, QoSReliabilityPolicy
from PyQt5.QtCore import QTimer
from PyQt5 import QtWidgets, uic
from ros_study_msgs.srv import OrderCustomer
# from ros_study_msgs.msg import OrderInfo

class KitchenNodeWithUI(Node, QtWidgets.QMainWindow):
    def __init__(self):
        Node.__init__(self, 'kitchen_display')
        QtWidgets.QMainWindow.__init__(self)
        uic.loadUi("kitchenlist.ui", self)

        # Order-related attributes
        self.order_list = [[]]
        self.menu_num = 0
        self.quantity_num = 0
        self.table_number = 0
        self.price = 0
        self.menu = ['', '콩나물 국밥', '돼지 국밥', '순대 국밥', '설렁탕']
        
        # ROS2 Callback Group and QoS Profile
        self.callback_group = ReentrantCallbackGroup()
        self.declare_parameter('qos_depth', 10)
        qos_depth = self.get_parameter('qos_depth').value
        QOS_RKL10V = QoSProfile(
            reliability=QoSReliabilityPolicy.RELIABLE,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=qos_depth,
            durability=QoSDurabilityPolicy.VOLATILE)

        # Service to receive orders
        self.order_service_server = self.create_service(
            OrderCustomer,
            'order',
            self.get_order_kitchen,
            callback_group=self.callback_group)
        
        # Connect complete buttons to their respective handlers
        self.pushButton.clicked.connect(lambda: self.clear_and_shift_orders(0))
        self.pushButton_2.clicked.connect(lambda: self.clear_and_shift_orders(1))
        self.pushButton_3.clicked.connect(lambda: self.clear_and_shift_orders(2))
        self.pushButton_4.clicked.connect(lambda: self.clear_and_shift_orders(3))
        self.pushButton_5.clicked.connect(lambda: self.clear_and_shift_orders(4))
        self.pushButton_6.clicked.connect(lambda: self.clear_and_shift_orders(5))

        # Timer to spin the ROS node for callbacks
        self.timer = QTimer()
        self.timer.timeout.connect(self.ros_spin_once)
        self.timer.start(100)  # Spin every 100 ms

    def get_order_kitchen(self, request, response):
        """Service callback to handle incoming orders."""
        self.menu_num = request.menu_num
        self.quantity_num = request.quantity_num
        self.table_number = request.table_number
        self.price = request.price
        self.order_list.append([self.menu_num,self.quantity_num,self.table_number,self.price])
        response.order_check = 1
        # self.order_list += [self.menu_num] * self.quantity_num
        self.get_logger().info('{} {}개 주문~!'.format(self.menu[self.menu_num], self.quantity_num))
        self.get_logger().info('주문 완료 테이블 번호: {}'.format(self.table_number))
        self.get_logger().info('추가로 결제할 금액: {}원'.format(self.price))
        # self.get_logger().info("요리 순서: " + " >> ".join(map(str, self.order_list)))
        

        # Display the order in the UI
        self.display_order(self.table_number, self.menu[self.menu_num], self.quantity_num)
        
        return response

    def display_order(self, table_number, menu_name, quantity):
        """Display the received order in the next available table widget."""
        table_widgets = [
            self.tableWidget, self.tableWidget_2, self.tableWidget_3,
            self.tableWidget_4, self.tableWidget_5, self.tableWidget_6
        ]
        
        # Find the first empty table widget and fill it with the order info
        for table in table_widgets:
            if table.rowCount() == 0:  # Check if table is empty (no other order has used it)
                for i in range(quantity):  # Add rows based on quantity of items ordered
                    row_position = table.rowCount()
                    table.insertRow(row_position)
                    table.setItem(row_position, 0, QtWidgets.QTableWidgetItem(str(table_number)))
                    table.setItem(row_position, 1, QtWidgets.QTableWidgetItem(menu_name))
                    table.setItem(row_position, 2, QtWidgets.QTableWidgetItem("1"))  # Each row represents one item
                break

    def clear_and_shift_orders(self, index):
        """Clears the table at the specified index and shifts all tables to the left."""
        table_widgets = [
            self.tableWidget, self.tableWidget_2, self.tableWidget_3,
            self.tableWidget_4, self.tableWidget_5, self.tableWidget_6
        ]
        
        # Clear the specified table
        table_widgets[index].clearContents()
        
        # Shift orders from right to left
        for i in range(index, len(table_widgets) - 1):
            # Copy contents from the next table to the current table
            self.copy_table_contents(table_widgets[i + 1], table_widgets[i])
            # Clear the next table
            table_widgets[i + 1].clearContents()
    
    def copy_table_contents(self, source_table, dest_table):
        """Copies contents from source table to destination table."""
        for row in range(source_table.rowCount()):
            for col in range(source_table.columnCount()):
                item = source_table.item(row, col)
                if item:
                    dest_table.setItem(row, col, QtWidgets.QTableWidgetItem(item.text()))

    def update_robot_status(self, status_message):
        """Updates the robot status display with the current status."""
        self.robotstatus.setText(status_message)

    def ros_spin_once(self):
        """Spin the ROS node to handle callbacks."""
        rclpy.spin_once(self, timeout_sec=0.01)

def main(args=None):
    rclpy.init(args=args)
    app = QtWidgets.QApplication(sys.argv)
    window = KitchenNodeWithUI()  # Initialize the integrated UI and ROS node
    window.show()
    
    # Run the Qt application
    app.exec_()

    # Clean up ROS node after the application is closed
    window.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
