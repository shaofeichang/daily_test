#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int main()
{
	int testCounts;
	int testNums;
	cin >> testCounts;
	int testCountsReocrd = 0;
	if (testCounts < 0 || testCounts > 10)
		return 0;
	vector<vector<int>> vec(testCounts);
	while (testCountsReocrd < testCounts)
	{
		cin >> testNums;
		while (testNums--)
		{
			int inputNum;
			cin >> inputNum;
			vec.at(testCountsReocrd).push_back(inputNum);
			getchar();
		}
		testCountsReocrd++;
	}
	testCountsReocrd = 0;
	while (testCountsReocrd < testCounts)
	{
		int returnNum = 0;
		int sizeR = vec[testCountsReocrd].size();
		for (size_t i = 0; i < sizeR - 2; i++)
		{
			if (vec[testCountsReocrd].at(i) + vec[testCountsReocrd].at(i + 2) < vec[testCountsReocrd].at(i))
			{
				returnNum = 1;
			}
		}
		int at0 = vec[testCountsReocrd].at(0);
		int atLast1 = vec[testCountsReocrd].at(sizeR - 1);
		int atLast2 = vec[testCountsReocrd].at(sizeR - 2);
		int at1 = vec[testCountsReocrd].at(1);
		if (returnNum == 0 &&  (atLast1 + at0 > at1) && (atLast2 + at0 > atLast1))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
		testCountsReocrd++;
	}
	system("pause");
	return 0;
}