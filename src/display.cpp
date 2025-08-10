#include "display.hpp"
#include <curses.h>
#include <regex>

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
            highlight = ((highlight - 1) < 0)? 0 : highlight - 1;
            break;
         case KEY_DOWN:
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



