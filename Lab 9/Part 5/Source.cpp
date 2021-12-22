/*

// Name: -----	ID: -----

// ************************ PART 5 ************************

// Modify the Time class of Figs. 17.4–17.5 to include a tick member function that increments the time stored in a Time object by one second. Write a program that tests the tick member function in a loop that prints the time in standard format during each iteration of the loop to illustrate that the tick member function works correctly. Be sure to test the following cases:

// a) Incrementing into the next minute.

// b) Incrementing into the next hour.

// c) Incrementing into the next day(i.e., 11:59 : 59 PM to 12 : 00 : 00 AM).


#include <iostream>
#include "Time.h"


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

*/