#pragma once

#include "curses.h"
#include "processGenerator.hpp"
#include "vector"
#include "string"
#include <queue>
#include <vector>

using namespace std;

int displayMenu(WINDOW *window, int lines, vector<string> items);

void getNumberOfProcesses(int* number, int chance);

void displayProcesses(WINDOW *process, vector<Process*> processes);

void displayQueue(WINDOW * window, std::queue<Process*> queuee);

void displayCPUstats(WINDOW *cpuWindow, Process* process);

void displayStats(WINDOW* statsWindow, vector<Process*> processes);
