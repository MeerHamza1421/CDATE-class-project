#include<iostream>
#pragma once
using namespace std;
class CDATE {
	int year, month, day;
	void validate();
public:
	CDATE();
	CDATE(int day, int month, int year);
	CDATE(const CDATE& ctr);
	~CDATE();
	void print();
	bool isLeapyear();
	CDATE& readfromKB();
	CDATE& setday(int day);
	CDATE& setMonth(int month);
	CDATE& setYear(int year);
	CDATE& setDate(int day, int month, int year);
	int getMonth();
	int getYear();
	int getDay();
};
void CDATE::validate()
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
CDATE::CDATE()
{
	this->day = 0;
	this->month = 0;
	this->year = 0;
}
CDATE::CDATE(int day, int month, int year)
{
	this->year = year;
	this->month = month;
	this->day = day;
	this->validate();
}
void CDATE::print()
{
	cout << endl<<this->day << "/\t" << this->month << "/\t" << this->year<<endl<<endl;
}
CDATE& CDATE::readfromKB()
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
bool CDATE::isLeapyear()
{
	if (!(this->year % 4))
		return true;

	else
		return false;
}
CDATE::CDATE(const CDATE& copy)
{
	this->day = copy.day;
	this->month = copy.month;
	this->year = copy.year;
}
CDATE::~CDATE()
{ }
CDATE& CDATE::setday(int day)
{
	this->day = day;
	this->validate();
	return *this;
}
CDATE& CDATE::setMonth(int month)
{
	this->month = month;
	this->validate();
	return *this;
}
CDATE& CDATE::setYear(int year)
{
	this->year = year;
	this->validate();
	return *this;
}
CDATE& CDATE::setDate(int day, int month, int year)
{
	 this->day= day ;
	 this->month= month;
	 this->year= year;
	 this->validate();
	return *this;
}
int CDATE::getDay()
{
	return this->day;
}
int CDATE::getMonth()
{
	return this->month;
}
int CDATE::getYear()
{
	return this->year;
}
