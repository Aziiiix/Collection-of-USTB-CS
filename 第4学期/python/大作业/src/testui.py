# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'testui.ui'
#
# Created by: PyQt5 UI code generator 5.15.4
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(535, 600)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.Remember = QtWidgets.QTextBrowser(self.centralwidget)
        self.Remember.setGeometry(QtCore.QRect(140, 60, 256, 101))
        self.Remember.setObjectName("Remember")
        self.pushButtonToday = QtWidgets.QPushButton(self.centralwidget)
        self.pushButtonToday.setGeometry(QtCore.QRect(170, 190, 191, 91))
        self.pushButtonToday.setObjectName("pushButtonToday")
        self.pushButtonVersion = QtWidgets.QPushButton(self.centralwidget)
        self.pushButtonVersion.setGeometry(QtCore.QRect(170, 320, 191, 91))
        self.pushButtonVersion.setObjectName("pushButtonVersion")
        self.graphicsView = QtWidgets.QGraphicsView(self.centralwidget)
        self.graphicsView.setGeometry(QtCore.QRect(-10, -10, 551, 571))
        self.graphicsView.setObjectName("graphicsView")
        self.pushButtonExit = QtWidgets.QPushButton(self.centralwidget)
        self.pushButtonExit.setGeometry(QtCore.QRect(170, 450, 191, 91))
        self.pushButtonExit.setObjectName("pushButtonExit")
        self.graphicsView.raise_()
        self.Remember.raise_()
        self.pushButtonToday.raise_()
        self.pushButtonVersion.raise_()
        self.pushButtonExit.raise_()
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 535, 26))
        self.menubar.setObjectName("menubar")
        self.menu = QtWidgets.QMenu(self.menubar)
        self.menu.setObjectName("menu")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)
        self.menubar.addAction(self.menu.menuAction())

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "背单词"))
        self.Remember.setHtml(_translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'SimSun\'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:48pt;\">背单词</span></p></body></html>"))
        self.pushButtonToday.setText(_translate("MainWindow", "开始今日"))
        self.pushButtonVersion.setText(_translate("MainWindow", "版本信息"))
        self.pushButtonExit.setText(_translate("MainWindow", "退出程序"))
        self.menu.setTitle(_translate("MainWindow", "开始"))
