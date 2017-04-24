#include "module/StopWatch.h"

StopWatch::StopWatch() {
    reset();
}

void StopWatch::reset() {
    startTime = 0;
    stopTime = 0;
    duration = 0;
}

void StopWatch::start() {
    startTime = time(NULL);
}

void StopWatch::cont() {
    startTime += difftime(time(NULL), stopTime);
}

time_t StopWatch::curr() {
    return difftime(time(NULL), startTime);
}

time_t StopWatch::stop() {
    stopTime = time(NULL);
    duration = difftime(stopTime, startTime);
}
