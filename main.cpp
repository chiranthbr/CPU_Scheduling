#include "display.hpp"
#include "processGenerator.hpp"
#include <cstdio>
#include <curses.h>
#include "iostream"
#include <queue>
#include <string>
#include <vector>

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
   processes = generateProcess(numberOfProcess, 16, 20, processesQueue);

   WINDOW *processProgress = newwin(ymax - 6, (int)(xmax / 2) + 4, 2, (int)(xmax / 2) - 4);
   wrefresh(processProgress);

   displayProcesses(processProgress, processes);

   delwin(processProgress);    

   WINDOW *qWindow = newwin(9, (int)(xmax / 2) - 6, (int)(ymax / 4) * 3, 1);
   box(qWindow, 0, 0);

   WINDOW *cpuWindow = newwin(6, (xmax / 2) - 6 , (int)(ymax / 4), 1);
   displayCPUstats(cpuWindow, 3);
   wrefresh(qWindow);
   wrefresh(cpuWindow);
   getch();

   endwin();

   for(auto p: processes) delete p;

   cout << processesQueue.empty() << endl;
   
   return 0;
}





