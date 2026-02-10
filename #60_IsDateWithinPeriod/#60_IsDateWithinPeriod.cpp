#include<iostream>
#include "DateLib.h"
using namespace std;

int main() {

	cout << "Enter Period :\n";
	stPeriod Period = PeriodFun::ReadPeriod();

	cout << "\nEnter Date to Check :";
	stDate Date = ReadDate::ReadFullDate();

	if (PeriodFun::IsDateWithinPeriod(Period, Date))
		cout << "\nYes, Date is Within Period\n";
	else
		cout << "\nNo, Date is not Within Period\n";

	return 0;
}