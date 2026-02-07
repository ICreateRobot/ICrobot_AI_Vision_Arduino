/**
 * wifi ai对话的状态、运动命令与自定义命令
 * 
 * state：
 * 0：ai未启动、1：连接中、2：待命、3：聆听中、4：说话中、5：配网中
 * 
 * command：
 * 1：前进、2：后退、3：左转、4：右转、5：停止
 * 
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
    uint8_t state;
    uint8_t command, speed;
    uint8_t custom_command;

    ai_camera.get_ai_chat_state(state);                   // 获取状态
    ai_camera.get_ai_chat_run_state(command, speed);      // 获取运动状态
    ai_camera.get_ai_chat_custom_command(custom_command); // 获取自定义命令

    sprintf(buffer, "state:%d", state);
    Serial.println(buffer);

    sprintf(buffer, "command:%d, speed:%d", command, speed);
    Serial.println(buffer);

    sprintf(buffer, "custom_command:%d", custom_command);
    Serial.println(buffer);

    Serial.println("----------");

    delay(1000);
}

