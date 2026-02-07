#include<iostream>
#include"DateLib.h";
using namespace std;

int main() {

	stDate Date = ReadDate::ReadFullDate();

	cout << "\n\n\nDate After :\n\n\n";

	Date = IncreaseDate::IncreaseDateByOneDay(Date);
	cout << "01-Adding one day is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDate::IncreaseDateByXDays(Date, 10);
	cout << "02-Adding 10 days is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDate::IncreaseDateByOneWeek(Date);
	cout << "03-Adding one week is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDate::IncreaseDateByXWeek(Date, 10);
	cout << "04-Adding 10 week is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDate::IncreaseDateByOneMonth(Date);
	cout << "05-Adding one month is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDate::IncreaseDateByXMonth(Date, 5);
	cout << "06-Adding 5 months is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDate::IncreaseDateByOneYear(Date);
	cout << "07-Adding one year is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDate::IncreaseDateByXYear(Date, 10);
	cout << "08-Adding 10 years is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDate::IncreaseDateByXYearFaster(Date, 10);
	cout << "09-Adding 10 years (faster) is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDate::IncreaseDateByOneDecade(Date);
	cout << "10-Adding one Decade is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	
	Date = IncreaseDate::IncreaseDateByXDecade(Date, 10);
	cout << "11-Adding 10 Decades is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDate::IncreaseDateByXDecadeFaster(Date, 10);
	cout << "12-Adding 10 Decades (faster) is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDate::IncreaseDateByOneCentury(Date);
	cout << "13-Adding one century is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDate::IncreaseDateByOneMillennium(Date);
	cout << "14-Adding one Millennium is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	return 0;
}