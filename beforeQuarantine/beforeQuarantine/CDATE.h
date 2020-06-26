#include<iostream>
#pragma once				//Add for the ease of linker which restrict linker and avoid to make instanctaneous copies of class
using namespace std;

// Defining class CDATE

class CDATE {
	// ------------------ Private members and methods ----------------------------
	int year, month, day;
	void validate();
	//------------------ Public members and methods -----------------------------
public:

	//--------------------- Declaring members ------------------------------------

	CDATE();
	CDATE(int day, int month, int year);
	CDATE(const CDATE& ctr);
	~CDATE();
	void print();
	bool isLeapyear();

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
		if (this->month == 2)
		{
			if (this->day < 1 || this->day>29)
			{
				cerr << "\nyou type wrong input day of febuary range from 1 to 29(Leap Year) \n";
				this->day = -1;
			}
		}
		else if (this->month == 1 || this->month == 3 || this->month == 7
			|| this->month == 10 || this->month == 12)
		{
			if (this->day < 1 || this->day>31)
			{
				cerr << "\nyou type wrong input, days range from 1 to 31\n";
				this->day = -1;
			}
		}
		else
		{
			if (this->day < 1 || this->day > 30)
			{
				cerr << "\nyou type wrong input, days range from 1 to 30\n";
				this->day = -1;
			}
		}
	}
	else
	{
		if (this->month == 2)
		{
			if (this->day < 1 || this->day > 28)
			{
				cerr << "\nyou type wrong input, days of febuary range from 0 to 28(nonleapyear) \n";
				this->day = -1;
			}
		}
		else if (this->month == 1 || this->month == 3 || this->month == 7
			|| this->month == 10 || this->month == 12)
		{
			if (this->day < 1 || this->day>31)
			{
				cerr << "\nyou type wrong input, days range from 0 to 31\n";
				this->day = -1;
			}
		}
		else
		{
			if (this->day < 1 || this->day>30)
			{
				cerr << "\nyou type wrong input, days range from 0 to 30\n";
				this->day = -1;
			}
		}
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

void CDATE::print() //Print function to display values on console 
{
	cout << endl<<this->day << "  -  " << this->month << "  -  " << this->year<<endl<<endl;
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
	 this->day= day ;
	 this->month= month;
	 this->year= year;
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


