///
///
/// Time.h 
/// 
/// 

//#pragma once


// Time class definition 
class Time
{
public:
	explicit Time(int = 0, int = 0, int = 0); // default constructor 

	void tick();

	// set functions 
	void setTime(int, int, int); // set hour, minute, second 
	void setHour(int); // set hour (after validation) 
	void setMinute(int); // set minute (after validation) 
	void setSecond(int); // set second (after validation) 


	// get functions 
	unsigned int getHour() const; // return hour 
	unsigned int getMinute() const; // return minute 
	unsigned int getSecond() const; // return second 


	void printUniversal() const; // output time in universal-time format 
	void printStandard() const; // output time in standard-time format 
private:
	unsigned int hour; // 0 - 23 (24-hour clock format) 
	unsigned int minute; // 0 - 59 
	unsigned int second; // 0 - 59 
}; // end class Time




///
///
/// Time.cpp 
/// 
/// 

//#include "Time.h"

// Fig. 17.5: Time.cpp 
// Member-function definitions for class Time. 
#include <iostream> 
#include <iomanip> 
#include <stdexcept> 
//#include "Time.h" // include definition of class Time from Time.h 
using namespace std;

// Time constructor initializes each data member  
Time::Time(int hour, int minute, int second)
{
    setTime(hour, minute, second); // validate and set time 
} // end Time constructor 

void Time::tick()
{
	// Increment seconds
    second++;
	// If seconds is greater then 60, increment minutes
    minute += second / 60;
	// If minutes is greater then 60, increment hours
    hour += minute / 60;

	// Loop all values between 0 -> 59 and 0 -> 23
    second %= 60;
    minute %= 60;
    hour %= 24;
}


// set new Time value using universal time 
void Time::setTime(int h, int m, int s)
{
    setHour(h); // set private field hour 
    setMinute(m); // set private field minute 
    setSecond(s); // set private field second 
} // end function setTime 

// set hour value 
void Time::setHour(int h)
{
    if (h >= 0 && h < 24)
        hour = h;
    else
        throw invalid_argument("hour must be 0-23");
} // end function setHour 

// set minute value 

void Time::setMinute(int m)
{
    if (m >= 0 && m < 60)
        minute = m;
    else
        throw invalid_argument("minute must be 0-59");
} // end function setMinute 


// set second value 

void Time::setSecond(int s)
{
    if (s >= 0 && s < 60)
        second = s;
    else
        throw invalid_argument("second must be 0-59");
} // end function setSecond 


// return hour value 
unsigned int Time::getHour() const
{
    return hour;
} // end function getHour 


// return minute value 
unsigned int Time::getMinute() const
{
    return minute;
} // end function getMinute 

// return second value 
unsigned int Time::getSecond() const
{
    return second;
} // end function getSecond 

// print Time in universal-time format (HH:MM:SS) 
void Time::printUniversal() const
{
    cout << setfill('0') << setw(2) << getHour() << ":"
        << setw(2) << getMinute() << ":" << setw(2) << getSecond();
} // end function printUniversal 


// print Time in standard-time format (HH:MM:SS AM or PM) 
void Time::printStandard() const
{
    cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
        << ":" << setfill('0') << setw(2) << getMinute()
        << ":" << setw(2) << getSecond() << (hour < 12 ? " AM" : " PM");
} // end function printStandard

///
///
/// Source.cpp 
/// 
/// 


// Name: -----	ID: -----

// ************************ PART 5 ************************

// Modify the Time class of Figs. 17.4–17.5 to include a tick member function that increments the time stored in a Time object by one second. Write a program that tests the tick member function in a loop that prints the time in standard format during each iteration of the loop to illustrate that the tick member function works correctly. Be sure to test the following cases:

// a) Incrementing into the next minute.

// b) Incrementing into the next hour.

// c) Incrementing into the next day(i.e., 11:59 : 59 PM to 12 : 00 : 00 AM).


#include <iostream>
//#include "Time.h"


// Program entry function
int main(void)
{

	// Print the title of the project (optional)
	std::cout << "-----------====== Enchanced Time Class Demo ======-----------" << std::endl;

	Time time = Time();

	std::cout << "The program DOES NOT print out every tick as requested by the GA.\nThe program will only print out the end result of running tick an x amount of times.\nUncomment the lines in the for loops below to enable outputing every tick." << std::endl;
	std::cout << "Current time: ";
	time.printStandard();
	std::cout << std::endl;

	std::cout << "Running for 60 seconds..." << std::endl;
	for (int i = 0; i != 60; i++)
	{
		time.tick();
		//time.printStandard();
		//std::cout << std::endl;
	}
	std::cout << "Current time: ";
	time.printStandard();
	std::cout << std::endl;

	std::cout << "Running for 1 hour..." << std::endl;
	// 1 hour == 60 seconds/minute * 60 minutes = 3600
	for (int i = 0; i != 3600; i++)
	{
		time.tick();
		//time.printStandard();
		//std::cout << std::endl;
	}
	std::cout << "Current time: ";
	time.printStandard();
	std::cout << std::endl;

	std::cout << "Running for 1 day..." << std::endl;
	// 1 day (12 hours?) == 3600 seconds/hour * 24 = 86400
	// The -61 - 3600 is to offset for the mods above we did above
	for (int i = 0; i != 86400 - 61 - 3600; i++)
	{
		time.tick();
		//time.printStandard();
		//std::cout << std::endl;
	}
	std::cout << "Current time: ";
	time.printStandard();
	std::cout << std::endl;

} // End entry function