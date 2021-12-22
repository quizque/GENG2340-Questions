/*

// Name: -----	ID: -----

// ************************ PART 3 ************************

// (RationalNumber Class) Create a class RationalNumber (fractions) with these capabilities:

// a) Create a constructor that prevents a 0 denominator in a fraction, reduces or simplifies fractions that are not in reduced form and avoids negative denominators.
// b) Overload the addition, subtraction, multiplicationand division operators for this class.
// c) Overload the relationaland equality operators for this class.A sample output shown in the following figure.


#include <iostream>

#include "RationalNumber.h"


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

*/