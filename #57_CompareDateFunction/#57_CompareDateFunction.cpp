#include<iostream>
#include "DateLib.h"
using namespace std;

int main() {

	cout << "Enter Date1 :";
	stDate Date1 = ReadDate::ReadFullDate();

	cout << "\nEnter Date2 :";
	stDate Date2 = ReadDate::ReadFullDate();

	cout << "Compare Result = " << DateFun::CompareDate(Date1, Date2) << endl;

	return 0;
}