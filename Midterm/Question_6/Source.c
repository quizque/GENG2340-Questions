// Name: -----	ID: -----

// ************************ PART 6 ************************

// The greatest common divisor (GCD) of two integers is the largest integer that evenly divides each of the two numbers. Write a program that reads two integer numbers and prints their greatest common divisor.


#include <stdio.h>

// Define the function signiture
int GCD(int num1, int num2);

// Program entry function
int main(void)
{
	// Print the title of the project (optional)
	puts("--========= Greatest Common Divisor (GCD) Calculator =========--");

	// Ask for the first number
	printf("Enter the first number: ");
	int num1;
	scanf_s("%d", &num1);

	// Ask for the second number
	printf("Enter the second number: ");
	int num2;
	scanf_s("%d", &num2);

	// Print the GDC
	printf("The Greatest Common Divisor (GCD) is: %d\n", GCD(num1, num2));


} // End entry function

int GCD(int num1, int num2)
{
	// Store the number we are checking and the GDC we have found
	int checking = 2;
	int highestDiv = 1;

	// While the the we are checking is less then either of the numbers we are given
	while (checking < num1 && checking < num2)
	{
		// If its divisble by both, set it as the new GDC
		if (num1 % checking == 0 && num2 % checking == 0)
		{
			highestDiv = checking;
		}

		// Increment the number we are checking by one
		checking++;
	}

	// Return the highest GDC we found
	return highestDiv;
}