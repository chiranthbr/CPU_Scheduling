#include "curses.h"
#include "vector"
#include "string"

using namespace std;

int displayMenu(WINDOW *window, int lines, vector<string> items);

void getNumberOfProcesses(int* number, int chance);

void displayProcesses(WINDOW *process, int numberOfProcess);

void displayQueue(WINDOW * window, int capacity);

void displayCPUstats(WINDOW *cpuWindow, int processNumber);



