#pragma once

#include "process.h"
#include <queue>
#include <vector>

std::vector<Process*> generateProcess(int count, int maxArrival, int maxBurst);

void addToQueue(std::queue<Process*> &processQueue, std::vector<Process*> processVector);
