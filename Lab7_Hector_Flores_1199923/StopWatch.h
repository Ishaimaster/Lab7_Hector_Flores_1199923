#pragma once
#include <chrono>

class StopWatch
{

private:
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;

public:
    void Start();

    void Stop();

    double ElapsedMilliseconds();

    double ElapsedSeconds();
};


