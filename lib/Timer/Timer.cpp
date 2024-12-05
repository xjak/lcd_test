#include <Timer.h>

// void __callback;

typedef int (*Operation)(int, int);
Operation _callback = NULL;

void TIMER::setTask(int T, int (*callback)(int)) {
  timer_ms = T;
  _callback = callback;
}

void TIMER::loop(void (*callback)(int)) {
  if (millis() - timer_t >= timer_ms) {
    timer_t = millis();
    callback();
  }
}