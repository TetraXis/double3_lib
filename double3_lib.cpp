﻿/*

	This file is just for testing

*/

#include <iostream>
#include <chrono>
#include <Windows.h>

#define AMOUNT_OF_TESTS 30
#define TEST_DURATION 100000000

using namespace std;
using namespace std::chrono;

#include "double3.h"

#define TEST true

int main()
{
	double3 a = {0,1,2};
	double3 b = {1,2,3};

	if (TEST) // =============================================================================
	{
		double sum = 0;
		uint64_t ms1, ms2;
		for (int j = 0; j < AMOUNT_OF_TESTS; j++)
		{
			ms1 = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
			for (int i = 0; i < TEST_DURATION; i++)
			{
				a = a + b;
			}
			ms2 = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
			cout << j << '\t' << ms2 - ms1 << " ms" << endl;
			sum += ms2 - ms1;
		}
		cout << "avg:\t" << sum / AMOUNT_OF_TESTS << " ms" << endl;
	} // =====================================================================================

	cout << "\n\nreturn\n";
	return 0;
}
