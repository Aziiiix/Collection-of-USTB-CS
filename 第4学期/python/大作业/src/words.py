from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
import sys

from testui import Ui_MainWindow
from testui2 import Ui_Version
from testui3 import Ui_Remember
from testui4 import Ui_Wrong


class MainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.scene = QGraphicsScene(0, 0, 400, 400)


        self.pushButtonToday.clicked.connect(self.BtnToday)
        self.pushButtonVersion.clicked.connect(self.BtnVersion)
        self.pushButtonExit.clicked.connect(self.BtnExit)

    def BtnToday(self, evt):
        Remember.show()
        Main.close()

    def BtnVersion(self, evt):
        Version.show()
        Main.close()

    def BtnExit(self, evt):
        Main.close()


class VersionWindow(QMainWindow, Ui_Version):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.scene = QGraphicsScene(0, 0, 1000, 1000)

        self.pushButtonBack.clicked.connect(self.BtnBack)

    def BtnBack(self, evt):
        Main.show()
        Version.close()


class RememberWindow(QMainWindow, Ui_Remember):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.scene = QGraphicsScene(0, 0, 1000, 1000)

        self.pushButtonBack.clicked.connect(self.BtnBack)
        self.pushButtonCheck.clicked.connect(self.BtnCheck)
        self.pushButtonNext.clicked.connect(self.BtnNext)
        self.ChineseWord.setText(f"<font color='purple' size=10>{data[counter][1]}")

    def BtnBack(self, evt):
        Main.show()
        Remember.close()

    def BtnCheck(self, evt):
        global counter
        if counter < length:
            ans = self.InputAns.text()
            if ans == data[counter][0]:
                self.LabelDisplay.setText("<font color='red' size=5>YES 恭喜你答对了!")
            else:
                self.LabelDisplay.setText(f"<font color='red' size=5>X 正确答案{data[counter][0]}")
                group.append(counter)
            counter += 1
        else:
            Wrong.show()
            Remember.close()

    def BtnNext(self, evt):
        global counter
        if counter < length:
            self.ChineseWord.setText(f"<font color='purple' size=10>{data[counter][1]}")
            self.LabelDisplay.setText(" ")
            self.InputAns.clear()
        else:
            self.ChineseWord.setText(f"<font color='purple' size=5>今日学习结束，点击确认查看错题")
            self.LabelDisplay.setText(" ")
            self.InputAns.clear()


class WrongWindow(QMainWindow, Ui_Wrong):
    global group
    global counter

    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.scene = QGraphicsScene(0, 0, 1000, 1000)

        self.pushButtonExit.clicked.connect(self.BtnExit)
        self.pushButtonUpdate.clicked.connect(self.BtnUpdate)

    def BtnExit(self, evt):
        Wrong.close()

    def BtnUpdate(self,evt):
        flength = len(group)
        for i in range(flength):
            self.Wrong.insertPlainText(data[group[i]][0])
            self.Wrong.insertPlainText('  ')
            self.Wrong.insertPlainText(data[group[i]][1])
            self.Wrong.insertPlainText('\n')


if __name__ == '__main__':
    file = open("words.txt", "r", encoding='utf-8')
    data = []
    for line in file:
        line = line.strip('\n')
        line = line.split()
        data.append(line)
    length = len(data)
    counter = 0
    group = []

    app = QApplication(sys.argv)
    Main = MainWindow()
    Version = VersionWindow()
    Remember = RememberWindow()
    Wrong = WrongWindow()
    Main.show()
    sys.exit(app.exec_())
