///
///
/// HugeInteger.h
/// 
/// 

// #pragma once

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

///
///
/// HugeInteger.cpp
/// 
///

// #include "HugeInteger.h"

#include <iostream>

HugeInteger::HugeInteger(std::string digits, const bool is_negative)
{
	// Pass the parameters to the input function
	input(digits, is_negative);
}

void HugeInteger::input(std::string digits, const bool is_negative)
{
	// Get the size of the string
	int size_of_val = digits.size();

	// For every digit in the string
	for (int i = 0; i != size_of_val; i++)
	{
		// Store it in the member digits from right to left
		m_digits[39 - i] = (int)(digits[size_of_val - i - 1] - '0');
	}

	// Set if the number is negative
	m_is_negative = is_negative;
}

void HugeInteger::output() const
{
	// Used to find the first digit
	int hit = false;

	// Print wether the number is negative or positive
	if (m_is_negative && !isZero())
	{
		std::cout << "-";
	}
	else {
		std::cout << "+";
	}

	// For all the digits in the array
	for (int i = 0; i != 40; i++)
	{
		// If we havn't found the first digit
		if (!hit)
		{
			// If the digit we are checking isn't zero, then we found the first digit
			if (m_digits[i] != 0)
			{
				hit = true;
			}
			else {
				// Otherwise, skip until we find it
				continue;
			}
		}

		// Otherwise, print the digit
		std::cout << m_digits[i];
	}

	// If we never found a digit, then just print 0
	if (hit == false)
	{
		std::cout << "0";
	}

	std::cout << std::endl;
}

void HugeInteger::add(HugeInteger& other, bool bypass)
{
	// Edgecase -> If either of the numbers are negative and the other one is positive, run the subtract function instead (without sign check)
	if (((other.m_is_negative && !m_is_negative) || (!other.m_is_negative && m_is_negative)) && !bypass)
	{
		return subtract(other);
	}

	// For all the digits
	for (int i = 39; i >= 0; i--)
	{
		// Add them together
		int total = m_digits[i] + other.m_digits[i];

		// Get the digit in the ones column
		m_digits[i] = total % 10;

		// Check to make sure we aren't at the end of the possible array size
		if (i == 0)
		{
			break;
		}

		// Overflow to the next digit if the number is bigger then expected
		m_digits[i - 1] += (total / 10);
	}
}

void HugeInteger::subtract(HugeInteger& other)
{
	// Edgecase -> If either of the numbers are negative and the other one is possitive, run add instead (without sign check)
	if (!m_is_negative && other.m_is_negative || m_is_negative && !other.m_is_negative)
	{
		return add(other, true);
	}

	// Store the biggest and smallest number
	int t_big_arr[40];
	int t_small_arr[40];

	// Store if we flip the sign or not
	bool t_flip_sign = false;

	// If this classes number is bigger then the other classes number
	if (isGreaterThan(other, true))
	{
		// Store this classes numbers into the big array and the other into the smaller array
		for (int i = 0; i != 40; i++)
		{
			t_big_arr[i] = m_digits[i];
			t_small_arr[i] = other.m_digits[i];
		}
	}
	else {
		// Otherwise, put this class into the small array and the other one into the big array
		// Also flip the sign at the end of this function
		t_flip_sign = true;
		for (int i = 0; i != 40; i++)
		{
			t_big_arr[i] = other.m_digits[i];
			t_small_arr[i] = m_digits[i];
		}
	}

	// From right to left
	for (int i = 39; i >= 0; i--)
	{
		// Subtract the values
		t_big_arr[i] = t_big_arr[i] - t_small_arr[i];

		// If the number is negative, we need to do some carrying
		if (t_big_arr[i] < 0)
		{

			// Find next non-zero digit
			int target = 0;
			for (int j = i - 1; j >= 0; j--)
			{
				// When we find it
				if (t_big_arr[j] != 0)
				{
					// Set target its index to our target value and break out
					target = j;
					break;
				}
			}

			// Subtract the number we are carrying from
			t_big_arr[target]--;

			// Count from the target back to where we are setting every slot to 9 (because we are carrying backwards)
			for (int j = target + 1; j != i; j++)
			{
				t_big_arr[j] = 9;
			}

			// Correct the current digits number
			t_big_arr[i] += 10;
		}
	}

	// If we flip the sign, flip the sign
	if (t_flip_sign)
	{
		m_is_negative = !m_is_negative;
	}

	// Store the result into this classes digits member
	for (int i = 0; i != 40; i++)
	{
		m_digits[i] = t_big_arr[i];
	}
}

