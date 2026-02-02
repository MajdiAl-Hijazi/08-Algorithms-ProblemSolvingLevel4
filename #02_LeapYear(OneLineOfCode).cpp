#include<iostream>
using namespace std;

short ReadYear() {

	short Year = 0;
	cout << "Enter Number :\n";
	cin >> Year;
	return Year;
}

bool IsLeapYear(short Year) {

	return (Year % 400 == 0) ? true : ((Year % 4 == 0 && Year % 100 != 0) ? true : false);
}

void CheckLeapYear(short Year) {

	(IsLeapYear(Year)) ? (cout << "Yes, Leap Year.\n") : (cout << "No, Not Leap Year.\n");
}

int main() {

	short Year = ReadYear();
	CheckLeapYear(Year);

	return 0;
}
