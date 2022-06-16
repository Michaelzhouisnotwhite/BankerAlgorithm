#include <iostream>
#include "Mat.h"
#include "function.h"
using namespace std;
#define MAXROW 5
#define MAXCOL 4

int main() // NOLINT(bugprone-exception-escape)
{
	int nAvailable[MAXCOL] = {1, 5, 2, 0};
	// int nAvailable[MAXCOL] = {0, 0, 0, 0};
	int nAllocation[MAXROW * MAXCOL] = {
		0, 0, 1, 2,
		1, 0, 0, 0,
		1, 3, 5, 4,
		0, 6, 3, 2,
		0, 0, 1, 4,
	};
	int nMax[MAXROW * MAXCOL] = {
		0, 0, 1, 2,
		// 0, 4, 2, 0,
		1, 7, 5, 0,
		2, 3, 5, 6,
		0, 6, 5, 2,
		0, 6, 5, 6,
	};

	Mat mtAvailable(1, MAXCOL, nAvailable);
	Mat mtAllocation(MAXROW, MAXCOL, nAllocation);
	cout << "Available = \n" << mtAvailable << endl;
	cout << "Allocation = \n" << mtAllocation << endl;

	Mat mtMax(MAXROW, MAXCOL, nMax);
	cout << "Max = \n" << mtMax << endl;

	Mat mtNeed = mtMax - mtAllocation;
	cout << "Need = \n" << mtNeed << endl;;

	Mat mtSequence(1, MAXROW);
	Mat mtStatus(1, MAXROW);
	Mat mtQueue(1, MAXROW);
	vector<int> queue;


	cout << "All Safe Sequences: \n";
	FindSecuritySequence(mtAvailable, mtAllocation, mtNeed, mtStatus, MAXROW, queue, 0);
	system("pause");
	return 0;
}
