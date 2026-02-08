#pragma once

#pragma warning(disable : 4996)

#include <ctime>
#include<iostream>
using namespace std;

struct stDate {

    short Year;
    short Month;
    short Day;
};

//Declaration
namespace IncreaseDate {

    stDate IncreaseDateByOneDay(stDate Date);
};

namespace ReadDate {

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

    stDate ReadFullDate() {

        stDate Date;
        Date.Day = ReadDay();
        Date.Month = ReadMonth();
        Date.Year = ReadYear();
        return Date;
    }
}

namespace DateFun {

    short DayOfWeekOrder(short Day, short Month, short Year) {

        short a, y, m;
        a = (14 - Month) / 12;
        y = Year - a;
        m = Month + (12 * a) - 2;

        return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }

    void SwapDate(stDate& Date1, stDate& Date2) {

        stDate Temp;

        Temp.Day = Date1.Day;
        Temp.Month = Date1.Month;
        Temp.Year = Date1.Year;

        Date1.Day = Date2.Day;
        Date1.Month = Date2.Month;
        Date1.Year = Date2.Year;

        Date2.Day = Temp.Day;
        Date2.Month = Temp.Month;
        Date2.Year = Temp.Year;
    }

    bool IsLeapYear(short Year) {

        return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
    }

    bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {

        return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
    }

    short NumberOfDaysInAMonth(short Month, short Year) {

        if (Month < 1 || Month > 12)
            return 0;

        int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

        return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : days[Month - 1];
    }

    bool IsLastDayInMonth(stDate Date) {

        return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
    }

    bool IsLastMonthInYear(short Month) {

        return (Month == 12);
    }

    int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false) {

        int Days = 0;
        short SwapFlagValue = 1;

        if (!IsDate1BeforeDate2(Date1, Date2)) {

            SwapDate(Date1, Date2);
            SwapFlagValue = -1;
        }

        while (IsDate1BeforeDate2(Date1, Date2)) {

            Days++;
            Date1 = IncreaseDate::IncreaseDateByOneDay(Date1);
        }

        return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
    }

    stDate GetSystemDate() {

        time_t t = time(0);
        tm* now = localtime(&t);

        stDate Date;
        Date.Day = now->tm_mday;
        Date.Month = now->tm_mon + 1;
        Date.Year = now->tm_year + 1900;

        return Date;
    }
}

namespace IncreaseDate {

