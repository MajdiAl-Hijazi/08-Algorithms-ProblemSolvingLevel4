#include<iostream>
#include "DateLib.h";
using namespace std;

int main() {

	stDate Date = DateFun::GetSystemDate();
	cout << "Today is " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	return 0;
}