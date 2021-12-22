/*

#include "RationalNumber.h"

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

*/