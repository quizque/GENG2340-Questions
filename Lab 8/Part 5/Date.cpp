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
