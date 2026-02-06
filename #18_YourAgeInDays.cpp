#pragma warning(disable : 4996)

#include <ctime>
#include<iostream>
using namespace std;

struct sDate {

    short Year;
    short Month;
    short Day;
};

short ReadDay() {

    short Day;
    cout << "\nPlease enter a Day? ";
    cin >> Day;
    return Day;
}

short ReadMonth() {

    short Month;
    cout << "Please enter a Month? ";
    cin >> Month;
    return Month;
}

short ReadYear() {

    short Year;
    cout << "Please enter a Year? ";
    cin >> Year;
    return Year;
}

sDate ReadFullDate() {

    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

bool IsLeapYear(short Year) {

    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

bool IsDate1BeforeDate2(sDate Date1, sDate Date2) {

    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

short NumberOfDaysInAMonth(short Month, short Year) {

    if (Month < 1 || Month > 12)
        return 0;

    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

bool IsLastDayInMonth(sDate Date) {

    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month) {

    return (Month == 12);
}

sDate IncreaseDateByOneDay(sDate Date) {

    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }
    return Date;
}

int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false) {

    int Days = 0;

    while (IsDate1BeforeDate2(Date1, Date2)) {

        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    return IncludeEndDay ? ++Days : Days;
}

sDate GetSystemDate() {

    time_t t = time(0);
    tm* now = localtime(&t);

    sDate Date;
    Date.Day = now->tm_mday;
    Date.Month = now->tm_mon + 1;
    Date.Year = now->tm_year + 1900;

    return Date;
}

int main() {

    sDate DateBirth = ReadFullDate();

    sDate DateToday = GetSystemDate();

    cout << "\nYour Age is : " << GetDifferenceInDays(DateBirth, DateToday) << endl;

    return 0;
}