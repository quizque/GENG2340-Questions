/*

///
///
/// GradeBook.h
/// 
/// 

#pragma once

// Fig. 3.11: GradeBook.h 
// GradeBook class definition. This file presents GradeBook's public  
// interface without revealing the implementations of GradeBook's member 
// functions, which are defined in GradeBook.cpp. 
#include <string> // class GradeBook uses C++ standard string class 

// GradeBook class definition 
class GradeBook
{
public:
	explicit GradeBook(std::string, std::string); // constructor initialize courseName 

	void displayMessage() const; // displays a welcome message 

	void setCourseName(std::string); // sets the course name 
	std::string getCourseName() const; // gets the course name 

	void setInstructor(std::string); // sets the course name 
	std::string getInstructor() const; // gets the course name 

private:
	std::string courseName; // course name for this GradeBook 
	std::string instructorName; // instructorName
}; // end class GradeBo

///
///
/// GradeBook.cpp
/// 
/// 

// Fig. 3.12: GradeBook.cpp 
// GradeBook member-function definitions. This file contains 
// implementations of the member functions prototyped in GradeBook.h. 
#include <iostream> 
#include "GradeBook.h" // include definition of class GradeBook 
using namespace std;

// constructor initializes courseName with string supplied as argument 
GradeBook::GradeBook(string _courseName, string _instructorName)
    : courseName(_courseName), // member initializer to initialize courseName  
    instructorName(_instructorName) // member initalizer to initialize instructorName
{
    // empty body 
} // end GradeBook constructor 

// function to set the course name 
void GradeBook::setCourseName(string name)
{
    courseName = name; // store the course name in the object 
} // end function setCourseName 

// function to get the course name 
string GradeBook::getCourseName() const
{
    return courseName; // return object's courseName 
} // end function getCourseName 

void GradeBook::setInstructor(string name)
{
    instructorName = name;
}

std::string GradeBook::getInstructor() const
{
    return instructorName;
}

// display a welcome message to the GradeBook user 
void GradeBook::displayMessage() const
{
    // call getCourseName to get the courseName 
    cout << "Welcome to the grade book for " << getCourseName()
        << "!" << endl;
    cout << "This course is presented by: " << getInstructor()
        << "!" << endl;
} // end function displayMessage


///
///
/// Source.cpp
/// 
/// 


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


*/