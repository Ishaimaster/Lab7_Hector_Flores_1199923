#include "pch.h"
#include "StopWatch.h"

using namespace std;

void StopWatch::Start() 
{
    start = chrono::high_resolution_clock::now();
}

void StopWatch::Stop() {
    end = chrono::high_resolution_clock::now();
}

double StopWatch::ElapsedMilliseconds() {
    chrono::duration<double, std::milli> duration = end - start;
    return duration.count();
}

double StopWatch::ElapsedSeconds() {
    chrono::duration<double> duration = end - start;
    return duration.count();
}