import sys
import rclpy
from rclpy.node import Node
from PyQt5.QtCore import QTimer
from PyQt5 import QtWidgets, uic
import sqlite3


class KitchenBoard(QtWidgets.QMainWindow):
    def __init__(self):
        super(KitchenBoard,self).__init__()
        uic.loadUi("/home/rokey/2W/order_ws/kitchenlist.ui",self)

        #DB버튼
        
        self.pushButton.clicked.connect(self.open_order_db)

        self.complete_buttons = [
            self.findChild(QtWidgets.QPushButton, f'pushButton_{i}')
            for i in range(2, 8)
        ]
        for button in self.complete_buttons:
            button.clicked.connect(self.complete_order)
    def open_order_db(self):
        print("DB를 열었습니다  ")



 
    def complete_order(self):
        self.order_table.setRowCount(0)
    




def main():
    app = QtWidgets.QApplication(sys.argv)
    window = KitchenBoard()
    window.show()
    sys.exit(app.exec_())


if __name__=="__main__":
    main()
        

