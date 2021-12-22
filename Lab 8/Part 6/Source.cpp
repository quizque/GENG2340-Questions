// Name: -----	ID: -----

// ************************ PART 6 ************************

// (Target - Heart - Rate Calculator) While exercising, you can use a heart - rate monitor to see that your heart rate stays within a safe range suggested by your trainers and doctors.According to the American Heart Association(AHA) (www.americanheart.org / presenter.jhtml ? identifier = 4736), the formula for calculating your maximum heart rate in beats per minute is 220 minus your age in years.Your target heart rate is a range that is 50–85 % of your maximum heart rate.[Note:These formulas are estimates provided by the AHA.Maximum and target heart rates may vary based on the health, fitness and gender of the individual.Always consult a physician or qualified health care professional before beginning or modifying an exercise program.] Create a class called HeartRates.The class attributes should include the person’s first name, last nameand date of birth(consisting of separate attributes for the month, dayand year of birth).Your class should have a constructor that receives this data as parameters.For each attribute provide setand get functions.The class also should include a function getAge that calculatesand returns the person’s age(in years), a function getMaxiumumHeartRate that calculatesand returns the person’s maximum heart rateand a function getTargetHeartRate that calculatesand returns the person’s target heart rate.Since you do not yet know how to obtain the current date from the computer, function getAge should prompt the user to enter the current month, dayand year before calculating the person’s age.Write an application that prompts for the person’s information, instantiates an object of class HeartRatesand prints the information from that object— including the person’s first name, last nameand date of birth—then calculatesand prints the person’s age in(years), maximum heart rateand target - heart - rate range.



#include <iostream>
#include <string>
#include "HeartRates.h"


// Program entry function
int main(void)
{

	// Print the title of the project (optional)
	std::cout << "-----------====== Heart Rate Calculate Using Classes ======-----------" << std::endl;

	// Define varibles
	std::string first_name;
	std::string last_name;

	int month;
	int day;
	int year;

	// Get user info
	std::cout << "Enter first name: ";
	std::getline(std::cin, first_name);

	std::cout << "Enter last name: ";
	std::getline(std::cin, last_name);

	std::cout << "Enter birthday month (as number): ";
	std::cin >> month;

	std::cout << "Enter birthday day (as number): ";
	std::cin >> day;

	std::cout << "Enter birthday year (as number): ";
	std::cin >> year;

	// Spacing
	std::cout << std::endl << std::endl;

	// Define heartrate
	HeartRates heart_rate = HeartRates(first_name, last_name, month, day, year);

	// Print header
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
	std::cout << "-=-=-             Info            -=-=-" << std::endl;
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;

	// Print first and last name
	std::cout << "Name: " << heart_rate.getFirstName() << " " << heart_rate.getLastName() << std::endl;

	// Print birthday
	std::cout << "Birthday: " << heart_rate.getBirthdayMonth() << "/" << heart_rate.getBirthdayDay() << "/" << heart_rate.getBirthdayYear() << std::endl;

	// Get the user age
	// Once its ran once, it doesn't need to prompt again
	heart_rate.getAge();

	// Display age, maximum heart rate, and target heart rate
	std::cout << "Age: " << heart_rate.getAge() << std::endl;
	std::cout << "Maximum Heart Rate: " << heart_rate.getMaximumHeartRate() << std::endl;
	std::cout << "Target Heart Rate (+/- 17.5%): " << heart_rate.getTargetHeartRate() << std::endl;

} // End entry function