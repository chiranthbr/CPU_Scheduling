#pragma once

#include "processGenerator.hpp"
#include <curses.h>
#include <queue>
#include <vector>

void updateVisualsForFCFS(Process* processInCPU, std::vector<Process*> processes, WINDOW* cpuWindow, WINDOW* processWindow, WINDOW* queueWindow, std::queue<Process*> &queuee);

void updateValuesForFCFS(std::queue<Process*> &processQueue, std::vector<Process*> processes, WINDOW* cpuWindow, WINDOW* processWindow, WINDOW* queueWindow);





