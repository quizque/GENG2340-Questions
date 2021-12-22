/*

#include <iostream>
#include "Complex.h"

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

*/