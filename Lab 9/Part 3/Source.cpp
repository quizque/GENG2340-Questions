/*

// Name: -----	ID: -----

// ************************ PART 3 ************************

// (Rectangle Class) Create a class Rectangle with attributes length and width, each of which defaults to 1. Provide member functions that calculate the perimeter and the area of the rectangle. Also, provide set and get functions for the length and width attributes. The set functions should verify that length and width are each floating-point numbers larger than 0.0 and less than 20.0.


#include <iostream>
#include "Rectangle.h"


// Program entry function
int main(void)
{

	// Print the title of the project (optional)
	std::cout << "-----------====== Rectangle Class Demo ======-----------" << std::endl;

	// Run test 1
	std::cout << "Defining rect1 with no initializers (should be 1x1)" << std::endl;
	Rectangle rect1 = Rectangle();
	std::cout << "Rect1 size: " << rect1.getLength() << "x" << rect1.getWidth() << std::endl;
	std::cout << "Rect1 area: " << rect1.area() << std::endl;
	std::cout << "Rect1 perimeter area: " << rect1.perimeter() << std::endl;

	// Run test 1.5
	std::cout << "Seting rect1 width and height to 15x10" << std::endl;
	rect1.setLength(15);
	rect1.setWidth(10);
	std::cout << "Rect1 size: " << rect1.getLength() << "x" << rect1.getWidth() << std::endl;
	std::cout << "Rect1 area: " << rect1.area() << std::endl;
	std::cout << "Rect1 perimeter area: " << rect1.perimeter() << std::endl;

	// Run test 2
	std::cout << "Defining rect2 with invalid initializers (should be 1x1)" << std::endl;
	Rectangle rect2 = Rectangle(30, 30);
	std::cout << "Rect2 size: " << rect1.getLength() << "x" << rect2.getWidth() << std::endl;
	std::cout << "Rect2 area: " << rect1.area() << std::endl;
	std::cout << "Rect2 perimeter area: " << rect1.perimeter() << std::endl;

	// Run test 3
	std::cout << "Defining rect3 with size 3x19" << std::endl;
	Rectangle rect3 = Rectangle(3, 19);
	std::cout << "Rect1 size: " << rect3.getLength() << "x" << rect3.getWidth() << std::endl;
	std::cout << "Rect1 area: " << rect3.area() << std::endl;
	std::cout << "Rect1 perimeter area: " << rect3.perimeter() << std::endl;



} // End entry function

*/