#!python3.10
#coding=utf8

'''

Project:Lucky Clover
Author:Aziiiix
Last updated:2022/03/08
Comment:用于Python程序设计作业1

'''


import time
from turtle import *

def go(x,y):
    penup()
    goto(x,y)
    pendown()
#海龟前往指定地点（途中不划线）

def leaf():
    fillcolor('#23af51')
    begin_fill()
    circle(50,150)
    circle(110,110)#左半边叶子
    left(8)
    circle(110,110)
    circle(50,150)#右半边叶子
    end_fill()
#画出心形叶子

def heart():
    pencolor('#127d36')
    fillcolor('#19c252')
    begin_fill()
    circle(15, 360)
    end_fill()
#画叶心

def state1():
    pensize(3)

    pencolor('#27731c')

    go(100,0)
    leaf()
    #叶子右

    go(-35, 160)
    setheading(100)
    leaf()
    #叶子上

    go(-176,0)
    setheading(180)
    leaf()
    #叶子左

    go(-35,-120)
    setheading(-80)
    leaf()
    #叶子下

    go(-20,20)
    heart()
    #叶心

    go(140,-250)
    pensize(8)
    circle(190,53)
    #叶柄

    go(200, -250)
    write("春意盎然", font=("Verdana", 30, "normal"))
    #打印成语“春意盎然”

def state2():
    #本函数原理同上
    pensize(3)

    pencolor('#27731c')

    go(80,-20)
    setheading(0)
    leaf()

    go(-55, 140)
    setheading(100)
    leaf()

    go(-196,-20)
    setheading(180)
    leaf()

    go(-55,-140)
    setheading(-80)
    leaf()

    go(-40,0)
    heart()

    go(140,-250)
    pensize(8)
    circle(140,70)

    go(200, -250)
    write("春意盎然", font=("Verdana", 30, "normal"))

def main():
    #主函数

    tracer(False)#关闭追踪
    hideturtle()#隐藏海龟
    speed(0)#速度max

    for i in range(1000):

        reset()
        if i%2:#动图判断
            state1()
            update()
            time.sleep(0.15)#延迟时间0.15s
        else:
            state2()
            update()
            time.sleep(0.15)

main()#调用主函数

exitonclick()#鼠标点击退出