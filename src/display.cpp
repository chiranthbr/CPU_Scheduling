#include "display.hpp"
#include <cstdlib>
#include <curses.h>
#include <string>

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

void displayProcesses(WINDOW *process, int numberOfProcess) {
   int print = 1;
   std::string loading = "  --------------------";

   for(int i = 0; i < numberOfProcess; i++) {
      mvwprintw(process, print, 1, (to_string(i) + loading).c_str());
      print += 2;
   }
   wrefresh(process);
}














