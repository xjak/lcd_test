#ifndef TIMER_H;
#define TIMER_H;

#define timer_t 0;

class TIMER {
  public: // 公有
    int setTask(int T, void (*callback)(int));
    void loop();
    void _callback();

  private: // 私有
    long timer_ms = 0;
    // void _callback();
}

// void _callback(); 

#endif