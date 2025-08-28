#include "rr.hpp"
#include "processGenerator.hpp"
#include <queue>

void updateValuesForRR(std::queue<Process *> queue, WINDOW *cpuWIndow, WINDOW *processesWindow, WINDOW *queueWindow, std::vector<Process *> processes) {
   int currentTIme = 0;
   int quantTime = 1;
   std::queue<Process*> readyProcessesQueue;
   Process* processInCPU = nullptr;

   while (!queue.empty() || !readyProcessesQueue.empty()) {

      while (!queue.empty()) {
         if(queue.front() -> arrivalTime == currentTIme) {
            readyProcessesQueue.push(queue.front());
            queue.pop();
         } else break;
      }

      if(!readyProcessesQueue.empty()) {
         processInCPU = readyProcessesQueue.front();
         if(processInCPU -> completedTime + quantTime == processInCPU -> burstTime) {
            processInCPU -> completedTime = processInCPU -> burstTime;
            processInCPU -> completedAt = currentTIme + quantTime;
            readyProcessesQueue.pop();
         } else {

            processInCPU -> completedTime += quantTime;

            readyProcessesQueue.pop();
            readyProcessesQueue.push(processInCPU);
         }
      } 
      currentTIme++;
   }
}
