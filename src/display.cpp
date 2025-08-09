#include "display.hpp"

void displayMenu(WINDOW *window, int lines, std::vector<std::string> items) {
   for(int i = 0; i < lines; i++) {
      mvwprintw(window, i + 1, 1, items[0].c_str());
   }
}
