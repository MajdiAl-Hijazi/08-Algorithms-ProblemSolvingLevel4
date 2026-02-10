#include<iostream>
#include "DateLib.h"
using namespace std;

int main() {

	stPeriod Period = PeriodFun::ReadPeriod();

	cout << "\nPeriod Length = " << PeriodFun::CalculatePeriodLengthInDays(Period) << endl;
	cout << "Period Length (Include End Date) = " << PeriodFun::CalculatePeriodLengthInDays(Period, true) << endl;

	return 0;
}