/*

#pragma once

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

*/