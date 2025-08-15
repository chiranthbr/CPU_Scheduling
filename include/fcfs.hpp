#pragma once

#include "processGenerator.hpp"
#include <curses.h>
#include <queue>

void startScheduling(WINDOW *cpuWindow, WINDOW *queueWindow, WINDOW *processWindow, std::queue<Process*> &processesQueue);
