#include "CDATE.h"
#include <iostream>
using namespace std;

CDATE minDate, maxDate;

int CDATE::daysOfmonth[13] = { 0, 31 , 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

char CDATE::strMonth[13][4] = { {""},{"Jan"},{"Feb"},{"Mar"},{"Apr"},{"May"},{"Jun"},{"Jul"},{"Aug"},{"Sep"},{"Oct"},{"Nov"},{"Dec"} };

char CDATE::stringMonth[13][10] = { {""},{"January"},{"February"},{"March"},{"April"},{"May"},
                                    {"June"},{"July"},{"August"},{"September"},{"October"},{"November"},{"December"} };

// ------------------------------- Defining members functions of class ----------------------------------
void CDATE::userinteracton()
{
    cout<<"\n**************************************************************************************\n\t"
          "Hello, Our valuable users You can get the date in the following formats\n"
          "*****************************************************************************************\n\n";
    cout<<"20 -  2  -  2020  "<<" to get this format press 1\n";
    cout<<"20  Feb ,  2020  "<<" to get this format press 2\n";
    cout<<"20  February ,  2020  "<<" to get this format press 3\n";
    cout<<"------------------------------------------------------------------------------------------------\n\tNote:\t You can set the data from 1 - 1 - 2000 to 31 - 12 - 2020\n------------------------------------------------------------------------------------------------\n";
    cout<<"Enter the option:\n";
    cin>>CDATE::option;
    cout<<endl;
}

void CDATE::validate()    // validate functions to validate data given by user to avoid unexpected results
{

    if (CDATE::setMaxdate(this->day, this->month, this->year) && CDATE::setMindate(this->day, this->month, this->year))
    {

        if (this->month < 1 || this->month > 12) {
            cerr << "\nyou type wrong input months range from 1 to 12\n";
            this->month = -1;
        }

        if (this->year < 1900 || this->year > 2020) {
            cerr << "\nInput may be valid Year should be in 0000 thousand format \n";
            this->year = -1;
        }

        if (isLeapyear())
            CDATE::daysOfmonth[2] = 29;

        else
            CDATE::daysOfmonth[2] = 28;

        //Due to this functionality days and month related to each other if you give wrong value of month it also store -1 as a value in days
        // but if you give wrong value of days it will not affect the value of months

        if (this->day < 1 || this->day > CDATE::daysOfmonth[this->month]) {
            cerr << "\nyou type wrong input, days range from 1 to " << CDATE::daysOfmonth[this->month] << "\n";
            this->day = -1;
        }
    }
    else
    {
        this->day=-1;
        this->month=-1;
        this->year=-1;
        cerr<<"Given date is beyond or above the specified limit the specified limit is\n"
              "From 1 - 1 -2000  to  30 - 12 - 2020 \n";
    }
}

void CDATE::print(int opt) //Print function to display values on console
{
    if (opt == 1)
        cout << endl << this->day << "  -  " << this->month << "  -  " << this->year << endl << endl;

    else if (opt == 2)
        cout << endl << this->day << "  " << this->strMonth[this->month] << "  ,  " << this->year << endl;

    else if(opt==3)
        cout << endl << this->day << "  " << this->stringMonth[this->month] << " , " << this->year << endl;

}

CDATE& CDATE::readfromKB()  //Function to get data from keyboard in runtime
{
    cout << "please enter the date\n";
    cout << "Enter the day date\n";
    cin >> this->day;

    cout << "Enter the month\n";
    cin >> this->month;

    cout << "Enter the year\n";
    cin >> this->year;
    this->validate();

    cout << "\n";
    return *this;
}

bool CDATE::isLeapyear() //Another validate type of function to check given Year is a leap year or not
{
    if (!(this->year % 4))
        return true;
    else
        return false;
}

CDATE::CDATE()   // Initializer constructor
{
    this->day = 0;
    this->month = 0;
    this->year = 0;
}

CDATE::CDATE(int day, int month, int year)  //Parameterize constructor
{
    this->year = year;
    this->month = month;
    this->day = day;
    this->validate();
}

CDATE::CDATE(const CDATE& copy) //Copy constructor to make Copies of an object
{
    this->day = copy.day;
    this->month = copy.month;
    this->year = copy.year;
}

CDATE::~CDATE()  //Destructor
{ }

CDATE& CDATE::setday(int day)  //Setter function to set value of day
{
    this->day = day;
    this->validate();
    return *this;
}

CDATE& CDATE::setMonth(int month)  //Setter function to set value of month
{
    this->month = month;
    this->validate();
    return *this;
}

CDATE& CDATE::setYear(int year)  //Setter function to set value of Year
{
    this->year = year;
    this->validate();
    return *this;
}

CDATE& CDATE::setDate(int day, int month, int year)  //Setter function to set new value of whole date
{
    this->day = day;
    this->month = month;
    this->year = year;
    this->validate();
    return *this;
}

int CDATE::getDay() //Function to get value of Day
{
    return this->day;
}

int CDATE::getMonth() //Function to get value of month
{
    return this->month;
}

int CDATE::getYear() //Function to get value of Year
{
    return this->year;
}

// ------------------------------- Defining Static Methods ----------------------------------------

bool CDATE::setMindate(int day,int month,int year)
{
    int limit_day=1;
    int limit_month=1;
    int limit_year=2000;
    minDate.day=day;
    minDate.month=month;
    minDate.year=year;
    return ((minDate.day >= limit_day) && (minDate.month >= limit_month) && (minDate.year >= limit_year));
}

bool CDATE::setMaxdate(int day, int month, int year)
{
    maxDate.day=day;
    maxDate.month=month;
    maxDate.year=year;
    int limit_day=31;
    int limit_month=12;
    int limit_year=2020;
    return ((/*maxDate.day*/maxDate.getDay() <= limit_day) && (maxDate.month <= limit_month) && (maxDate.year <= limit_year));
}
