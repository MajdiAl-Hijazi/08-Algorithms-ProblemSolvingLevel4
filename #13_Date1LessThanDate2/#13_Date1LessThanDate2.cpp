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

bool IsDate1BeforeDate2(const sDate& Date1, const sDate& Date2) {

	return ((Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year) ? ((Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month) ? Date1.Day < Date2.Day : false) : false);
}

int main() {

	sDate Date1 = ReadFullDate();
	cout << "\n";
	sDate Date2 = ReadFullDate();

	if (IsDate1BeforeDate2(Date1, Date2))
		cout << "\nYes, Date1 is less than Date2.\n";
	else
		cout << "\nNo, Date1 isn't less than Date2.\n";


	return 0;
}
