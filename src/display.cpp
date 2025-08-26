#include "display.hpp"
#include "processGenerator.hpp"
#include "helperFunctions.hpp"
#include <cstdlib>
#include <curses.h>
#include <iostream>
#include <string>
#include <vector>

int displayMenu(WINDOW *window, int lines, vector<string> items) {
   int highlight = 0;
   int max = items.size() - 1;
   int choice;

   while (true) {
      for(int i = 0; i <= max; i++) {
         if(i == highlight)
            wattron(window, A_REVERSE);
         mvwprintw(window, i + 1, 1, items[i].c_str());
         wattroff(window, A_REVERSE);
      }
      choice = wgetch(window);

      switch (choice) {
         case KEY_UP:
         case 107:
         case KEY_LEFT:
            highlight = ((highlight - 1) < 0)? 0 : highlight - 1;
            break;
         case KEY_DOWN:
         case 106:
         case KEY_RIGHT:
            highlight++;
            if(highlight == max + 1)
               highlight = max;
            break;
         default:
            break;
      }

      if(choice == 10)
         break;
   }
   return highlight;
}

void getNumberOfProcesses(int* number, int chance) {
   echo();
   curs_set(1);
   if(chance  == 1) {
      mvprintw(2, 1, "Enter number of Processes bw (1 and 15): ");
      refresh();

   }
   else {
      move(2, 0);
      clrtoeol();
      mvprintw(2, 1, "Please enter bw 1 and 15 only integer: ");
      refresh();
   }

   char numProcess[3];
   getstr(numProcess);

   if(atoi(numProcess) == 0 || atoi(numProcess) < 1 || atoi(numProcess) > 15) {
      getNumberOfProcesses(number, ++chance);
   } else {
      *number = atoi(numProcess);
   }
   curs_set(0);
   return;
}

void displayProcesses(WINDOW *process, vector<Process*> processes) {
   int print = 1;

   for(int i = 0; i < processes.size(); i++) {
      std::string loaded ="";
      std::string loading = "";
      int completed = (int)(((float)processes[i]->completedTime / processes[i]->burstTime) * 10);
      int remaining = 10 - completed;

      multiplyString(loaded, completed, 1);
      multiplyString(loading, remaining, 2);

      std::string progressBar = std::string("P") + to_string(processes[i] -> pid) + "  " + loaded + loading + "  " + to_string(completed * 10) + "%";
      mvwprintw(process, print, 1, "%s", progressBar.c_str());
      // mvwprintw(process, print, 1, ("P" + to_string(processes[i] -> pid) + loading).c_str());
      print += 2;
   }
   wrefresh(process);
}

void displayQueue(WINDOW *qWindow, int capacity) {
   
}

void displayCPUstats(WINDOW *cpuWindow, Process* process) {
   mvwprintw(cpuWindow, 1, 1, ("In CPU:  P - " + to_string(process -> pid)).c_str());
}

void displayStats(WINDOW* statsWindow, vector<Process*> processes) {
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







