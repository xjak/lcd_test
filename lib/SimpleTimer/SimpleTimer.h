#ifndef SIMPLETIMER_H
#define SIMPLETIMER_H

#include <Arduino.h>

class SimpleTimer {
public:
  // 构造函数
  SimpleTimer();

  // 添加一个定时任务
  uint8_t addTask(unsigned long interval, void (*callback)());

  // 更新所有定时任务，应在主循环中调用
  void update();

  // 移除指定ID的任务
  void removeTask(uint8_t id);

private:
  struct Task {
    unsigned long interval;   // 时间间隔 (ms)
    unsigned long lastTime;   // 上次触发的时间戳
    void (*callback)();       // 回调函数
    bool enabled;             // 是否启用
  };

  Task tasks[10];             // 最多支持10个任务
  uint8_t taskCount;          // 当前任务数量
};

#endif // SIMPLETIMER_H