bool HugeInteger::isEqualTo(const HugeInteger& other) const
{
	// Edgecase -> If the signs are different, return false
	if (other.m_is_negative != m_is_negative)
	{
		return false;
	}

	// For all the digits from right to left
	for (int i = 39; i >= 0; i--)
	{
		// If they don't equal eachother, return false
		if (m_digits[i] != other.m_digits[i])
		{
			return false;
		}
	}

	// Return true otherwise
	return true;
}

bool HugeInteger::isNotEqualTo(const HugeInteger& other) const
{
	// Return the inverse of isEqualTo
	return !isEqualTo(other);
}

bool HugeInteger::isGreaterThan(const HugeInteger& other, const bool passthrough) const
{
	// Edgecase -> If this number is negative and the other one is positive, return false
	if (m_is_negative && !other.m_is_negative && !passthrough)
	{
		return false;
	}
	// Edgecase -> If this number is positive and the other one is negative, return true
	else if (!m_is_negative && other.m_is_negative && !passthrough)
	{
		return true;
	}
	// Edgecase -> If both numbers are negative, run a less then check instead (with ignore signs enabled)
	else if (m_is_negative && other.m_is_negative && !passthrough) {
		return isLessThan(other, true);
	}

	// Used to find the first digit
	bool hit = false;

	// From left to right
	for (int i = 0; i != 40; i++)
	{
		// If we havn't found a digit yet
		if (!hit)
		{
			// If either of the numbers aren't zero, set hit to true
			if (m_digits[i] != 0 || other.m_digits[i] != 0)
			{
				hit = true;
			}
			// Otherwise, skip until we find one
			else {
				continue;
			}
		}

		// If this classes digit is greater then the classes digit, return true
		if (m_digits[i] > other.m_digits[i])
		{
			return true;
		}
		// Otherwise, return false
		else if (m_digits[i] < other.m_digits[i]) {
			return false;
		}
		// If they are equal, check the next digit
	}

	// Otherwise, return false
	return false;
}

bool HugeInteger::isLessThan(const HugeInteger& other, const bool passthrough) const
{
	// Edgecase -> If this number is negative and the other one is positive, return true
	if (m_is_negative && !other.m_is_negative && !passthrough)
	{
		return true;
	}
	// Edgecase -> If this number is positive  and the other one is negative, return false
	else if (!m_is_negative && other.m_is_negative && !passthrough)
	{
		return false;
	}
	// Edgecase -> If both numbers are negative, call isGreaterThen (with ignore sign enabled)
	else if (m_is_negative && other.m_is_negative && !passthrough) {
		return isGreaterThan(other, true);
	}

	// Used to find the first digit
	bool hit = false;

	// For every digit from left to right
	for (int i = 0; i != 40; i++)
	{
		// If we havn't found the first digit yet
		if (!hit)
		{
			// Check to see if either of the digits we are checking aren't zero
			if (m_digits[i] != 0 || other.m_digits[i] != 0)
			{
				// Set it to true if either digits aren't zero
				hit = true;
			}
			else {
				// Otherwise, skip until we find a digit
				continue;
			}
		}

		// If the digit we are checking is less then the other digit, return true
		if (m_digits[i] < other.m_digits[i])
		{
			return true;
		}
		// If the digit we are checking is greater then the other digit, return false
		else if (m_digits[i] > other.m_digits[i]) {
			return false;
		}
		// Otherwise, keep checking digits
	}

	// Return false otherwise
	return false;
}

bool HugeInteger::isGreaterThanOrEqualTo(const HugeInteger& other) const
{
	// Return if isGreaterThan or isEqualTo is 1
	return isGreaterThan(other) || isEqualTo(other);
}

bool HugeInteger::isLessThanOrEqualTo(const HugeInteger& other) const
{
	// Return if isLessThan or isEqualTo is 1
	return isLessThan(other) || isEqualTo(other);
}

bool HugeInteger::isZero() const
{
	// From left to right
	for (int i = 0; i != 40; i++)
	{
		// If any of the digits aren't 0
		if (m_digits[i] != 0)
		{
			// Return false
			return false;
		}
	}

	// Otherwise, return true
	return true;
}

///
///
/// Source.cpp
/// 
///

// Name: -----	ID: -----

// ************************ PART 1 ************************

// (HugeInteger  Class)  Create  a  class  HugeInteger  that  uses  a  40-element  array  of  digits  to  store 
// integers  as  large  as  40  digits  each.Provide  member  functions  input, output, addand subtract.For
// comparing  HugeInteger  objects, provide  functions  isEqualTo, isNotEqualTo, isGreaterThan, isLessThan,
// isGreaterThanOrEqualToand isLessThanOrEqualTo—each of these is a “predicate” function that simply
// returns true if the relationship holds between the two HugeIntegersand returns false if the relationship
// does not hold.Also, provide a predicate function isZero.


// #include <iostream>

