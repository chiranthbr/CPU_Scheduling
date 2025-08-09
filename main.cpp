#include <iostream>

#include "src/display.hpp"

using namespace std;
int main(int argc, char* argv[]) {

   initscr();
   noecho();
   cbreak();

   int ymax, xmax;
   getmaxyx(stdscr, ymax, xmax);
   printw("CPU SCHEDULING VISUALIZATION");
   refresh();
   
   vector<string> visualizations = {
      "Round Robin (RR)",
      "First come first serve (FCFS)"
   };

   int numberOfVisualizations = visualizations.size();

   WINDOW *menuWindow = newwin(numberOfVisualizations * 2, xmax - 12, ((ymax / 2) - (numberOfVisualizations / 2)), 8);

   box(menuWindow, 0, 0);

   wrefresh(menuWindow);
   keypad(menuWindow, true);  // Enables user to give functional keys such as arrow keys!!

   displayMenu(menuWindow, numberOfVisualizations, visualizations);
   getch();
   delwin(menuWindow);

   endwin();
   
   return 0;
}