    stDate IncreaseDateByOneDay(stDate Date) {

        if (DateFun::IsLastDayInMonth(Date))
        {
            if (DateFun::IsLastMonthInYear(Date.Month))
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

    stDate IncreaseDateByXDays(stDate Date, int Days) {

        for (int i = 1; i <= Days; i++)
            Date = IncreaseDateByOneDay(Date);

        return Date;
    }

    stDate IncreaseDateByOneWeek(stDate Date) {

        for (short i = 1; i <= 7; i++)
            Date = IncreaseDateByOneDay(Date);

        return Date;
    }

    stDate IncreaseDateByXWeek(stDate Date, int Weeks) {

        for (int i = 1; i <= Weeks; i++)
            Date = IncreaseDateByOneWeek(Date);

        return Date;
    }

    stDate IncreaseDateByOneMonth(stDate Date) {

        if (DateFun::IsLastMonthInYear(Date.Month)) {

            Date.Year++;
            Date.Month = 1;
        }
        else
            Date.Month++;

        short NumOfDaysInMonth = DateFun::NumberOfDaysInAMonth(Date.Month, Date.Year);

        // this if statment is very important!!!!!
        if (Date.Day > NumOfDaysInMonth)
            Date.Day = NumOfDaysInMonth;

        return Date;
    }

    stDate IncreaseDateByXMonth(stDate Date, int Months) {

        for (int i = 1; i <= Months; i++)
            Date = IncreaseDateByOneMonth(Date);

        return Date;
    }

    stDate IncreaseDateByOneYear(stDate Date) {

        Date.Year++;
        return Date;
    }

    stDate IncreaseDateByXYear(stDate Date, int Years) {

        for (int i = 1; i <= Years; i++)
            Date = IncreaseDateByOneYear(Date);

        return Date;
    }

    stDate IncreaseDateByXYearFaster(stDate Date, int Years) {

        Date.Year += Years;
        return Date;
    }

    stDate IncreaseDateByOneDecade(stDate Date) {

        Date.Year += 10;
        // Date = IncreaseDateByXYearFaster(Date, 10);
        //IncreaseDateByXYear(Date, 10);
        return Date;
    }

    stDate IncreaseDateByXDecade(stDate Date, int Decades) {

        for (int i = 1; i <= Decades; i++)
            Date = IncreaseDateByOneDecade(Date);

        return Date;
    }

    stDate IncreaseDateByXDecadeFaster(stDate Date, int Decades) {

        Date.Year += (10 * Decades);
        return Date;
    }

    stDate IncreaseDateByOneCentury(stDate Date) {

        Date.Year += 100;
        return Date;
    }

    stDate IncreaseDateByOneMillennium(stDate Date) {

        Date.Year += 1000;
        return Date;
    }
}

namespace DecreaseDate {

    stDate DecreaseDateByOneDay(stDate Date) {

        if (Date.Day == 1) {

            if (Date.Month == 1) {

                Date.Year--;
                Date.Month = 12;
                Date.Day = 31;
            }
            else {

                Date.Month--;
                Date.Day = DateFun::NumberOfDaysInAMonth(Date.Month, Date.Year);
            }
        }
        else {

            Date.Day--;
        }

        return Date;
    }

    stDate DecreaseDateByXDays(stDate Date, int Days) {

        for (int i = 1; i <= Days; i++)
            Date = DecreaseDateByOneDay(Date);

        return Date;
    }

    stDate DecreaseDateByOneWeek(stDate Date) {

        for (short i = 1; i <= 7; i++)
            Date = DecreaseDateByOneDay(Date);

        return Date;
    }

    stDate DecreaseDateByXWeeks(stDate Date, int Weeks) {

        for (int i = 1; i <= Weeks; i++)
            Date = DecreaseDateByOneWeek(Date);

        return Date;
    }

    stDate DecreaseDateByOneMonth(stDate Date) {

        if (Date.Month == 1) {

            Date.Year--;
            Date.Month = 12;
        }
        else {

            Date.Month--;
        }

        short NumOfDaysInCurrentMonth = DateFun::NumberOfDaysInAMonth(Date.Month, Date.Year);

        //this is important : 
        if (Date.Day > NumOfDaysInCurrentMonth)
            Date.Day = NumOfDaysInCurrentMonth;

        return Date;
    }

    stDate DecreaseDateByXMonths(stDate Date, int Months) {

        for (int i = 1; i <= Months; i++)
            Date = DecreaseDateByOneMonth(Date);

        return Date;
    }

    stDate DecreaseDateByOneYear(stDate Date) {

        Date.Year--;
        return Date;
    }

    stDate DecreaseDateByXYear(stDate Date, int Years) {

        for (int i = 1; i <= Years; i++)
            Date = DecreaseDateByOneYear(Date);

        return Date;
    }

    stDate DecreaseDateByXYearFaster(stDate Date, int Years) {

        Date.Year -= Years;
        return Date;
    }

    stDate DecreaseDateByOneDecade(stDate Date) {

        Date.Year -= 10;

        /*

        or :
        for (short i = 1; i <= 10; i++)
            Date = DecreaseDateByOneYear(Date);

        */

        return Date;
    }

    stDate DecreaseDateByXDecades(stDate Date, int Decades) {

        for (int i = 1; i <= Decades; i++)
            Date = DecreaseDateByOneDecade(Date);

        return Date;
    }

    stDate DecreaseDateByXDecadesFaster(stDate Date, int Decades) {

        Date.Year -= Decades * 10;
        return Date;
    }

    stDate DecreaseDateByOneCentury(stDate Date) {

        Date.Year -= 100;
        return Date;
    }

    stDate DecreaseDateByOneMillennium(stDate Date) {

        Date.Year -= 1000;
        return Date;
    }
}