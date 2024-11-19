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
import sys
from ros_study_msgs.srv import OrderCustomer
from ros_study_msgs.msg import MoveRobot#추가
import rclpy
from rclpy.node import Node
from PyQt5.QtCore import QTimer
from PyQt5 import QtWidgets, uic
from rclpy.qos import QoSDurabilityPolicy#추가
from rclpy.qos import QoSHistoryPolicy#추가
from rclpy.qos import QoSProfile#추가
from rclpy.qos import QoSReliabilityPolicy#추가

order_history=[]



class CustomerNode(Node):
    def __init__(self):
        super().__init__('customer_display')
        self.declare_parameter('qos_depth', 10)#추가
        qos_depth = self.get_parameter('qos_depth').value#추가

        self.order_round = 1  # 주문 차수 초기화
        self.table_number = 7
        self.menu = ['', '콩나물 국밥', '돼지 국밥', '순대 국밥', '설렁탕']
        self.price_list = [0, 4000, 5000, 5500, 7000]
        self.sales = 0

        self.robot_command_list = ['move to table 1','move to table 2','move to table 3',
                                      'move to table 4','move to table 5','move to table 6',
                                      'move to table 7','move to table 8','move to table 9',
                                      'move to table', 'move to kitchen']  
        
        self.order_service_client = self.create_client(
            OrderCustomer,
            'order')
        while not self.order_service_client.wait_for_service(timeout_sec=0.1):
            self.get_logger().warning('service not available.')        
        
        QOS_RKL10V = QoSProfile(
            reliability=QoSReliabilityPolicy.RELIABLE,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=qos_depth,
            durability=QoSDurabilityPolicy.TRANSIENT_LOCAL)

        self.moverobot_topic_publisher = self.create_publisher(
            MoveRobot,
            'move_robot',
           QOS_RKL10V)

    def send_request(self, menu_nums, quantities, table_number,):
        service_request = OrderCustomer.Request()
        service_request.menu_num = menu_nums  # 메뉴 번호 리스트
        service_request.quantity_num = quantities  # 수량 리스트
        service_request.table_number = table_number
        service_request.order_round = self.order_round
        future = self.order_service_client.call_async(service_request)
        return future
    
    def publish_move_robot(self):
        msg = MoveRobot()
        # input("퇴식하시겠습니까?")
        msg.topic_move_robot = self.table_number - 1 #table 1의 인덱스는 0이므로, -1 해야함
        self.moverobot_topic_publisher.publish(msg)
        self.get_logger().info('입력된 명령: {}\n'.format(self.robot_command_list[msg.topic_move_robot]))



