#include<iostream>
using namespace std;

short ReadYear() {

	short Year = 0;
	cout << "Enter a yesr to check ? ";
	cin >> Year;
	return Year;
}

short ReadMounth() {

	short Mounth = 0;
	cout << "Enter a mounth to check ? ";
	cin >> Mounth;
	return Mounth;
}

bool IsLeapYear(short Year) {

	return ((Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0));
}

short NumberOfDaysInAMounth(short Mounth, short Year) {

	if (Mounth < 1 || Mounth > 12)
		return 0;
	if (Mounth == 2)
		return ((IsLeapYear(Year)) ? 29 : 28);

	short arr[7] = { 1, 3, 5, 7, 8, 10, 12 };
	
	for (short i = 1; i <= 7; i++) {
	
		if (arr[i - 1] == Mounth)
			return 31;
	}

	return 30;
}

short NumberOfHoursInAMounth(short Month, short Year) {

	return (NumberOfDaysInAMounth(Month, Year) * 24);
}

int NumberOfMinuteInAMounth(short Month, short Year) {

	return (NumberOfHoursInAMounth(Month, Year) * 60);
}

int NumberOfSecondInAMounth(short Month, short Year) {

	return (NumberOfMinuteInAMounth(Month, Year) * 60);
}

int main() {

	short Year = ReadYear();
	cout << "\n";
	short Month = ReadMounth();

	cout << "\nNumber of Days in    Mounth [" << Month << "] is " << NumberOfDaysInAMounth  (Month, Year);
	cout << "\nNumber of Hours in   Mounth [" << Month << "] is " << NumberOfHoursInAMounth (Month, Year);
	cout << "\nNumber of Minutes in Mounth [" << Month << "] is " << NumberOfMinuteInAMounth(Month, Year);
	cout << "\nNumber of Seconds in Mounth [" << Month << "] is " << NumberOfSecondInAMounth(Month, Year);
	cout << "\n";

	return 0;
}
