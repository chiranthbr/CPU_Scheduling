#include "helperFunctions.hpp"

void multiplyString(std::string &s, int n, int num) {
   std::string temp;
   if(num == 1) temp = "|";
   else temp = "-";

   for(int i = 0; i < n; i++) {
      s += temp;
   }
}

