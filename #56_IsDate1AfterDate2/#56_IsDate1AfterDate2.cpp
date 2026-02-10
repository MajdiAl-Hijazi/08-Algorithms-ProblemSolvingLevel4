#include<iostream>
#include "DateLib.h"
using namespace std;

int main() {

	cout << "Enter Date1 :";
	stDate Date1 = ReadDate::ReadFullDate();

	cout << "\n\nEnter Date1 :";
	stDate Date2 = ReadDate::ReadFullDate();

	return 0;
}