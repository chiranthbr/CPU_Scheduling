#include "process.hpp"


Process::Process(int pid, int atime, int btime) : pid(pid), arrivalTime(atime), burstTime(btime), waitingTime(0), completedTime(0), completedAt(0) {}
