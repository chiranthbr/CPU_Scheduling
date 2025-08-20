#pragma once

#include "processGenerator.hpp"
#include <curses.h>
#include <queue>
#include <vector>

void updateVisuals(Process* processInCPU, std::vector<Process*> processes, WINDOW* cpuWindow, WINDOW* processWindow, WINDOW* queueWindow);

void updateValues(std::queue<Process*> &processQueue, std::vector<Process*> processes, WINDOW* cpuWindow, WINDOW* processWindow, WINDOW* queueWindow);
void updateWindowsAndRefresh(WINDOW* cpuWIndow, WINDOW* queueWindow, WINDOW* processWindow);


