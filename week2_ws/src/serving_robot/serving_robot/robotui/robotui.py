# turtlebot3_GUI/publisher_node.py
import rclpy
from rclpy.node import Node
from ros_study_msgs.msg import MoveRobot
from rclpy.qos import QoSDurabilityPolicy
from rclpy.qos import QoSHistoryPolicy
from rclpy.qos import QoSProfile
from rclpy.qos import QoSReliabilityPolicy

import sys

from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import *

class RobotuiNode(Node):
    def __init__(self,  runner):
        self.runner = runner
        super().__init__('robot_display')
        self.robot_command_list = ['move to table 1','move to table 2','move to table 3',
                                      'move to table 4','move to table 5','move to table 6',
                                      'move to table 7','move to table 8','move to table 9',
                                      'move to table', 'move to kitchen']  
        self.declare_parameter('qos_depth', 10)
        qos_depth = self.get_parameter('qos_depth').value

        QOS_RKL10V = QoSProfile(
            reliability=QoSReliabilityPolicy.RELIABLE,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=qos_depth,
            durability=QoSDurabilityPolicy.TRANSIENT_LOCAL)

        self.moverobot_topic_publisher = self.create_publisher(
            MoveRobot,
            'move_robot',
            QOS_RKL10V)

    def publish_move_robot(self, i):
        msg = MoveRobot()
        msg.topic_move_robot = i
        self.moverobot_topic_publisher.publish(msg)
        self.get_logger().info('입력된 명령: {}\n'.format(self.robot_command_list[msg.topic_move_robot]))
        

    def input_topic_num(self):
                while 1:
                    try:
                        input_topic_num = int(input("로봇 움직이기(10: 배식(to origin), 9: 퇴식(to kitchen)): "))
                        if 9<=input_topic_num<=10:
                            return input_topic_num
                        else:
                            self.get_logger().error('존재하지 않는 명령입니다. 다시 입력해주세요.')
                    except ValueError:
                        print("유효하지 않은 입력입니다. 숫자를 입력하세요.")


class GUI():
    def __init__(self, runner):
        self.runner = runner
        self.node = self.runner.node
        self.create_gui()
        
    def create_gui(self):
        self.num = 2
        
        self.app = QApplication(sys.argv)
        self.window = QMainWindow()
        
        self.window.setWindowTitle(QCoreApplication.translate("MainWindow", u"MainWindow", None))
        self.window.resize(420, 470)
        self.centralwidget = QWidget(self.window)
        self.centralwidget.setObjectName(u"centralwidget")

        self.goButtons_geo = [50, 50, 100, 50] 
        self.goButtons = [None for i in range(self.num)]

        # 버튼 위치와 크기 설정
         # X, Y, 너비, 높이

        # 버튼 0
        self.goButtons[0] = QPushButton(self.centralwidget)
        self.goButtons[0].setObjectName("goButton_0")
        self.goButtons[0].setGeometry(QRect(self.goButtons_geo[0], self.goButtons_geo[1] + (self.goButtons_geo[3] + 10) * 3 -200 , 155, self.goButtons_geo[3]))
        self.goButtons[0].setText(QCoreApplication.translate("MainWindow", "배식", None))
        self.goButtons[0].clicked.connect(lambda checked, i=10: self.go_button_clicked(i))
        self.goButtons[0].setStyleSheet("background-color: green; color: black;")

        # 버튼 1
        self.goButtons[1] = QPushButton(self.centralwidget)
        self.goButtons[1].setObjectName("goButton_1")
        self.goButtons[1].setGeometry(QRect(self.goButtons_geo[0] + self.goButtons_geo[2] + 65, self.goButtons_geo[1] + (self.goButtons_geo[3] + 10) * 3 -200, 155, self.goButtons_geo[3]))
        self.goButtons[1].setText(QCoreApplication.translate("MainWindow", "퇴식", None))
        self.goButtons[1].clicked.connect(lambda checked, i=9: self.go_button_clicked(i))
        self.goButtons[1].setStyleSheet("background-color: yellow; color: black;")

        self.textBrowser = QTextBrowser(self.centralwidget)
        self.textBrowser.setObjectName(u"textBrowser")
        self.textBrowser.setGeometry(QRect(self.goButtons_geo[0], self.goButtons_geo[1] + self.goButtons_geo[3] + 190 -200, 320, 320))

        self.window.setCentralWidget(self.centralwidget)

    def go_button_clicked(self, i):
        try:
            if i==10:
                message = "[INFO] 배식이 완료되었습니다."
                self.textBrowser.append("[WARN] 음식이 뜨거우니 주의하세요.")
            else:
                message = "[INFO] 퇴식을 시작합니다."
        except:
            message = "[ERROR] 배식/퇴식 버튼 클릭 오류"
        self.textBrowser.append(message)
        self.node.publish_move_robot(i)

class RUNNER():
    def __init__(self):

        # init
        self.node = RobotuiNode(self)
        self.gui = GUI(self)
        
    def run(self):
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
    



# def main(args=None):
#     rclpy.init(args=args)
#     robotui = RobotuiNode()

#     try:
#         while rclpy.ok():
#             robotui.publish_move_robot()
#             rclpy.spin_once(robotui, timeout_sec=0)  # 한번의 spin 호출로 ROS2 이벤트 처리

#     except KeyboardInterrupt:
#         robotui.get_logger().info('Keyboard Interrupt (SIGINT)')

#     finally:
#         robotui.destroy_node()
#         rclpy.shutdown()


if __name__ == '__main__':
    main()