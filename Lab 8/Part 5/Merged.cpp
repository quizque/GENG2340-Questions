/*

///
///
/// Date.h
/// 
/// 

#pragma once
class Date
{
public:
	explicit Date(int _month, int _day, int _year);

	void displayDate();

	// Getters and Setters

	int getMonth();
	void setMonth(int _month);

	int getDay();
	void setDay(int _day);

	int getYear();
	void setYear(int _year);

private:
	int month;
	int day;
	int year;
};


///
///
/// Date.cpp
/// 
/// 

#include "Date.h"

#include <iostream>

Date::Date(int _month, int _day, int _year)
	: day(_day),
	year(_year)
{
	setMonth(_month);
}

void Date::displayDate()
{
	std::cout << month << "/" << day << "/" << year << std::endl;
}

int Date::getMonth()
{
	return month;
}

void Date::setMonth(int _month)
{
	month = _month;
	if (!(1 <= month && month <= 12))
	{
		month = 1;
	}
}

int Date::getDay()
{
	return day;
}

void Date::setDay(int _day)
{
	day = _day;
}

int Date::getYear()
{
	return year;
}

void Date::setYear(int _year)
{
	year = _year;
}


///
///
/// Source.cpp
/// 
/// 


// Name: -----	ID: -----

// ************************ PART 5 ************************

// (Date Class) Create a class called Date that includes three pieces of information as data members—a month(type int), a day(type int) and a year(type int).Your class should have a constructor with three parameters that uses the parameters to initialize the three data members.For the  purpose of this exercise, assume that the values provided for the yearand day are correct, but ensure that the month value is in the range 1–12; if it isn’t, set the month to 1. Provide a set and a get function for each data member.Provide a member function displayDate that displays the month, dayand year separated by forward slashes(/ ).Write a test program that demonstrates class Date’s capabilities.



#include <iostream>
#include "Date.h"


// Program entry function
int main(void)
{

	std::cout << "-----------====== Date Class Demo ======-----------" << std::endl;

	// Run the tests on the first date
	std::cout << "\nTesting first date." << std::endl;
	std::cout << "Defining the first date with 7/23/2002." << std::endl;
	// Define date1
	Date date1 = Date(7, 23, 2002);

	std::cout << "Calling displayDate on date1: " << std::endl;
	date1.displayDate();

	std::cout << std::endl << std::endl;

	// Run the tests on the second date
	std::cout << "\nTesting second date." << std::endl;
	std::cout << "Defining the second date with 50/23/2002. (month should be set to 1)" << std::endl;
	// Define date1
	Date date2 = Date(50, 23, 2002);

	std::cout << "Calling displayDate on date2: " << std::endl;
	date2.displayDate();

	std::cout << std::endl << std::endl;
	std::cout << "Changing date1 to 30/2/2021 (should be 1/2/2021)" << std::endl;
	date1.setMonth(30);
	date1.setDay(2);
	date1.setYear(2021);

	std::cout << "Changing date2 to 10/10/1001" << std::endl;
	date2.setMonth(10);
	date2.setDay(10);
	date2.setYear(1001);

	std::cout << "Calling displayDate on date1: " << std::endl;
	date1.displayDate();
	std::cout << "Calling displayDate on date2: " << std::endl;
	date2.displayDate();

} // End entry function


*/