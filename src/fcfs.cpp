#include "fcfs.hpp"
#include "display.hpp"
#include "processGenerator.hpp"
#include <chrono>
#include <thread>
#include <vector>

void updateValuesForFCFS(std::queue<Process*> &processQueue, std::vector<Process*> processes, WINDOW* cpuWindow, WINDOW* processWindow, WINDOW* queueWindow) {
   Process* processInCPU = processQueue.front();
   processQueue.pop();

   int currentTime = processInCPU -> arrivalTime;
   std::this_thread::sleep_for(std::chrono::seconds(3));
   
   do {
      updateVisualsForFCFS(processInCPU, processes, cpuWindow, processWindow, queueWindow);

      currentTime += processInCPU -> burstTime;
      processInCPU->completedAt = currentTime;

      Process* tempProcess = processQueue.front();
      processQueue.pop();

      if(tempProcess -> arrivalTime < currentTime) {
         tempProcess -> waitingTime = (currentTime - tempProcess -> arrivalTime);
         processInCPU = tempProcess;
      } else {
         currentTime = tempProcess -> arrivalTime;
         processInCPU = tempProcess;
      }
      if(processQueue.empty()) {
         tempProcess -> completedAt = currentTime + tempProcess -> burstTime;
      }
      updateVisualsForFCFS(processInCPU, processes, cpuWindow, processWindow, queueWindow);
   } while(!processQueue.empty());
}   
   

void updateVisualsForFCFS(Process* processInCPU, vector<Process*> processes, WINDOW* cpuWindow, WINDOW* processWindow, WINDOW* queueWindow) {
   displayCPUstats(cpuWindow, processInCPU);
   wrefresh(cpuWindow);
   while (true) {
      processInCPU->completedTime += 2;
      if(processInCPU->completedTime > processInCPU->burstTime) {
         processInCPU -> completedTime = processInCPU -> burstTime;
         displayProcesses(processWindow, processes);
         return;
      }
      displayProcesses(processWindow, processes);
      wrefresh(processWindow);
      std::this_thread::sleep_for(std::chrono::seconds(1));
   }
}
