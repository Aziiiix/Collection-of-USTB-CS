#!/usr/bin/python3

import aliLink,mqttd,rpi
import time,json

ProductKey = 'h5puit3jEk9'
DeviceName = 'raspberry_device'
DeviceSecret = "7948bccac4d61875155c8564f6a2e1cd"
# topic (iot后台获取)
POST = '/sys/h5puit3jEk9/raspberry_device/thing/event/property/post'  # 上报消息到云
POST_REPLY = '/sys/h5puit3jEk9/raspberry_device/thing/event/property/post_reply'
SET = '	/sys/h5puit3jEk9/raspberry_device/thing/service/property/set'  # 订阅云端指令

# 消息回调（云端下发消息的回调函数）
def on_message(client, userdata, msg):
    #print(msg.payload)
    Msg = json.loads(msg.payload)
    switch = Msg['params']['PowerLed']
    rpi.powerLed(switch)
    print(msg.payload)  # 开关值

#连接回调（与阿里云建立链接后的回调函数）
def on_connect(client, userdata, flags, rc):
    pass


# 链接信息
Server,ClientId,userNmae,Password = aliLink.linkiot(DeviceName,ProductKey,DeviceSecret)

# mqtt链接
mqtt = mqttd.MQTT(Server,ClientId,userNmae,Password)
mqtt.subscribe(SET) # 订阅服务器下发消息topic
mqtt.begin(on_message,on_connect)

def fun():

    # 获取指示灯状态
    power_stats = int(rpi.getLed())
    if (power_stats == 0):
        power_LED = 0
    else:
        power_LED = 1


    # 构建与云端模型一致的消息结构
    updateMsn = {
        'PowerLed': power_LED
    }
    JsonUpdataMsn = aliLink.Alink(updateMsn)
    #print(JsonUpdataMsn)

    mqtt.push(POST, JsonUpdataMsn)  # 定时向阿里云IOT推送我们构建好的Alink协议数据
