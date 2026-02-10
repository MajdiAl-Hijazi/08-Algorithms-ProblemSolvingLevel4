#include<iostream>
#include "DateLib.h"
using namespace std;

int main() {

	string StringDate;
	cout << "Enter Date dd/mm/yy ? ";
	getline(cin >> ws, StringDate);

	stDate Date = DateFun::StringToDate(StringDate);

	cout << "\nDays : " << Date.Day << endl;
	cout << "Month : " << Date.Month << endl;
	cout << "Year : " << Date.Year << endl;
	
	cout << "\nYour Entered : " << DateFun::DateToString(Date) << endl;

	return 0;
}