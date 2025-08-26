#pragma once


#include "processGenerator.hpp"
#include <curses.h>
#include <vector>

void updateValuesForSJF(std::queue<Process*> &processQueue, std::vector<Process*> processes, WINDOW* cpuWindow, WINDOW* processWindow, WINDOW* queueWindow);


void updateVisualsForSJF(Process* processInCPU, std::vector<Process*> processes, WINDOW* cpuWindow, WINDOW* processWindow, WINDOW* queueWindow);



