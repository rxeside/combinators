#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <Windows.h>
using TimeMap = std::map<int, int>;
std::vector<int> FindArticulationPoints(std::vector<std::vector<bool>> & graph);
