#include<iostream>
#include "DateLib.h"
using namespace std;

int main() {

	cout << "Enter period 1 :\n";
	stPeriod Period1 = PeriodFun::ReadPeriod();

	cout << "\nEnter period 2 :\n";
	stPeriod Period2 = PeriodFun::ReadPeriod();

	cout << "\nOverlap Days count is : " << PeriodFun::CountOverlapDays(Period1, Period2) << endl;

	return 0;
}