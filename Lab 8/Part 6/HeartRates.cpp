#include "HeartRates.h"

#include <iostream>

HeartRates::HeartRates(std::string _first_name, std::string _last_name, int _month, int _day, int _year)
	: first_name(_first_name),
	  last_name(_last_name),
	  month(_month),
	  day(_day),
	  year(_year)
{
}

int HeartRates::getAge()
{
	// If age is already set to a value, return age
	if (age != -1)
	{
		return age;
	}

	// Otherwise, prompt and calculate the users age

	std::cout << "Enter the current month (as a number): ";
	int current_month;
	std::cin >> current_month;

	std::cout << "Enter the current day (as a number): ";
	int current_day;
	std::cin >> current_day;

	std::cout << "Enter the current year (as a number): ";
	int current_year;
	std::cin >> current_year;

	// Get the difference between the current year and the birthday year
	age = current_year - year;

	// If the month is greater then birthay month, return age
	if (current_month > month)
	{
		return age;
	}

	// If the day is greater then birthay day, return age
	if (current_day > day)
	{
		return age;
	}
	
	// Otherwise, return age minus one
	return --age;
}

int HeartRates::getMaximumHeartRate()
{
	// Maximum heart rate formula
	return 220 - age;
}

int HeartRates::getTargetHeartRate()
{
	// Target heart rate formula
	// Floor the value it returns
	return (int)((float)getMaximumHeartRate() * 0.675);
}

std::string HeartRates::getFirstName()
{
	return first_name;
}

void HeartRates::setFirstName(std::string _first_name)
{
	first_name = _first_name;
}

std::string HeartRates::getLastName()
{
	return last_name;
}

void HeartRates::setLastName(std::string _last_name)
{
	last_name = _last_name;
}

int HeartRates::getBirthdayMonth()
{
	return month;
}

void HeartRates::setBirthdayMonth(int _month)
{
	month = _month;
}

int HeartRates::getBirthdayDay()
{
	return day;
}

void HeartRates::setBirthdayDay(int _day)
{
	day = _day;
}

int HeartRates::getBirthdayYear()
{
	return year;
}

void HeartRates::setBirthdayYear(int _year)
{
	year = _year;
}
