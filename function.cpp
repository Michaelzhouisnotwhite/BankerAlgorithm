#include "function.h"
#include "Mat.h"
#include<iostream>
using namespace std;

void FindSecuritySequence(Mat mtAvailable, Mat mtAllocation, Mat mtNeed, const Mat& mtStatus, int row, vector<int> queue,
                          int floor)
{
	if (floor == row)
	{
		for (int i : queue)
		{
			cout << "P" << i << " ";
		}
		cout.put('\n');
	}

	for (int i = 0; i < row; i++)
	{
		if (!mtStatus.matrix[i])
		{
			Mat r_mtNeed = mtNeed(i);
			if (r_mtNeed <= mtAvailable)
			{
				mtStatus.matrix[i] = 1;
				//cout << "states = \n" << mtStatus << endl;
				Mat r_mtAlloc = mtAllocation(i);
				mtAvailable = mtAvailable + r_mtAlloc;
				queue.push_back(i);
				FindSecuritySequence(mtAvailable, mtAllocation, mtNeed, mtStatus, row, queue, floor + 1);
				mtStatus.matrix[i] = 0;
				queue.pop_back();
				mtAvailable = mtAvailable - r_mtAlloc;
			}
		}
	}
}
