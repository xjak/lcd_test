#include <Timer.h>

int __callback;

// void functionWithCallback(void (*callback)(int), int arg) {}

void TIMER::setTask(void (*callback)(int), int T) {
// void TIMER::setTask(int T, void (*callback)(int)) {
  timer_ms = T;
  const auto fn = callback;
  __callback = fn
}

void TIMER::loop(void (*callback)(int)) {
  if (millis() - timer_t >= 5000) {
    timer_t = millis();
    callback();
  }
}