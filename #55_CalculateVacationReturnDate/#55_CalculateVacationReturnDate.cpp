#include<iostream>
#include "DateLib.h"
using namespace std;

short ReadNum(string Message) {

	short Num;
	cout << Message;
	cin >> Num;
	return Num;
}

int main() {

	stDate Date = ReadDate::ReadFullDate();
	cout << "\n";
	short VacationDays = ReadNum("Please enter vacation days ? ");
	Date = DateFun::CalculateVacationDate(Date, 23);
	cout << "\nReturn Date : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	return 0;
}