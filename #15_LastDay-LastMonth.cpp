#include<iostream>
using namespace std;

struct sDate {

	short Year;
	short Month;
	short Day;
};

short ReadYear() {

	short Year;
	cout << "\nPlease enter a year ? ";
	cin >> Year;
	return Year;
}

short ReadMonth() {

	short Month;
	cout << "\nPlease enter a month ? ";
	cin >> Month;
	return Month;
}

short ReadDay() {

	short Day;
	cout << "\nPlease enter a day ? ";
	cin >> Day;
	return Day;
}

sDate ReadFullDate() {

	sDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}

bool IsLeapYear(short Year) {

	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year) {

	if (Month < 1 || Month>12)
		return 0;

	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

bool IsLastDayInMonth(const sDate& Date) {

	return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(const short& Month) {

	return (Month == 12);
}

int main() {

	sDate Date = ReadFullDate();
	cout << "\n";

	if (IsLastDayInMonth(Date))
		cout << "\nYes, Day is last Day in Month.\n";
	else
		cout << "\nNo, Day isn't last Day in Month.\n";

	if (IsLastMonthInYear(Date.Month))
		cout << "\nYes, Month is last Month in Year.\n";
	else
		cout << "\nNo, Month isn't last Month in Year.\n";

	return 0;
}