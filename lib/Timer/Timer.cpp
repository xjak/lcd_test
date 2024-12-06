#include <Timer.h>


int TIMER::setTask(int T, void (*callback)()) {
// void TIMER::setTask(int T, Operation callback ) {
  timer_ms = T;
  _callback = callback;
}


void TIMER::loop() {
  if (millis() - timer_t >= timer_ms) {
    timer_t = millis();
    _callback();
  }
}

// // 定义一个回调函数
// void CallbackFunction() {
//   std::cout << "Callback function called" << std::endl;
// }

// // 定义一个调用者函数，它接受一个函数指针作为参数
// void CallerFunction(void (*funcPtr)()) {
//   std::cout << "Caller function called" << std::endl;
//   funcPtr(); // 调用回调函数
// }

// int main() {
//   // 注册回调函数
//   void (*funcPtr)() = CallbackFunction;
//   // 调用者函数调用回调函数
//   CallerFunction(funcPtr);
//   return 0;
// }