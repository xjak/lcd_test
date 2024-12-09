#include <Arduino.h>
#include "SimpleTimer.h"

SimpleTimer timer;

// 定义一些回调函数
void blinkLED() {
  static int state = LOW;
  digitalWrite(LED_BUILTIN, state = !state);
}

void printMessage() {
  Serial.println("Time's up!");
}

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  // 添加定时任务
  timer.addTask(1000, blinkLED);     // 每秒切换一次LED状态
  timer.addTask(5000, printMessage); // 每5秒打印一条消息
}

void loop() {
  // 更新定时器
  timer.update();
}