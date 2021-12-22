// Name: -----	ID: -----

// ************************ PART 7 ************************

// Write a program that reads in two integers and determines and prints if the first is a multiple of the second. [Hint: Use the remainder operator]


#include <stdio.h>


// Program entry function
int main(void)
{
	int x, y;

	// Ask the user for two numbers
	printf("Enter two numbers: ");
	scanf_s("%d%d", &x, &y);

	// Check if the remainder is zero
	if (x % y == 0)
		printf("%d is a multiple of %d\n", x, y);

	// If the remainder is not zero
	if (x % y != 0)
		printf("%d is NOT a multiple of %d\n", x, y);


} // End entry function