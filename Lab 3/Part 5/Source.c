// Name: -----	ID: -----

// ************************ PART 5 ************************

// 5-Write a program that estimates the value of the mathematical constant e by eleven terms of the following formula: 1 + 1/1! + 1/2! + 1/3! + ....


#include <stdio.h>


// Program entry function
int main(void)
{
	// Define e
	float e = 1.0;
	
	// Define factorial
	int fact = 1;

	// From 1 -> 11
	for (int i = 1; i <= 11; i++) {
		// Calculate the factorial
		fact = fact * i;

		// Add the calculate factorial ^ -1 too e
		e += 1.0 / fact;
	}

	// Print e
	printf("The calculated value of e: %f\n", e);

} // End entry function