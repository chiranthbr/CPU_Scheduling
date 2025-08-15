#include "process.hpp"

void Process::changeBurstAndWaitingTime(int btime, int wtime) {
   this -> burstTime -= btime;
   this -> waitingTime += (wtime - this -> waitingTime);
   return;
}

Process::Process(int pid, int atime, int btime) : pid(pid), arrivalTime(atime), burstTime(btime), waitingTime(0), completedTime(2) {}
