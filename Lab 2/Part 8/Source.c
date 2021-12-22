// Name: -----	ID: -----

// ************************ PART 8 ************************

// Write a program that inputs one five-digit number, separates the number into its individual digits and prints the digits separated from one another by three spaces each. [Hint: Use combinations of integer division and the remainder operation.] For example, if the user types in 42139, the program should print  4   2   1   3   9


#include <stdio.h>


// Program entry function
int main(void)
{

	int number;

	// Ask user for a number
	printf("Enter a five digit number: ");
	scanf_s("%d", &number);

	// Get first number
	printf("The seperated digits are: %d   ", number / 10000);

	// Get second number
	number -= (number / 10000) * 10000;
	printf("%d   ", number / 1000);

	// Get third number
	number -= (number / 1000) * 1000;
	printf("%d   ", number / 100);

	// Get fourth number
	number -= (number / 100) * 100;
	printf("%d   ", number / 10);

	// Get fifth number
	number -= (number / 10) * 10;
	printf("%d\n", number);


} // End entry function