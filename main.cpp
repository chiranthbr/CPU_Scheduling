#include "display.hpp"
#include "fcfs.hpp"
#include "processGenerator.hpp"
#include <algorithm>
#include <cstdio>
#include <curses.h>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

bool comparator(const Process *a, const Process *b) {
   return a->arrivalTime < b->arrivalTime;
}

int main(int argc, char* argv[]) {

   initscr();
   curs_set(0);
   noecho();
   cbreak();

   int ymax, xmax;
   getmaxyx(stdscr, ymax, xmax);
   attron(A_UNDERLINE);
   printw("CPU SCHEDULING VISUALIZATION");
   attroff(A_UNDERLINE);
   refresh();
   
   vector<string> visualizations = {
      "Round Robin (RR)",
      "First come first serve (FCFS)",
      "Shortest job first",
   };

   int numberOfVisualizations = visualizations.size();

   WINDOW *menuWindow = newwin(numberOfVisualizations * 2, xmax - 12, ((ymax / 2) - (numberOfVisualizations / 2)), 8);

   box(menuWindow, 0, 0);


   wrefresh(menuWindow);
   keypad(menuWindow, true);  // Enables user to give functional keys such as arrow keys!!
   
   int choose = displayMenu(menuWindow, numberOfVisualizations, visualizations);

   std::string algorithm = visualizations[choose];

   delwin(menuWindow);

   clear(); // clearing std scr (cpu scheduling) 
   attron(A_UNDERLINE);
   mvprintw(0, 1, "%s", algorithm.c_str());
   attroff(A_UNDERLINE);

   int numberOfProcess;
   getNumberOfProcesses(&numberOfProcess, 1);
   clear(); // clearing process input
   attron(A_UNDERLINE);
   mvprintw(0, 1, "%s", algorithm.c_str());
   refresh();
   attroff(A_UNDERLINE);

   queue<Process*> processesQueue;

   std::vector<Process*> processes;
   processes = generateProcess(numberOfProcess, 16, 20);
   std::sort(processes.begin(), processes.end(), comparator);
   addToQueue(processesQueue, processes);

   WINDOW *processProgress = newwin(ymax - 6, (int)(xmax / 2) + 4, 2, (int)(xmax / 2) - 4);
   wrefresh(processProgress);

   displayProcesses(processProgress, processes);


   WINDOW *qWindow = newwin(9, (int)(xmax / 2) - 6, (int)(ymax / 4) * 3, 1);
   box(qWindow, 0, 0);

   WINDOW *cpuWindow = newwin(6, (xmax / 2) - 6 , (int)(ymax / 4), 1);
   displayCPUstats(cpuWindow, processes[0]);
   wrefresh(qWindow);
   wrefresh(cpuWindow);
   
   WINDOW* statsWindow = newwin(ymax, xmax, 0, 0);

   if(choose == 1) {
      updateValuesForFCFS(processesQueue, processes, cpuWindow, processProgress, qWindow);
      getch();
      mvwprintw(statsWindow, 1, 1, std::string("AT  - Arrival TIme\n BT  - Burst TIme\n CT  - Completed Time\n TAT - Turnaround Time (CT - AT)\n WT  - Waiting Time (TAT - BT) ").c_str());
      
      mvwprintw(statsWindow, 8, 10, std::string("AT  |  BT  |  CT  |  TAT  |  WT ").c_str());

      int totalTurnaroundTIme;
      int totalWaitingTIme;
      int posLine = 9;
      int posStats = 10;

      for(int i = 0; i < processes.size(); i++) {
         int tat = processes[i] -> completedAt - processes[i] -> arrivalTime;
         int wt = tat - processes[i] -> burstTime;
         std::string allStatsOfaProcess = "";
         allStatsOfaProcess += to_string(processes[i] -> arrivalTime) + "  |  " +
            to_string(processes[i] -> burstTime) + "  |  " +
            to_string(processes[i] -> completedAt) + "  |  " +
            to_string(tat) + "  |  " +
            to_string(wt);

         totalWaitingTIme += wt;
         totalTurnaroundTIme += tat;

         mvwprintw(statsWindow, posStats, 10, allStatsOfaProcess.c_str());
         posLine += 2;
         posStats += 2;
      }
      wrefresh(statsWindow);
      getch();
   }
   delwin(processProgress);    
   delwin(qWindow);
   delwin(cpuWindow);
   endwin();

   cout << "Arrival, Burst, Waiting" << endl;
   for(auto i: processes) {
      cout << i->arrivalTime << " " << i->burstTime << " " << i->waitingTime << " " << i->completedTime << endl;
   }
   for(auto p: processes) delete p;
   
   return 0;
}




