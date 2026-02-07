#include<iostream>
#include "DateLib.h";
using namespace std;

int main() {

	stDate Date = ReadDate::ReadFullDate();
	cout << "\n\nDate After : \n\n";

	Date = DecreaseDate::DecreaseDateByOneDay(Date);
	cout << "01-Subtracting One Day is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDate::DecreaseDateByXDays(Date, 10);
	cout << "02-Subtracting 10 Days is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDate::DecreaseDateByOneWeek(Date);
	cout << "03-Subtracting One Week is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDate::DecreaseDateByXWeeks(Date, 10);
	cout << "04-Subtracting 10 Weeks is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDate::DecreaseDateByOneMonth(Date);
	cout << "05-Subtracting One Month is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDate::DecreaseDateByXMonths(Date, 5);
	cout << "06-Subtracting 5 Months is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDate::DecreaseDateByOneYear(Date);
	cout << "07-Subtracting One Year is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDate::DecreaseDateByXYear(Date, 10);
	cout << "08-Subtracting 10 Years is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDate::DecreaseDateByXYearFaster(Date, 10);
	cout << "09-Subtracting 10 Years (faster) is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDate::DecreaseDateByOneDecade(Date);
	cout << "10-Subtracting One Decade is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDate::DecreaseDateByXDecades(Date, 10);
	cout << "11-Subtracting 10 Decades is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDate::DecreaseDateByXDecadesFaster(Date, 10);
	cout << "12-Subtracting 10 Decades (faster) is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDate::DecreaseDateByOneCentury(Date);
	cout << "13-Subtracting One Century is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDate::DecreaseDateByOneMillennium(Date);
	cout << "14-Subtracting One Millennuim is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	return 0;
}