class MenuBoard(QtWidgets.QMainWindow):
    def __init__(self):
        super(MenuBoard, self).__init__()
        uic.loadUi("/home/kimdahun/order_v10_good_ws/Menuboard.ui", self)

        self.customer=CustomerNode()

        self.timer = QTimer()
        self.timer.timeout.connect(self.spin_ros)
        self.timer.start(100)

        self.order_list_window = OrderList()
        self.orderlist.clicked.connect(self.order_list_window.show)
        
        self.menu = ['', '콩나물 국밥', '돼지 국밥', '순대 국밥', '설렁탕']
        self.price_list = [0, 4000, 5000, 5500, 7000]
        self.select_button=['kongnamul_select','pig_select','soondea_select','cow_select']
        # 각 메뉴의 선택 버튼 연결

        self.kongnamul_select.clicked.connect(lambda: self.add_to_order("콩나물 국밥", 4000, self.kongnamul_cnt.value()))
        self.pig_select.clicked.connect(lambda: self.add_to_order("돼지 국밥", 5000, self.pig_cnt.value()))
        self.soondea_select.clicked.connect(lambda: self.add_to_order("순대 국밥", 5500, self.soondea_cnt.value()))
        self.cow_select.clicked.connect(lambda: self.add_to_order("설렁탕", 7000, self.cow_cnt.value()))

        # 주문하기 버튼 연결
        self.payment.clicked.connect(self.process_payment)
        
        #결제버튼
        self.exit.clicked.connect(self.call_robot)
       
       # 주문 내역 저장용
        self.orders = []
    
    def spin_ros(self):
        rclpy.spin_once(self.customer,timeout_sec=0.01)

    
    def add_to_order(self, menu_name, price, quantity):
        if quantity >= 1:
            row_position = self.order_table.rowCount()
            self.order_table.insertRow(row_position)
            self.order_table.setItem(row_position, 0, QtWidgets.QTableWidgetItem(menu_name))
            self.order_table.setItem(row_position, 1, QtWidgets.QTableWidgetItem(str(quantity)))    
            # 주문 내역 저장용 리스트에 추가
            self.orders.append((menu_name, quantity, price))

    def process_payment(self):
    # 주문 데이터를 리스트로 묶기
        menu_nums = []
        quantities = []
        total_price = 0

        for name, quantity, price in self.orders:
            menu_num = self.customer.menu.index(name)  # 메뉴 번호 가져오기
            menu_nums.append(menu_num)
            quantities.append(quantity)
            total_price += quantity * price  # 총 금액 계산

            self.order_list_window.add_order(name, quantity, price)
        # ROS 서비스 요청
        future = self.customer.send_request(menu_nums, quantities, self.customer.table_number)
        # rclpy.spin_until_future_complete(self.customer, future)
        rclpy.spin_once(self.customer)
        if future.done():        
            try:
                response = future.result()
                order_check = 0
                self.customer.get_logger().info(f"Response received: {response}")
                order_check = response.order_check
                if order_check == 1 :
                    self.customer.get_logger().info('주문이 정상적으로 접수되었습니다.')
                    self.customer.order_round += 1
                else:
                    self.customer.get_logger().error('주문 접수 오류 발생!')
            except Exception as e:
                self.customer.get_logger().error(f'Service call failed: {str(e)}')
            
                # 메뉴 화면 초기화
        self.clear_order_table()
        self.kongnamul_cnt.setValue(0)
        self.pig_cnt.setValue(0)
        self.soondea_cnt.setValue(0)
        self.cow_cnt.setValue(0)
        

    def clear_order_table(self):
        # 테이블 초기화
        self.order_table.setRowCount(0)
        # 주문 내역 리스트 초기화
        self.orders = []

    def call_robot(self):
        self.customer.publish_move_robot()

        rclpy.spin_once(self.customer, timeout_sec=0)
        self.order_list_window.clear_order_history()


    def closeEvent(self, event):
        # Clean up ROS resources when the application is closed
        self.customer.destroy_node()
        rclpy.shutdown()
        super().closeEvent(event)

# 주문 내역 창
class OrderList(QtWidgets.QMainWindow):
    def __init__(self,parent=None):
        super(OrderList,self).__init__(parent)
        uic.loadUi("/home/kimdahun/order_v10_good_ws/orderlist.ui", self)

        self.pushButton.clicked.connect(self.close)

        self.load_order_history()
        self.add_price()
        


    def add_order(self, menu, quantity, price,):
        # 주문 항목을 주문내역 테이블에 추가
        row_position = self.tableWidget.rowCount()
        self.tableWidget.insertRow(row_position)
        self.tableWidget.setItem(row_position, 0, QtWidgets.QTableWidgetItem(menu))
        self.tableWidget.setItem(row_position, 1, QtWidgets.QTableWidgetItem(str(quantity)))
        self.tableWidget.setItem(row_position, 2, QtWidgets.QTableWidgetItem(str(price*quantity)))
            
        order_history.append((menu, quantity, price))
        self.add_price()


    def load_order_history(self):
        # 전역 리스트의 기존 주문 내역을 테이블에 추가
        for menu, quantity, price in order_history:
            row_position = self.tableWidget.rowCount()
            self.tableWidget.insertRow(row_position)
            self.tableWidget.setItem(row_position, 0, QtWidgets.QTableWidgetItem(menu))
            self.tableWidget.setItem(row_position, 1, QtWidgets.QTableWidgetItem(str(quantity)))
            self.tableWidget.setItem(row_position, 2, QtWidgets.QTableWidgetItem(str(price*quantity)))
                                     
    def clear_order_history(self):
        # 주문 내역 및 총 금액 초기화
        self.tableWidget.setRowCount(0)
        order_history.clear()
        self.add_price()
    
    # def add_price(self):
    #     total = sum(int(self.tableWidget.item(row, 2).text()) for row in range(self.tableWidget.rowCount()))
    #     self.textBrowser.setText(f"합계: {total}")
    def add_price(self):
        # 주문 내역(`order_history`)을 기반으로 합계 계산
        total = sum(quantity * price for _, quantity, price in order_history)
        self.textBrowser.setText(f"합계: {total}")


def main(args=None):
    rclpy.init(args=args)
    app = QtWidgets.QApplication(sys.argv)
    window = MenuBoard()
    window.show()
    sys.exit(app.exec_())

if __name__ == '__main__':
    main()
    
