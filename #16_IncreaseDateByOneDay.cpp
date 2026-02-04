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

	if (Month < 1 || Month > 12)
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

void IncreaseOneDay(sDate& Date) {

	if (IsLastDayInMonth(Date)) {

		if (IsLastMonthInYear(Date.Month)) {
		
			Date.Year++;
			Date.Month = 1;
			Date.Day = 1;
		}
		else {
		
			Date.Month++;
			Date.Day = 1;
		}
	}
	else
		Date.Day++;
}

int main() {

	sDate Date = ReadFullDate();
	cout << "\n";

	IncreaseOneDay(Date);

	cout << "Date after adding one day is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	return 0;
}