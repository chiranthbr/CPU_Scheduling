#include "fcfs.hpp"
#include "processGenerator.hpp"

void updateValues(std::queue<Process*> &processQueue) {
   Process* processInCPU = processQueue.front();
   processQueue.pop();

   int currentTime = processInCPU -> arrivalTime;

   while (!processQueue.empty()) {

      currentTime += processInCPU -> burstTime;

      Process* tempProcess = processQueue.front();
      processQueue.pop();

      if(tempProcess -> arrivalTime < currentTime) {
         tempProcess -> waitingTime = (currentTime - tempProcess -> arrivalTime);
         processInCPU = tempProcess;
      } else {
         currentTime = tempProcess -> arrivalTime;
         processInCPU = tempProcess;
      }
   }
}   
   






