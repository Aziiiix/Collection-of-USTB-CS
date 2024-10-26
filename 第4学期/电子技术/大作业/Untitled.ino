#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# ?????????????????????
#  ????13_rain_detector.py
#  ???V2.0
#  author: zhulin
#  ????????????
#####################################################
import LCD1602
import PCF8591 as ADC
import RPi.GPIO as GPIO
import time

makerobo_DO = 17  # ?????????

makerobo_TiltPin = 24  # ?????Pin??

makerobo_Rpin = 21  # ??LEDPin??
makerobo_Gpin = 20  # ??LEDPin??

GPIO.setmode(GPIO.BCM)  # ??BCM???GPIO?
GPIO.setwarnings(False)  # ??GPIO????

QXcheck = 1
check = 1
state1 = 1
state2 = 1


# GPIO???
def makerobo_setup():
    ADC.setup(0x48)  # ??PCF8591????
    GPIO.setup(makerobo_DO, GPIO.IN)  # ??????????????
    GPIO.setup(makerobo_Rpin, GPIO.OUT)  # ????LED???????
    GPIO.setup(makerobo_Gpin, GPIO.OUT)  # ????LED???????

    LCD1602.init(0x27, 1)  # init(slave address, background light)
    LCD1602.write(0, 0, 'Tilt:NORMAL')
    LCD1602.write(1, 1, 'Moist:NORMAL')

    GPIO.setup(makerobo_TiltPin, GPIO.IN, pull_up_down=GPIO.PUD_UP)  # ??makerobo_TiltPin??????????????(3.3V)
    # ??????????????makerobo_detect??
    GPIO.add_event_detect(makerobo_TiltPin, GPIO.BOTH, callback=makerobo_detect, bouncetime=200)


def makerobo_Print(x):
    if x == 0:
        print('***************************************')
        print('***** makerobo Raspberry Kit Tilt!   *')
        print('***************************************')


# ?????????????????
def makerobo_detect(chn):
    QXdouble_colorLED(GPIO.input(makerobo_TiltPin))  # ????LED????
    makerobo_Print(GPIO.input(makerobo_TiltPin))  # ??????????


def QXdouble_colorLED(x):
    global QXcheck
    global check
    if x == 0:  # x?0??????LED?
        GPIO.output(makerobo_Rpin, 1)
        GPIO.output(makerobo_Gpin, 0)
        QXcheck = 0

    if x == 1:  # x?1??????LED?
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
    if x >= 210:  # ????LED?
        if QXcheck == 1:
            GPIO.output(makerobo_Rpin, 0)
            GPIO.output(makerobo_Gpin, 1)
        else:
            GPIO.output(makerobo_Rpin, 1)
            GPIO.output(makerobo_Gpin, 0)
        check = 1

    elif x < 210:  # ????LED?
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


# ????
def makerobo_loop():
    makerobo_status = 1  # ???????
    while True:
        print(ADC.read(0))  # ???AIN0??????
        double_colorLED(ADC.read(0))

        makerobo_tmp = GPIO.input(makerobo_DO)  # ????IO?????????????DO??
        if makerobo_tmp != makerobo_status:  # ??????
            makerobo_status = makerobo_tmp  # ???????

        LEDinsight()

        time.sleep(0.2)  # ??200ms


def destroy():
    GPIO.output(makerobo_Gpin, GPIO.LOW)  # ????LED
    GPIO.output(makerobo_Rpin, GPIO.LOW)  # ????LED
    GPIO.cleanup()  # ????


# ????
if __name__ == '__main__':
    try:
        makerobo_setup()  # GPIO??
        makerobo_loop()  # ??????
    except KeyboardInterrupt:
        destroy()
        pass
