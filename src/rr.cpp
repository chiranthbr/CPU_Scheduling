#include "rr.hpp"
#include "display.hpp"
#include "processGenerator.hpp"
#include <chrono>
#include <curses.h>
#include <queue>
#include <thread>

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
      if(processInCPU != nullptr) updateVisualsForRR(cpuWIndow, processesWindow, queueWindow, processes, processInCPU);
   }
}

void updateVisualsForRR(WINDOW* cpuWIndow, WINDOW* processesWindow, WINDOW* queueWindow, std::vector<Process*> processes, Process* processInCPU) {
   displayCPUstats(cpuWIndow, processInCPU);
   displayProcesses(processesWindow, processes);
   wrefresh(cpuWIndow);
   wrefresh(processesWindow);

   std::this_thread::sleep_for(std::chrono::seconds(1));
}



