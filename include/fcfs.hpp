#pragma once

#include "processGenerator.hpp"
#include <curses.h>
#include <queue>

void updateVisuals(WINDOW *cpuWindow, WINDOW *queueWindow, WINDOW *processWindow, std::queue<Process*> &processesQueue);

void updateValues(std::queue<Process*> &processQueue);
void updateWindowsAndRefresh();
