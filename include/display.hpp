#pragma once

#include "curses.h"
#include "processGenerator.hpp"
#include "vector"
#include "string"
#include <vector>

using namespace std;

int displayMenu(WINDOW *window, int lines, vector<string> items);

void getNumberOfProcesses(int* number, int chance);

void displayProcesses(WINDOW *process, vector<Process*> processes);

void displayQueue(WINDOW * window, int capacity);

void displayCPUstats(WINDOW *cpuWindow, Process* process);



