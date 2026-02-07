#include<iostream>
using namespace std;

// my new library
#include"DateLib.h";


//this struct is definition into "DateLib" library, and include -> short Year, Month, Day.
struct stDate;

int main() {

	stDate Date1 = ReadDate::ReadFullDate();
	stDate Date2 = ReadDate::ReadFullDate();

	cout << "\nDifference is : " << Date::GetDifferenceInDays(Date1, Date2) << " Day(s)" << endl;
	cout << "\nDifference (Including End Day) is : " << Date::GetDifferenceInDays(Date1, Date2, true) << " Day(s)" << endl;


	return 0;
}
