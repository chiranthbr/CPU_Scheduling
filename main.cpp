#include "display.hpp"
#include <curses.h>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {

   initscr();
   curs_set(0);
   noecho();
   cbreak();

   int ymax, xmax;
   getmaxyx(stdscr, ymax, xmax);
   printw("CPU SCHEDULING VISUALIZATION");
   refresh();
   
   vector<string> visualizations = {
      "Round Robin (RR)",
      "First come first serve (FCFS)",
      "Shortest job first",
      "a",
      "b"
   };

   int numberOfVisualizations = visualizations.size();

   WINDOW *menuWindow = newwin(numberOfVisualizations * 2, xmax - 12, ((ymax / 2) - (numberOfVisualizations / 2)), 8);

   box(menuWindow, 0, 0);


   wrefresh(menuWindow);
   keypad(menuWindow, true);  // Enables user to give functional keys such as arrow keys!!
   
   int algorithm = displayMenu(menuWindow, numberOfVisualizations, visualizations);

   mvwprintw(stdscr, 2, 1, to_string(algorithm).c_str());

   getch();
   delwin(menuWindow);

   endwin();
   
   return 0;
}






