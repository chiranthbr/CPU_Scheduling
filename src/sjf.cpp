#include "sjf.hpp"
#include "display.hpp"
#include <chrono>
#include <curses.h>
#include <thread>
#include <vector>

void updateValuesForSJF(std::queue<Process*> &processQueue, std::vector<Process*> processes, WINDOW* cpuWindow, WINDOW* processWindow, WINDOW* queueWindow) {

   int time = 0;
   std::vector<bool> isProcessCompleted(processes.size(), false);
   int completed = 0;

   while(completed < processes.size()) {
      int idx = -1;
      int minBT = 1e9;

      for(int i = 0; i < processes.size(); i++) {
         if(!isProcessCompleted[i] && processes[i] -> arrivalTime <= time) {
            if(processes[i] -> burstTime < minBT) {
               minBT = processes[i] -> burstTime;
               idx = i;
            }
         }
      }

      if(idx == -1) time++;
      else {
         time += processes[idx] -> burstTime;
         processes[idx] -> completedAt = time;
         isProcessCompleted[idx] = true;
         completed++;
      }
      if(idx >= 0) updateVisualsForSJF(processes[idx], processes, cpuWindow, processWindow, queueWindow);      
   }
}


void updateVisualsForSJF(Process* processInCPU, std::vector<Process*> processes, WINDOW* cpuWindow, WINDOW* processWindow, WINDOW* queueWindow) {

   displayCPUstats(cpuWindow, processInCPU);
   wrefresh(cpuWindow);

   while (true) {
      processInCPU -> completedTime += 2;
      if(processInCPU -> completedTime > processInCPU -> burstTime) {
         processInCPU -> completedTime = processInCPU -> burstTime;
         displayProcesses(processWindow, processes);
         return;
      }
      displayProcesses(processWindow, processes);
      wrefresh(processWindow);
      std::this_thread::sleep_for(std::chrono::seconds(1));
   }

}



