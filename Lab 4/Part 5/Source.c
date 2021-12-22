// Name: -----	ID: -----

// ************************ PART 5 ************************

// (Separating Digits) Write program segments that accomplish each of the following:

//a) Calculate the integer part of the quotient when integer a is divided by integer b.

//b) Calculate the integer remainder when integer a is divided by integer b.

//c) Use the program pieces developed in a) and b) to write a function that inputs an integer between 1 and 32767 and prints it as a series of digits, with two spaces between each digit.For example, the integer 4562 should be printed as : 4 5 6 2


#include <stdio.h>
#include <math.h>

// Define the signiture of seperatePrint
// Required for part a
void seperatePrint(int num);

// Define the signiture of getQuotient
// Required for part b
int getQuotient(int a, int b);

// Define the signiture of get Remainder
// Required for part c
int getRemainder(int a, int b);

// Program entry function
int main(void)
{
	int num;

	// Print the title
	puts("--========= Separating Digits =========--");

	// Ask the user for a number from 1 to 31767
	printf("Enter a number between 1 and 32767: ");
	scanf_s("%d", &num);

	// Print the number seperated
	seperatePrint(num);


} // End entry function

// Define int getQuotient
// Required for part a
int getQuotient(int a, int b)
{
	// Calculate and return the quotient
	return (a / b);
}

// Define int getRemainer
// Required for part b
int getRemainder(int a, int b)
{
	// Calculate and return the remainder
	return (a % b);
}

// Define seperatePrint
// Required for part c
void seperatePrint(int num)
{
	// Define currNum
	int currNum = num;

	// Define the divisor to seperate digits
	int div = 10000;

	// Shrink div until we reach the length of the number
	while (1)
	{
		// If the result is a zero,
		if (getQuotient(currNum, div) == 0)
		{
			// Shrink the dividor
			div /= 10;
		}
		else {
			// Otherwise, break out
			break;
		}
	}

	// While we havn't reached the first digit
	while (div >= 1)
	{
		// Get the digit
		int digit = getQuotient(currNum, div);

		// Get the remainder
		currNum = getRemainder(currNum, div);

		// Print the number
		printf("%d  ", digit);

		// Shrink the div
		div /= 10;
	}

	// Print a new line
	printf("\n");
}