// Name: -----    ID: -----

// ************************ PART 2 ************************

// The factorial of a nonnegative integer n is written n! (pronounced “n factorial”) and is defined as follows:
// n!= n ·(n - 1) ·(n - 2) · ... · 1 (for values of n greater than or equal to 1)  n!= 1 (for n = 0).
// For example, 5!= 5 · 4 · 3 · 2 · 1, which is 120. Write a program that reads a nonnegative integer and computes and prints its factorial.


#include <stdio.h>


// Program entry function
int main(void)
{
	// Define a varible to hold the user input
	// and result
	unsigned int num, result = 1;

	// Ask the user for a non-negative number
	// and store it in varible num
	printf("Enter a non-negative number: ");
	scanf_s("%d", &num);

	// If its not zero, compute the factorial
	// NOTE: Only values up to n = 12 are supported as
	//         numbers that are any bigger will overflow
	while (num >= 2)
	{
		result *= --num + 1;
	}


	// Print the result of the calculation
	printf("The factorial is: %d\n", result);

} // End entry function