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

