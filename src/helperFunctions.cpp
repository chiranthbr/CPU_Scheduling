#include "helperFunctions.hpp"

void multiplyString(std::string& s, int& n) {
   if(n == 0) {
      s = "";
      return;
   }
   std::string temp = s;
   for(int i = 0; i < n - 1; i++) {
      s += temp;
   }
}



