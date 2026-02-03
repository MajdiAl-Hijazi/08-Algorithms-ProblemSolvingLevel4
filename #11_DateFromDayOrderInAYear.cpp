#include<iostream>
#include<string>
using namespace std;

struct sDate {

	short Year;
	short Month;
	short Day;
};

bool isLeapYear(short Year) {

	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year) {

	if (Month < 1 || Month>12)
		return 0;

	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

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

short TotalDaysFromBeginingOfYear(short Day, short Month, short Year) {

	short TotalDays = 0;

	if ((Day < 1 || Day > 31) || (Month < 1 || Month > 12)) {

		cout << "Error";
		return 0;
	}

	for (short i = 1; i < Month; i++)
		TotalDays += NumberOfDaysInAMonth(i, Year);

	TotalDays += Day;

	return TotalDays;
}

sDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year) {

	sDate Date;

	short RemainingDays = DateOrderInYear;
	short MonthDays = 0;
	
	Date.Year = Year;
	Date.Month = 1;

	while (true) {

		MonthDays = NumberOfDaysInAMonth(Date.Month, Year);

		if (RemainingDays > MonthDays) {

			RemainingDays -= MonthDays;
			Date.Month++;
		}
		else {

			Date.Day = RemainingDays;
			break;
		}
	}

	return Date;
}

int main() {

	short Day, Month, Year;
	Day = ReadDay(),
	Month = ReadMonth();
	Year = ReadYear();

	short DaysOrderInYear = TotalDaysFromBeginingOfYear(Day, Month, Year);

	cout << "\nNumber of days from the begining of the year is " << DaysOrderInYear << endl;

	sDate Date = GetDateFromDayOrderInYear(DaysOrderInYear, Year);

	cout << "\nDate for [" << DaysOrderInYear << "] is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	return 0;
}