// Name: -----    ID: -----

// ************************ PART 3 ************************

// (Table of Decimal, Binary, Octal and Hexadecimal Equivalents) Write a program that prints a table of the
// binary, octaland hexadecimal equivalents of the decimal numbers in the range 1 through 256


#include <stdio.h>


// Program entry function
int main(void)
{
	// Define a varible to start counting
	int n = 1;

	// Print the table header
	printf("------====== Table OF DEC, BIN, OCT, HEX ======------\n\n");
	printf("Decimal | (Unsigned) Binary  | Octal    | Hexadecimal\n");

	// For all numbers from 1 -> 256
	while (n <= 256)
	{

		// Define the varibles to calculate the binary
		// value and one value to calculate the spacer
		int bin = 0, tmp = n, stepper = 1;

		// While we havn't reached zero
		while (tmp != 0)
		{
			bin += (tmp % 2) * stepper;

			// Divide tmp by two and floor the value (round down)
			tmp /= 2;

			// Pow the stepper varible
			stepper *= 10;
		}

		// Print the first half of the table
		printf("%d\t|%d     ", n, bin);

		// Formatting fix
		if (n == 1)
			printf(" ");

		// Print the right half of the table
		printf("\t     |%o \t|%x\n", n, n);

		// Increment the counter
		n++;
	}

} // End entry function