/*

#pragma once

#include <string>

class HugeInteger
{
public:
	// Constructor
	explicit HugeInteger(std::string digits, const bool is_negative);

	// Input (for defining) and output (for printing
	void input(std::string digits, const bool is_negative);
	void output() const;

	// Math functions
	void add(HugeInteger& other, bool bypass = false);
	void subtract(HugeInteger& other);

	// Comparison checks
	bool isEqualTo(const HugeInteger& other) const;
	bool isNotEqualTo(const HugeInteger& other) const;
	bool isGreaterThan(const HugeInteger& other, const bool passthrough = false) const;
	bool isLessThan(const HugeInteger& other, const bool passthrough = false) const;
	bool isGreaterThanOrEqualTo(const HugeInteger& other) const;
	bool isLessThanOrEqualTo(const HugeInteger& other) const;
	bool isZero() const;

private:
	// The digits
	int m_digits[40] = { 0 };
	// Is the number negetive
	bool m_is_negative = true;
};

*/