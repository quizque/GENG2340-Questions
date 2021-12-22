///
///
/// RationalNumber.h
/// 
/// 

//#pragma once

#include <iostream>

static int gcd(int a, int b);

class RationalNumber
{
	friend RationalNumber operator+(const RationalNumber& r1, const RationalNumber& r2);
	friend RationalNumber operator-(const RationalNumber& r1, const RationalNumber& r2);
	friend RationalNumber operator*(const RationalNumber& r1, const RationalNumber& r2);
	friend RationalNumber operator/(const RationalNumber& r1, const RationalNumber& r2);

	friend bool operator==(RationalNumber& r1, RationalNumber& r2);
	friend bool operator!=(RationalNumber& r1, RationalNumber& r2);
	friend bool operator>=(RationalNumber& r1, RationalNumber& r2);
	friend bool operator<=(RationalNumber& r1, RationalNumber& r2);
	friend bool operator>(RationalNumber& r1, RationalNumber& r2);
	friend bool operator<(RationalNumber& r1, RationalNumber& r2);

	friend std::ostream& operator<<(std::ostream& os, const RationalNumber& r1);

public:
	explicit RationalNumber(int numerator, int denominator);

	void simplifiy();
	float getFloat();

private:

	int m_numerator;
	int m_denominator;

};

///
///
/// RationalNumber.cpp
/// 
/// 

//#include "RationalNumber.h"

RationalNumber::RationalNumber(int numerator, int denominator)
	: m_numerator(numerator),
	m_denominator(denominator)
{
	if (m_denominator == 0)
	{
		std::cout << "[ERROR] Denominator can't be zero! Defaulting to 1..." << std::endl;
		m_denominator = 1;
	}
	else if (m_denominator < 0)
	{
		std::cout << "[ERROR] Denominator can't be negative! Defaulting to positive..." << std::endl;
		m_denominator = -m_denominator;
	}

	simplifiy();
}


int gcd(int a, int b)
{
	int gcd = 1;

	for (int i = 1; i <= a && i <= b; i++)
	{
		if (a % i == 0 && b % i == 0)
		{
			gcd = i;
		}
	}

	return gcd;
}

void RationalNumber::simplifiy()
{
	int div = gcd(m_numerator, m_denominator);
	if (div != 1)
	{
		m_numerator /= div;
		m_denominator /= div;
	}
}

float RationalNumber::getFloat()
{
	return (float)m_numerator / (float)m_denominator;
}

RationalNumber operator+(const RationalNumber& r1, const RationalNumber& r2)
{
	return RationalNumber(r1.m_numerator * r2.m_denominator + r2.m_numerator * r1.m_denominator, r1.m_denominator * r2.m_denominator);
}

RationalNumber operator-(const RationalNumber& r1, const RationalNumber& r2)
{
	return RationalNumber(r1.m_numerator * r2.m_denominator - r2.m_numerator * r1.m_denominator, r1.m_denominator * r2.m_denominator);
}

RationalNumber operator*(const RationalNumber& r1, const RationalNumber& r2)
{
	return RationalNumber(r1.m_numerator * r2.m_numerator, r1.m_denominator * r2.m_denominator);
}

RationalNumber operator/(const RationalNumber& r1, const RationalNumber& r2)
{
	return RationalNumber(r1.m_numerator * r2.m_denominator, r1.m_denominator * r2.m_numerator);
}

bool operator==(RationalNumber& r1, RationalNumber& r2)
{
	r1.simplifiy();
	r2.simplifiy();
	return r1.m_numerator == r2.m_numerator && r1.m_denominator == r2.m_denominator;
}

bool operator!=(RationalNumber& r1, RationalNumber& r2)
{
	return !(r1 == r2);
}

bool operator>=(RationalNumber& r1, RationalNumber& r2)
{
	return r1 > r2 || r1 == r2;
}

bool operator<=(RationalNumber& r1, RationalNumber& r2)
{
	return r1 < r2 || r1 == r2;
}

bool operator>(RationalNumber& r1, RationalNumber& r2)
{
	return r1.getFloat() > r2.getFloat();
}

bool operator<(RationalNumber& r1, RationalNumber& r2)
{
	return r1.getFloat() < r2.getFloat();
}

std::ostream& operator<<(std::ostream& os, const RationalNumber& r1)
{
	if (r1.m_denominator != 1)
	{
		os << r1.m_numerator << "/" << r1.m_denominator;
	}
	else {
		os << r1.m_numerator;
	}

	return os;
}


///
///
/// Source.cpp
/// 
/// 

// Name: -----	ID: -----

// ************************ PART 3 ************************

// (RationalNumber Class) Create a class RationalNumber (fractions) with these capabilities:

// a) Create a constructor that prevents a 0 denominator in a fraction, reduces or simplifies fractions that are not in reduced form and avoids negative denominators.
// b) Overload the addition, subtraction, multiplicationand division operators for this class.
// c) Overload the relationaland equality operators for this class.A sample output shown in the following figure.


//#include <iostream>

//#include "RationalNumber.h"


// Program entry function
int main(void)
{

	// Print the title of the project (optional)
	std::cout << "-----------====== RationalNumber Class ======-----------" << std::endl;

	RationalNumber r1 = RationalNumber(7, 3);
	RationalNumber r2 = RationalNumber(1, 3);

	std::cout << r1 << " + " << r2 << " = " << r1 + r2 << std::endl;

	r1 = RationalNumber(7, 3);
	r2 = RationalNumber(1, 3);

	std::cout << r1 << " - " << r2 << " = " << r1 - r2 << std::endl;

	r1 = RationalNumber(7, 3);
	r2 = RationalNumber(1, 3);

	std::cout << r1 << " * " << r2 << " = " << r1 * r2 << std::endl;

	r1 = RationalNumber(7, 3);
	r2 = RationalNumber(1, 3);

	std::cout << r1 << " / " << r2 << " = " << r1 / r2 << std::endl;

	r1 = RationalNumber(7, 3);
	r2 = RationalNumber(1, 3);

	std::cout << r1 << " is:" << std::endl;

	std::cout << r1 << " > " << r2 << " => " << (int)(r1 > r2) << std::endl;
	std::cout << r1 << " < " << r2 << " => " << (int)(r1 < r2) << std::endl;
	std::cout << r1 << " >= " << r2 << " => " << (int)(r1 >= r2) << std::endl;
	std::cout << r1 << " <= " << r2 << " => " << (int)(r1 <= r2) << std::endl;
	std::cout << r1 << " !=  " << r2 << " => " << (int)(r1 != r2) << std::endl;
	std::cout << r1 << " == " << r2 << " => " << (int)(r1 == r2) << std::endl;




} // End entry function
