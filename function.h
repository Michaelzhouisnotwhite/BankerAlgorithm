#pragma once
#include "Mat.h"
#include <vector>
using namespace std;
void FindSecuritySequence(Mat mtAvailable, Mat mtAllocation, Mat mtNeed, const Mat& mtStatus, int row, vector<int> queue,
                          int floor);
