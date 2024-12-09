#include "SimpleTimer.h"

// 构造函数初始化
SimpleTimer::SimpleTimer() : taskCount(0) {
  for (uint8_t i = 0; i < 10; ++i) {
    tasks[i].enabled = false;
  }
}

// 添加一个新的定时任务
uint8_t SimpleTimer::addTask(unsigned long interval, void (*callback)()) {
  if (taskCount >= 10) return 255; // 如果任务已满，返回无效ID

  uint8_t taskId = taskCount++;
  tasks[taskId].interval = interval;
  tasks[taskId].lastTime = millis();
  tasks[taskId].callback = callback;
  tasks[taskId].enabled = true;

  return taskId;
}

// 更新所有定时任务
void SimpleTimer::update() {
  unsigned long currentTime = millis();

  for (uint8_t i = 0; i < taskCount; ++i) {
    if (!tasks[i].enabled) continue;

    if ((currentTime - tasks[i].lastTime) >= tasks[i].interval) {
      tasks[i].lastTime = currentTime;
      tasks[i].callback();
    }
  }
}

// 移除指定ID的任务
void SimpleTimer::removeTask(uint8_t id) {
  if (id < taskCount) {
    tasks[id].enabled = false;
  }
}