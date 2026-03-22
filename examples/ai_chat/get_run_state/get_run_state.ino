
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
    uint8_t command, speed;

    ai_camera.get_ai_chat_run_state(command, speed);      // 获取运动状态

    sprintf(buffer, "command:%d, speed:%d", command, speed);
    Serial.println(buffer);

    Serial.println("----------");

    delay(1000);
}