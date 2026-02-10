#include<iostream>
#include "DateLib.h"
using namespace std;

int main() {

	cout << "Enter Period 1:" << endl;
	stPeriod Period1 = PeriodFun::ReadPeriod();

	cout << "\nEnter Period 2:" << endl;
	stPeriod Period2 = PeriodFun::ReadPeriod();

	return 0;
}