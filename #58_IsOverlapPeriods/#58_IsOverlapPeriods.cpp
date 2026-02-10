#include<iostream>
#include "DateLib.h"
using namespace std;

int main() {

	cout << "Enter Period 1:" << endl;
	stPeriod Period1 = PeriodFun::ReadPeriod();

	cout << "\nEnter Period 2:" << endl;
	stPeriod Period2 = PeriodFun::ReadPeriod();

	cout << "\n\n";

	if (PeriodFun::IsOverlapPeriod(Period1, Period2))
		cout << "Yes, Periods Overlap" << endl;
	else
		cout << "No, Periods Not Overlap" << endl;

	return 0;
}