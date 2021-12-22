/*
* 
// Name: -----	ID: -----

// ************************ PART 1 ************************

// (HugeInteger  Class)  Create  a  class  HugeInteger  that  uses  a  40-element  array  of  digits  to  store 
// integers  as  large  as  40  digits  each.Provide  member  functions  input, output, addand subtract.For
// comparing  HugeInteger  objects, provide  functions  isEqualTo, isNotEqualTo, isGreaterThan, isLessThan,
// isGreaterThanOrEqualToand isLessThanOrEqualTo—each of these is a “predicate” function that simply
// returns true if the relationship holds between the two HugeIntegersand returns false if the relationship
// does not hold.Also, provide a predicate function isZero.


#include <iostream>

#include "HugeInteger.h"


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

*/