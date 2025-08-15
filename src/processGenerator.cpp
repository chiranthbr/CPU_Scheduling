#include "processGenerator.hpp"
#include <cstdlib>
#include <ctime>

std::vector<Process*> generateProcess(int count, int maxArrival, int maxBurst) {
   std::srand(std::time(nullptr));
   std::vector<Process*> processes;

   for(int i = 0; i < count; i++) {
      int pid = 1000 + std::rand() % 9000; // 1000 - 9999
      int arrival = std::rand() % (maxArrival + 1);
      int burst = 4 + std::rand() % 10;
      Process *newProcess = new Process(pid, arrival, burst);
      processes.push_back(newProcess);
      // processesQueue.push(newProcess);
   }

   return processes;
}

void addToQueue(std::queue<Process*> &processQueue, std::vector<Process*> processVector) {
   for(auto i: processVector) {
      processQueue.push(i);
   }

}



