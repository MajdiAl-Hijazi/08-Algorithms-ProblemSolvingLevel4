#include<iostream>
#include "DateLib.h"
using namespace std;

int main() {

	cout << "Vacation Starts : ";
	stDate DateFrom = ReadDate::ReadFullDate();

	cout << "\n\nVacation Ends : ";
	stDate DateTo = ReadDate::ReadFullDate();

	cout << "\n\nVacation From : " << DateFun::DayShortName(DateFun::DayOfWeekOrder(DateFrom))
		<< ", " << DateFrom.Day << "/" << DateFrom.Month << "/" << DateFrom.Year << endl;

	cout << "\n\nVacation To : " << DateFun::DayShortName(DateFun::DayOfWeekOrder(DateTo))
		<< ", " << DateTo.Day << "/" << DateTo.Month << "/" << DateTo.Year << endl;

	cout << "\n\nActual Vacation Days is : " << DateFun::CalculateVacationDays(DateFrom, DateTo) << endl;

	return 0;
}