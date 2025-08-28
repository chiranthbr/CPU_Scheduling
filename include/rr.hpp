#pragma once

#include "processGenerator.hpp"
#include <curses.h>
#include <vector>
#include <queue>

void updateValuesForRR(std::queue<Process*> queue, WINDOW* cpuWIndow, WINDOW* processesWindow, WINDOW* queueWindow, std::vector<Process*> processes);

void updateVisualsForRR(WINDOW* cpuWIndow, WINDOW* processesWindow, WINDOW* queueWindow, std::vector<Process*> processes, Process* processInCPU);
