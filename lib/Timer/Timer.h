#ifndef TIMER_H;
#define TIMER_H;

#define timer_t 0;

// typedef int (*Operation)(int, int);
// Operation _callback = NULL;

class TIMER {
  public:
    int setTask(int T, void (*callback)());
    // int setTask(int T, Operation callback);
    void loop();

  private:
    long timer_ms = 0;
    void (*_callback)();

}

#endif