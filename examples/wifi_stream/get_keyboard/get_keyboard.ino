
#include <Arduino.h>
#include "ai_camera.h"

// 设置 ai 视觉模块操作句柄
AiCamera ai_camera;

void setup(void)
{
    Serial.begin(115200);  // 初始化串口
    Wire.begin();          // 初始化 I2C
    ai_camera.Init(&Wire); // 初始化
}

void loop(void)
{
    char buffer[128];
    uint8_t keyboard;

    ai_camera.get_wifi_stream_keyboard(keyboard);            // 获取电脑键盘 wasd 按键

    sprintf(buffer, "keyboard:%d\n", keyboard);
    Serial.print(buffer);

    Serial.println("----------");

    delay(1000);
}