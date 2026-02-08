#include<iostream>
#include "DateLib.h";
using namespace std;

int main() {

	//stDate Date = DateFun::GetSystemDate();
	stDate Date = ReadDate::ReadFullDate();

	cout << "Today is " << DateFun::DayShortName(DateFun::DayOfWeekOrder(Date))
		<< ", " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	cout << "\nIt is End of week ?\n";
	if (DateFun::IsEndOfWeek(Date))
		cout << "Yes, end of week.";
	else
		cout << "No, Not end of week.";

	cout << "\n\nIt is WeekEnd ?\n";
	if (DateFun::IsWeekEnd(Date))
		cout << "Yes, it is a week end.";
	else
		cout << "No it is " << DateFun::DayShortName(DateFun::DayOfWeekOrder(Date)) << ", not a week end.";

	cout << "\n\nIt is Business Day ?\n";
	if (DateFun::IsBusinessDay(Date))
		cout << "Yes, it is a business day.";
	else
		cout << "No, it is not a business day.";

	cout << "\n\n";

	cout << "Days until end of week : " << DateFun::DaysUntilTheEndOfWeek(Date) << " Day(s)." << endl;
	cout << "Days until end of month : " << DateFun::DaysUntilTheEndOfMonth(Date) << " Day(s)." << endl;
	cout << "Days until end of year : " << DateFun::DaysUntilTheEndOfYear(Date) << " Day(s)." << endl;


	return 0;
}
