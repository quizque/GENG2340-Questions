///
///
/// Complex.h
/// 
/// 

//#pragma once
class Complex
{
public:
	explicit Complex(double real = 0, double imaginary = 1);

	void add(Complex& other);
	void subtract(Complex& other);
	void print() const;

private:

	double m_real;
	double m_imaginary;

};

///
///
/// Complex.cpp
/// 
/// 

#include <iostream>
//#include "Complex.h"

Complex::Complex(double real, double imaginary)
	: m_real(real),
	  m_imaginary(imaginary)
{
}

void Complex::add(Complex& other)
{
	// Add the two real and imaginary parts
	m_real += other.m_real;
	m_imaginary += other.m_imaginary;
}

void Complex::subtract(Complex& other)
{
	// Subtract the two real and imaginary parts
	m_real -= other.m_real;
	m_imaginary -= other.m_imaginary;
}

void Complex::print() const
{
	// Print out the complex number
	std::cout << "(" << m_real << ", " << m_imaginary << ")" << std::endl;
}

///
///
/// Source.cpp
/// 
/// 

// Name: -----	ID: -----

// ************************ PART 4 ************************

// (Complex Class) Create a class called Complex for performing arithmetic with complex numbers. Write a program to test your class. Complex numbers have the form

// realPart + imaginaryPart * i

// where i is the square root of minus one.Use double variables to represent the private data of the class.Provide a constructor that enables an object of this class to be initialized when it’s declared.The constructor should contain default values in case no  initializers are provided.Provide public member functions that perform the following tasks :



// a) Adding two Complex numbers : The real parts are added togetherand the imaginary parts are added together.

// b) Subtracting two Complex numbers : The real part of the right operand is subtracted from the real part of the left operand, and the imaginary part of the right operand is subtracted from the imaginary part of the left operand.

// c) Printing Complex numbers in the form(a, b), where a is the real partand b is the imaginary part.


#include <iostream>
//#include "Complex.h"


// Program entry function
int main(void)
{

	// Print the title of the project (optional)
	std::cout << "-----------====== Complex Class Demo ======-----------" << std::endl;

	std::cout << "Defining complex1 with no parameters (should be (0, 1))" << std::endl;
	Complex complex1 = Complex();
	std::cout << "Complex1: ";
	complex1.print();
	std::cout << std::endl;

	std::cout << "\nDefining complex2 with parameters (4, 3)" << std::endl;
	Complex complex2 = Complex(4, 3);
	std::cout << "Complex2: ";
	complex2.print();
	std::cout << std::endl;

	std::cout << "\nDefining complex3 with parameters (2, 8)" << std::endl;
	Complex complex3 = Complex(2, 8);
	std::cout << "Complex2: ";
	complex3.print();
	std::cout << std::endl;

	std::cout << "\nAdding complex1 with complex 3" << std::endl;
	complex1.add(complex3);
	std::cout << "Complex1: ";
	complex1.print();
	std::cout << std::endl;

	std::cout << "\nSubtracting complex1 with complex 2" << std::endl;
	complex1.subtract(complex2);
	std::cout << "Complex1: ";
	complex1.print();
	std::cout << std::endl;

} // End entry function