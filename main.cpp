#include "display.hpp"
#include <curses.h>
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
   mvprintw(0, 1, "%s", algorithm.c_str());

   int numberOfProcess;
   getNumberOfProcesses(&numberOfProcess, 1);
   clear(); // clearing process input

   endwin();
   
   return 0;
}






