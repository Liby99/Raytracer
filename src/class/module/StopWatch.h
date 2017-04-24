#ifndef STOP_WATCH_H
#define STOP_WATCH_H

#include <time.h>

class StopWatch {
private:
    time_t startTime;
    time_t stopTime;
    time_t duration;
public:
    StopWatch();
    void reset();
    void start();
    void cont();
    time_t curr();
    time_t stop();
};

#endif
