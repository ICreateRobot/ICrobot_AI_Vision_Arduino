/**
 * wifi图传，获取网页摇杆、按钮，键盘wasd按键
 * 获取连接到的wifi名称、密码与ip
 * 
 * 需要先将设备连接到2.4g的wifi网络，并打开对应ip的网页
 */

#include <Arduino.h>
#include "ai_camera.h"

// 设置 ai 视觉模块操作句柄
AiCamera ai_camera;

void setup(void)
{
    Serial.begin(115200);  // 初始化串口
    ai_camera.Init();      // 初始化
}

void loop(void)
{
    char buffer[128];
    int8_t x, y;
    uint8_t button;
    uint8_t keyboard;
    String ssid, password;
    String ip;

    ai_camera.get_wifi_stream_joystick(x, y);                // 获取网页摇杆
    ai_camera.get_wifi_stream_button(button);                // 获取网页按键
    ai_camera.get_wifi_stream_keyboard(keyboard);            // 获取电脑键盘 wasd 按键
    ai_camera.get_wifi_stream_ssid_password(ssid, password); // 获取连接到wifi的名称与密码
    ai_camera.get_wifi_stream_ip(ip);                        // 获取连接到wifi的ip地址

    sprintf(buffer, "x:%d, y:%d\n", x, y);
    Serial.print(buffer);

    sprintf(buffer, "button:%d, keyboard:%d\n", button, keyboard);
    Serial.print(buffer);

    sprintf(buffer, "ssid:%s, password:%s\n", ssid.c_str(), password.c_str());
    Serial.print(buffer);

    sprintf(buffer, "ip:%s\n", ip.c_str());
    Serial.print(buffer);

    Serial.println("----------");

    delay(1000);
}

