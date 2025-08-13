#include "process.h"

void Process::changeBurstAndWaitingTime(int btime, int wtime) {
   this -> burstTime -= btime;
   this -> waitingTime += (wtime - this -> waitingTime);
   return;
}
