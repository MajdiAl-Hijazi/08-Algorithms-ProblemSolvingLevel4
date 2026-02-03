#include<iostream>
using namespace std;

short ReadYear() {

	short Year = 0;
	cout << "Enter a year ? ";
	cin >> Year;
	return Year;
}

short ReadMonth() {

	short Month = 0;
	cout << "Enter a month ? ";
	cin >> Month;
	return Month;
}

short ReadDay() {

	short Day = 0;
	cout << "Enter a day ? ";
	cin >> Day;
	return Day;
}

short DayOfWeekOrder(short Day, short Month, short Year) {

	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;
	
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m)/ 12)) % 7;
}

string DayShortName(short DayOfWeekOrder) {

	string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
	return arrDayNames[DayOfWeekOrder];
}

int main() {

	short Year = ReadYear();
	cout << "\n";
	short Month = ReadMonth();
	cout << "\n";
	short Day = ReadDay();
	cout << "\n";

	cout << "Date      : " << Day << "/" << Month << "/" << Year << endl;;
	cout << "Day Order : " << DayOfWeekOrder(Day, Month, Year) << endl;
	cout << "Day Name : " << DayShortName(DayOfWeekOrder(Day, Month, Year)) << endl;
	

	return 0;
}