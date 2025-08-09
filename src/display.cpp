#include "display.hpp"

void displayMenu(WINDOW *window, int lines, vector<string> items) {
   for(int i = 0; i < lines; i++) {
      mvwprintw(window, i + 1, 1, "%s", items[i].c_str());
   }
}
