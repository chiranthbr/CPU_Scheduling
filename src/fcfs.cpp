#include "fcfs.hpp"
#include "processGenerator.hpp"

void startScheduling(WINDOW *cpuWindow, WINDOW *queueWindow, WINDOW *processWindow, std::queue<Process *> &processesQueue) {

   Process *processInCPU = processesQueue.front();
   processesQueue.pop();

   int currTime = processInCPU -> arrivalTime;

   //do {
   //   
   //   

   //}while ();
}





