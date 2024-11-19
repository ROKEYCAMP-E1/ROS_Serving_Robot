import sys
from rclpy.node import Node
from PyQt5.QtCore import QTimer
from PyQt5 import QtWidgets, uic

class KitchenWindow(QtWidgets.QMainWindow):
    def __init__(self):
        super(KitchenWindow, self).__init__()
        uic.loadUi("kitchenlist.ui", self)

        
        # Connect complete buttons to their respective handlers
        self.pushButton.clicked.connect(lambda: self.clear_and_shift_orders(0))
        self.pushButton_2.clicked.connect(lambda: self.clear_and_shift_orders(1))
        self.pushButton_3.clicked.connect(lambda: self.clear_and_shift_orders(2))
        self.pushButton_4.clicked.connect(lambda: self.clear_and_shift_orders(3))
        self.pushButton_5.clicked.connect(lambda: self.clear_and_shift_orders(4))
        self.pushButton_6.clicked.connect(lambda: self.clear_and_shift_orders(5))

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

if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = KitchenWindow()
    window.show()
    sys.exit(app.exec_())
