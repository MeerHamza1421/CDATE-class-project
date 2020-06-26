#include<iostream>
#pragma once				//Add for the ease of linker which restrict linker and avoid to make instanctaneous copies of class
using namespace std;

// Defining class CDATE

class CDATE {
	// ------------------ Private members and methods ----------------------------
	int year, month, day;
	void validate();

	// Static data members

	static int daysOfmonth[13];
	static char strMonth[13][4];
	static char stringMonth[13][10];
	static CDATE minDate, maxDate;

	//------------------ Public members and methods -----------------------------
public:

	//--------------------- Declaring members ------------------------------------

	CDATE();
	CDATE(int day, int month, int year);
	CDATE(const CDATE& ctr);
	~CDATE();
	void print(int opt);
	bool isLeapyear();
	 
	//------------------------- Static Methods ----------------------------------

	static void setMindate(int day,int month,int year);
	static void setMaxdate(int day,int month,int year);
	// -------------------Setters Functions ------------------------

	CDATE& readfromKB();  //   make referance return type to enable cascading in these functions 
	CDATE& setday(int day);
	CDATE& setMonth(int month);
	CDATE& setYear(int year);
	CDATE& setDate(int day, int month, int year);

	//------------------- Getter Functions ---------------------------

	int getMonth();
	int getYear();
	int getDay();
};

// Initializing static data members

int CDATE::daysOfmonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

char CDATE::strMonth[13][4] = { {""},{"Jan"},{"Feb"},{"Mar"},{"Apr"},{"May"},{"Jun"},{"Jul"},{"Aug"},{"Sep"},{"Oct"},{"Nov"},{"Dec"} };

char CDATE::stringMonth[13][10] = { {""},{"January"},{"February"},{"March"},{"April"},{"May"},
									{"June"},{"July"},{"August"},{"September"},{"October"},{"November"},{"December"} };

// ------------------------------- Defining members functons of class ----------------------------------

void CDATE::validate()    // validate functions to validate data given by user to avoid unexpected results 
{
	if (this->month < 1 || this->month>12)
	{
		cerr << "\nyou type wrong input months range from 1 to 12\n";
		this->month = -1;
	}

	if (this->year < 1900 || this->year>2020)
	{
		cerr << "\nYear out of range the year should be between 1900 to 2020\n";
		this->year = -1;
	}

	if (isLeapyear())
	{
		CDATE::daysOfmonth[2] = 29;
	}
	else
	{
		CDATE::daysOfmonth[2] = 28;
	}

	//Due to this functionality days and month related to each other if you give wrong value of month it also store -1 as a value in days
	// but if you give wrong value of days if will not affect the value of months 
	
	if (this->day < 1 || this->day > CDATE :: daysOfmonth[this->month] )  
	{
		cerr << "\nyou type wrong input, days range from 1 to " << CDATE::daysOfmonth[this->month] << "\n";
		this->day = -1;
	}
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

/*void CDATE::setMindate(int day,int month,int year)
{
	if ((day > 1 && day < 10) && (month > 1 && month > 12) && (year > 2000 && year < 2010))
	{
		CDATE::minDate.CDATE::setDate(day, month, year);
	}
}
*/
/*void CDATE::setMaxdate(int day, int month, int year)
{

}*/
