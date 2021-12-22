#pragma once

#include <string>

class HeartRates
{
public:
	explicit HeartRates(std::string _first_name, std::string _last_name, int _month, int _day, int _year);

	// Get age will only prompt the user once
	// for the current day
	int getAge();

	// Calculare maximum and target heart rate
	int getMaximumHeartRate();
	int getTargetHeartRate();

	// Getters and setters

	std::string getFirstName();
	void setFirstName(std::string _first_name);

	std::string getLastName();
	void setLastName(std::string _last_name);

	int getBirthdayMonth();
	void setBirthdayMonth(int _month);

	int getBirthdayDay();
	void setBirthdayDay(int _day);

	int getBirthdayYear();
	void setBirthdayYear(int _year);

private:
	std::string first_name;
	std::string last_name;

	// Birthday
	int month;
	int day;
	int year;

	// Age
	int age = -1;
};

