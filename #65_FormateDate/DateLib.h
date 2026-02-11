#pragma once

//for test only

#pragma warning(disable : 4996)

#include<iostream>
#include <ctime>
#include<vector>
#include<string>
using namespace std;

struct stDate {

    short Year;
    short Month;
    short Day;
};

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

struct stPeriod {

    stDate DateFrom;
    stDate DateTo;
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

    bool Date1IsEqualDate2(const stDate& Date1, const stDate& Date2) {

        return (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day);
    }

    string DayShortName(short DayOfWeekOrder) {

        string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
        return arrDayNames[DayOfWeekOrder];
    }

    short DayOfWeekOrder(short Day, short Month, short Year) {

        short a, y, m;
        a = (14 - Month) / 12;
        y = Year - a;
        m = Month + (12 * a) - 2;

        return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }

    //Overload
    short DayOfWeekOrder(stDate Date) {

        return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
    }

    bool IsEndOfWeek(stDate Date) {

        return (DayOfWeekOrder(Date) == 6);
    }

    bool IsWeekEnd(stDate Date) {

        short DayIndex = DayOfWeekOrder(Date);
        return (DayIndex == 5 || DayIndex == 6);
    }

    bool IsBusinessDay(stDate Date) {

        return !IsWeekEnd(Date);
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

    bool IsDate1AfterDat2(stDate Date1, stDate Date2) {

        return (!IsDate1BeforeDate2(Date1, Date2) && !Date1IsEqualDate2(Date1, Date2));
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

    short DaysUntilTheEndOfWeek(stDate Date) {

        return 6 - DayOfWeekOrder(Date);
    }

    short DaysUntilTheEndOfMonth(stDate Date1) {

        stDate Date2 = Date1;
        Date2.Day = NumberOfDaysInAMonth(Date1.Month, Date1.Year);

        return GetDifferenceInDays(Date1, Date2, true);
    }

    short DaysUntilTheEndOfYear(stDate Date1) {

        stDate Date2 = Date1;
        Date2.Day = 31;
        Date2.Month = 12;

        return GetDifferenceInDays(Date1, Date2, true);
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

    short CalculateVacationDays(stDate DateFrom, stDate DateTo) {

        short DaysCount = 0;

        while (IsDate1BeforeDate2(DateFrom, DateTo)) {

            if (IsBusinessDay(DateFrom))
                DaysCount++;

            DateFrom = IncreaseDate::IncreaseDateByOneDay(DateFrom);
        }

        return DaysCount;
    }

    stDate CalculateVacationDate(stDate DateFrom, short VacationDays) {

        short WeekEndCounter = 0;

        while (IsWeekEnd(DateFrom))
            DateFrom = IncreaseDate::IncreaseDateByOneDay(DateFrom);

        for (short i = 0; i < VacationDays + WeekEndCounter; i++) {

            if (IsWeekEnd(DateFrom))
                WeekEndCounter++;

            DateFrom = IncreaseDate::IncreaseDateByOneDay(DateFrom);
        }

        while (IsWeekEnd(DateFrom))
            DateFrom = IncreaseDate::IncreaseDateByOneDay(DateFrom);

        return DateFrom;
    }

    enDateCompare CompareDate(stDate Date1, stDate Date2) {

        if (IsDate1BeforeDate2(Date1, Date2))
            return enDateCompare::Before;

        if (Date1IsEqualDate2(Date1, Date2))
            return enDateCompare::Equal;

        return enDateCompare::After;
    }

    bool IsValidateDate(stDate Date) {

        if (Date.Day < 1 || Date.Day > 31)
            return false;

        if (Date.Month < 1 || Date.Month > 12)
            return false;

        if (Date.Month == 2) {

            if (IsLeapYear(Date.Year)) {

                if (Date.Day > 29)
                    return false;
            }
            else {

                if (Date.Day > 28)
                    return false;
            }
        }

        short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

        if (Date.Day > DaysInMonth)
            return false;

        return true;
    }

    vector<string> SplitString(string S1, string Delim) {

        vector<string> Words;
        short Pos;
        string Word = "";

        while ((Pos = S1.find(Delim)) != string::npos) {

            Word = S1.substr(0, Pos);

            if (Word != "")
                Words.push_back(Word);

            S1.erase(0, Pos + Delim.length());
        }

        if (S1 != "")
            Words.push_back(S1);

        return Words;
    }

    stDate StringToDate(string StringDate) {

        vector<string> Tokens = SplitString(StringDate, "/");
        stDate Date;

        Date.Day = stoi(Tokens.at(0));
        Date.Month = stoi(Tokens.at(1));
        Date.Year = stoi(Tokens.at(2));

        return Date;
    }

    string DateToString(stDate Date) {

        return  to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
    }

    string ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo) {

        short pos = S1.find(StringToReplace);

        while (pos != std::string::npos) {

            S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);
            pos = S1.find(StringToReplace);
        }

        return S1;
    }

    string FormateDate(stDate Date, string FormateDate = "dd/mm/yyyy") {
    
        string FormatedDateString = "";
        FormatedDateString = ReplaceWordInString(FormateDate, "dd", to_string(Date.Day));
        FormatedDateString = ReplaceWordInString(FormatedDateString, "mm", to_string(Date.Month));
        FormatedDateString = ReplaceWordInString(FormatedDateString, "yyyy", to_string(Date.Year));

        return FormatedDateString;
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

namespace PeriodFun {

    stPeriod ReadPeriod() {

        stPeriod Period;

        cout << "Enter Start Date :\n";
        Period.DateFrom = ReadDate::ReadFullDate();

        cout << "\nEnter End Date :\n";
        Period.DateTo = ReadDate::ReadFullDate();

        return Period;
    }

    bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2) {

        if (DateFun::CompareDate(Period2.DateTo, Period1.DateFrom) == enDateCompare::Before
            ||
            DateFun::CompareDate(Period2.DateFrom, Period1.DateTo) == enDateCompare::After)
            return false;

        return true;
    }

    int CalculatePeriodLengthInDays(stPeriod Period, bool IncludeEnd = false) {

        return DateFun::GetDifferenceInDays(Period.DateFrom, Period.DateTo, IncludeEnd);
    }

    bool IsDateWithinPeriod(stPeriod Period, stDate Date) {

        return !(DateFun::CompareDate(Date, Period.DateFrom) == enDateCompare::Before
            ||
            DateFun::CompareDate(Date, Period.DateTo) == enDateCompare::After);
    }

    int CountOverlapDays(stPeriod Period1, stPeriod Period2) {

        int Period1Length = CalculatePeriodLengthInDays(Period1, true);
        int Period2Length = CalculatePeriodLengthInDays(Period2, true);
        int OverlapDays = 0;

        if (!IsOverlapPeriods(Period1, Period2))
            return 0;

        if (Period1Length < Period2Length) {

            while (DateFun::IsDate1BeforeDate2(Period1.DateFrom, Period1.DateTo)) {

                if (IsDateWithinPeriod(Period2, Period1.DateFrom))
                    OverlapDays++;

                Period1.DateFrom = IncreaseDate::IncreaseDateByOneDay(Period1.DateFrom);
            }
        }
        else {

            while (DateFun::IsDate1BeforeDate2(Period2.DateFrom, Period2.DateTo)) {

                if (IsDateWithinPeriod(Period1, Period2.DateFrom))
                    OverlapDays++;

                Period2.DateFrom = IncreaseDate::IncreaseDateByOneDay(Period2.DateFrom);
            }
        }

        return OverlapDays;
    }
}