// #include "HugeInteger.h"


// Program entry function
int main(void)
{

	// Print the title of the project (optional)
	std::cout << "-----------====== HugeInteger Class Test ======-----------" << std::endl;

	std::cout << "----------- Test 1 ----------" << std::endl;
	std::cout << "Defining a positive huge integer 1: ";
	HugeInteger hugeInt1 = HugeInteger("999591843425678491625467981", false);
	hugeInt1.output();

	std::cout << "Defining a positive huge integer 2: ";
	HugeInteger hugeInt2 = HugeInteger("9849198574267632567654791", false);
	hugeInt2.output();

	std::cout << "Is hugeInt1 >= hugeInt2: " << hugeInt1.isGreaterThanOrEqualTo(hugeInt2) << std::endl;
	std::cout << "Is hugeInt1 <= hugeInt2: " << hugeInt1.isLessThanOrEqualTo(hugeInt2) << std::endl;
	std::cout << "Is hugeInt1 == hugeInt2: " << hugeInt1.isEqualTo(hugeInt2) << std::endl;
	std::cout << "Adding hugeInt1 with hugeInt2..." << std::endl;
	hugeInt1.add(hugeInt2);
	std::cout << "The new value of hugeInt1: ";
	hugeInt1.output();

	std::cout << "\n\n----------- Test 2 ----------" << std::endl;
	std::cout << "Defining a positive huge integer 1: ";
	hugeInt1 = HugeInteger("4984984498110000099999881", false);
	hugeInt1.output();

	std::cout << "Defining a positive huge integer 2: ";
	hugeInt2 = HugeInteger("6416516515655555555165198488852", false);
	hugeInt2.output();

	std::cout << "Is hugeInt1 >= hugeInt2: " << hugeInt1.isGreaterThanOrEqualTo(hugeInt2) << std::endl;
	std::cout << "Is hugeInt1 <= hugeInt2: " << hugeInt1.isLessThanOrEqualTo(hugeInt2) << std::endl;
	std::cout << "Is hugeInt1 == hugeInt2: " << hugeInt1.isEqualTo(hugeInt2) << std::endl;
	std::cout << "Subtracting hugeInt1 with hugeInt2..." << std::endl;
	hugeInt1.subtract(hugeInt2);
	std::cout << "The new value of hugeInt1: ";
	hugeInt1.output();

	std::cout << "\n\n----------- Test 3 ----------" << std::endl;
	std::cout << "Defining a positive huge integer 1: ";
	hugeInt1 = HugeInteger("16198146516884949681355", false);
	hugeInt1.output();

	std::cout << "Defining a negetive huge integer 2: ";
	hugeInt2 = HugeInteger("16198146516884949681355", true);
	hugeInt2.output();

	std::cout << "Is hugeInt1 >= hugeInt2: " << hugeInt1.isGreaterThanOrEqualTo(hugeInt2) << std::endl;
	std::cout << "Is hugeInt1 <= hugeInt2: " << hugeInt1.isLessThanOrEqualTo(hugeInt2) << std::endl;
	std::cout << "Is hugeInt1 == hugeInt2: " << hugeInt1.isEqualTo(hugeInt2) << std::endl;
	std::cout << "Is hugeInt1 zero: " << hugeInt1.isZero() << std::endl;
	std::cout << "Subtracting hugeInt2 with hugeInt1..." << std::endl;
	hugeInt2.subtract(hugeInt1);
	std::cout << "The new value of hugeInt2: ";
	hugeInt2.output();

	std::cout << "\n\n----------- Test 4 ----------" << std::endl;
	std::cout << "Defining a positive huge integer 1: ";
	hugeInt1 = HugeInteger("35", false);
	hugeInt1.output();

	std::cout << "Defining a negetive huge integer 2: ";
	hugeInt2 = HugeInteger("35", false);
	hugeInt2.output();

	std::cout << "Is hugeInt1 >= hugeInt2: " << hugeInt1.isGreaterThanOrEqualTo(hugeInt2) << std::endl;
	std::cout << "Is hugeInt1 <= hugeInt2: " << hugeInt1.isLessThanOrEqualTo(hugeInt2) << std::endl;
	std::cout << "Is hugeInt1 == hugeInt2: " << hugeInt1.isEqualTo(hugeInt2) << std::endl;
	std::cout << "Is hugeInt2 zero: " << hugeInt2.isZero() << std::endl;
	std::cout << "Subtracting hugeInt2 with hugeInt1..." << std::endl;
	hugeInt2.subtract(hugeInt1);
	std::cout << "The new value of hugeInt2: ";
	hugeInt2.output();
	std::cout << "Is hugeInt2 zero: " << hugeInt2.isZero() << std::endl;

} // End entry function