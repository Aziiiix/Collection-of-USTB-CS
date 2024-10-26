#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# －－－－湖南创乐博智能科技有限公司－－－－
#  文件名：13_rain_detector.py
#  版本：V2.0
#  author: zhulin
#  说明：雨滴探测传感器实验
#####################################################
import LCD1602
import PCF8591 as ADC
import RPi.GPIO as GPIO
import time

import run

# 三元素（iot后台获取）
ProductKey = 'a1Wb3NoSU9z'
DeviceName = 'raspberrypi4-00001'
DeviceSecret = "COBaCsHdd1yfA1mHkkwOAM7krXUwmezU"
# topic (iot后台获取)
POST = '/sys/a1Wb3NoSU9z/raspberrypi4-00001/thing/event/property/post'  # 上报消息到云
POST_REPLY = '/sys/a1Wb3NoSU9z/raspberrypi4-00001/thing/event/property/post_reply'
SET = '/sys/a1Wb3NoSU9z/raspberrypi4-00001/thing/service/property/set'  # 订阅云端指令

# 链接信息
Server, ClientId, userNmae, Password = aliLink.linkiot(DeviceName, ProductKey, DeviceSecret)

# mqtt链接
mqtt = mqttd.MQTT(Server, ClientId, userNmae, Password)
mqtt.subscribe(SET)  # 订阅服务器下发消息topic
mqtt.begin(on_message, on_connect)
# 信息获取上报，每10秒钟上报一次系统参数


makerobo_DO = 17  # 雨滴传感器数字管脚

makerobo_TiltPin = 24  # 倾斜传感器Pin端口

makerobo_Rpin = 21  # 红色LEDPin端口
makerobo_Gpin = 20  # 绿色LEDPin端口

GPIO.setmode(GPIO.BCM)  # 采用BCM管脚给GPIO口
GPIO.setwarnings(False)  # 关闭GPIO警告提示

QXcheck = 1
check = 1
state1 = 1
state2 = 1


# GPIO口定义
def makerobo_setup():
    ADC.setup(0x48)  # 设置PCF8591模块地址
    GPIO.setup(makerobo_DO, GPIO.IN)  # 设置雨滴传感器管脚为输入模式
    GPIO.setup(makerobo_Rpin, GPIO.OUT)  # 设置红色LED管脚为输出模式
    GPIO.setup(makerobo_Gpin, GPIO.OUT)  # 设置绿色LED管脚为输出模式

    LCD1602.init(0x27, 1)  # init(slave address, background light)
    LCD1602.write(0, 0, 'Tilt:NORMAL')
    LCD1602.write(1, 1, 'Moist:NORMAL')

    GPIO.setup(makerobo_TiltPin, GPIO.IN, pull_up_down=GPIO.PUD_UP)  # 设置makerobo_TiltPin管脚为输入模式，上拉至高电平(3.3V)
    # 中断函数，当发生倾斜时，调用makerobo_detect函数
    GPIO.add_event_detect(makerobo_TiltPin, GPIO.BOTH, callback=makerobo_detect, bouncetime=200)


def makerobo_Print(x):
    if x == 0:
        print('***************************************')
        print('***** makerobo Raspberry Kit Tilt!   *')
        print('***************************************')


# 中断函数，发生倾斜时，响应中断函数
def makerobo_detect(chn):
    QXdouble_colorLED(GPIO.input(makerobo_TiltPin))  # 调用双色LED驱动函数
    makerobo_Print(GPIO.input(makerobo_TiltPin))  # 打印出倾斜传感器信息


def QXdouble_colorLED(x):
    global QXcheck
    global check
    if x == 0:  # x为0时，开启红色LED灯
        GPIO.output(makerobo_Rpin, 1)
        GPIO.output(makerobo_Gpin, 0)
        QXcheck = 0

    if x == 1:  # x为1时，开启绿色LED灯
        if check == 0:
            GPIO.output(makerobo_Rpin, 1)
            GPIO.output(makerobo_Gpin, 0)
        else:
            GPIO.output(makerobo_Rpin, 0)
            GPIO.output(makerobo_Gpin, 1)

        QXcheck = 1


def double_colorLED(x):
    global QXcheck
    global check
    if x >= 210:  # 开启绿色LED灯
        if QXcheck == 1:
            GPIO.output(makerobo_Rpin, 0)
            GPIO.output(makerobo_Gpin, 1)
        else:
            GPIO.output(makerobo_Rpin, 1)
            GPIO.output(makerobo_Gpin, 0)
        check = 1

    elif x < 210:  # 开启红色LED灯
        GPIO.output(makerobo_Rpin, 1)
        GPIO.output(makerobo_Gpin, 0)
        check = 0


def LEDinsight():
    global QXcheck
    global check
    global state1
    global state2

    if state1 != QXcheck:
        if QXcheck == 1:
            LCD1602.write(0, 0, 'Tilt:NORMAL   ')
        else:
            LCD1602.write(0, 0, 'Tilt:ATTENTION')
        state1 = QXcheck

    if state2 != check:
        if check == 1:
            LCD1602.write(1, 1, 'Moist:NORMAL   ')
        else:
            LCD1602.write(1, 1, 'Moist:ATTENTION')
        state2 = check


# 循环函数
def makerobo_loop():
    makerobo_status = 1  # 雨滴传感器状态
    while True:
        print(ADC.read(0))  # 打印出AIN0的模拟量数值
        double_colorLED(ADC.read(0))

        makerobo_tmp = GPIO.input(makerobo_DO)  # 读取数字IO口电平，读取数字雨滴传感器DO端口
        if makerobo_tmp != makerobo_status:  # 状态发生改变
            makerobo_status = makerobo_tmp  # 状态值重新赋值

        LEDinsight()

        time.sleep(0.2)  # 延时200ms
        
        run.fun()


def destroy():
    GPIO.output(makerobo_Gpin, GPIO.LOW)  # 关闭绿色LED
    GPIO.output(makerobo_Rpin, GPIO.LOW)  # 关闭红色LED
    GPIO.cleanup()  # 释放资源


# 程序入口
if __name__ == '__main__':
    try:
        makerobo_setup()  # GPIO定义
        makerobo_loop()  # 调用循环函数
    except KeyboardInterrupt:
        destroy()
        pass
