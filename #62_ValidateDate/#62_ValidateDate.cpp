#include<iostream>
#include "DateLib.h"
using namespace std;

int main() {

	stDate Date = ReadDate::ReadFullDate();

	if (DateFun::IsValidateDate(Date))
		cout << "\nYes, Date is a validate date.";
	else
		cout << "\nNo, Date is not a validate date.";

	return 0;
}