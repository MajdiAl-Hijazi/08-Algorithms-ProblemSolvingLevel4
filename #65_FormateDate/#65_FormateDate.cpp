#include<iostream>
#include "DateLib.h"
using namespace std;

string ReadString(string Message) {

	string S1;
	cout << Message;
	cin >> Message;
	return Message;
}

int main() {

	string StringDate = ReadString("Enter Date dd/mm/yyyy ? ");
	stDate Date = DateFun::StringToDate(StringDate);

	cout << DateFun::FormateDate(Date) << endl;

	cout << "\n" << DateFun::FormateDate(Date, "dd-mm-yyyy") << endl;
	cout << "\n" << DateFun::FormateDate(Date, "yyyy-dd-mm") << endl;
	cout << "\n" << DateFun::FormateDate(Date, "dd/yyyy/mm") << endl;

	return 0;
}