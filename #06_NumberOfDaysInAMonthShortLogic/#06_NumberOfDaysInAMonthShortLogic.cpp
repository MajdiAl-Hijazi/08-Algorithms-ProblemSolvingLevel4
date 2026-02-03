#include<iostream>
using namespace std;

short ReadYear() {

	short Year = 0;
	cout << "Enter a yesr to check ? ";
	cin >> Year;
	return Year;
}

short ReadMonth() {

	short Mounth = 0;
	cout << "Enter a mounth to check ? ";
	cin >> Mounth;
	return Mounth;
}

bool IsLeapYear(short Year) {

	return ((Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0));
}

short NumberOfDaysInAMounth(short Month, short Year) {

	if (Month < 1 || Month > 12)
		return 0;

	short arr[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return ((Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : arr[Month - 1]);
}

int main() {

	short Year = ReadYear();
	cout << "\n";
	short Month = ReadMounth();

	cout << "\nNumber of Days in    Mounth [" << Month << "] is " << NumberOfDaysInAMounth  (Month, Year);
	cout << "\n";

	return 0;
}
