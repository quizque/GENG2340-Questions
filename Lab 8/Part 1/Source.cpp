// Name: -----	ID: -----

// ************************ PART 1 ************************

//  (Modifying Class GradeBook) Modify class GradeBook (Figs. 3.11–3.12) as follows: 
// a) Include a second string data member that represents the course instructor’s name.
// b) Provide a set function to change the instructor’s nameand a get function to retrieve it.
// c) Modify the constructor to specify course nameand instructor name parameters.
// d) Modify function displayMessage to output the welcome messageand course name, then the string "This 
// course is presented by : " followed by the instructor’s name. Use your modified class in a test program that 
// demonstrates the class’s new capabilities.


#include <iostream>
#include "GradeBook.h"

using namespace std;

// Program entry function
int main(void)
{

	// Print the title of the project (optional)
	cout << "-----------====== GradeBook Class Demo ======-----------" << endl;

	// Initialize softwareFundimentals with the appropriate class name and instructor
	cout << "Initilzing GENG 2340 with 'Rejesh Seth' as instructor..." << endl;
	GradeBook softwareFundimentals = GradeBook("GENG2320", "Rejesh Seth");

	// Run the tests
	cout << "Initilized!" << endl;
	cout << "Testing class..." << endl << endl;

	// Get getInstructor
	cout << "Calling getInstructor: " << softwareFundimentals.getInstructor() << endl;
	cout << "Calling getCourseName: " << softwareFundimentals.getCourseName() << endl;
	cout << "Calling displayMessage:" << endl << endl;
	softwareFundimentals.displayMessage();

	// Change the course instructor and then call getInstructor
	cout << "Calling setInstructor with 'Arezoo Emadi' as parameter... " << endl;
	softwareFundimentals.setInstructor("Arezoo Emadi");
	cout << "Calling getInstructor: " << softwareFundimentals.getInstructor() << endl;

	// Change the course name and then call getCourseName
	cout << "Calling setCourseName with 'GENG2340' as parameter... " << endl;
	softwareFundimentals.setCourseName("GENG2340");
	cout << "Calling getCourseName: " << softwareFundimentals.getCourseName() << endl;

	cout << "Calling displayMessage:" << endl << endl;
	softwareFundimentals.displayMessage();

	// Tests end
	cout << endl << "Testing finished!" << endl;

} // End entry function