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