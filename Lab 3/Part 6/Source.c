// Name: -----    ID: -----

// ************************ PART 6 ************************

// (Printing the Decimal Equivalent of a Binary Number) Input an integer containing
// only 0s and 1s (i.e., a “binary” integer) and print its decimal equivalent. [Hint:
// Use the remainder and division operators to pick off the “binary” number’s digits
// one at a time from right to left. Just as in the decimal number system, in which
// the rightmost digit has a positional value of 1, and the next digit left has a
// positional value of 10, then 100, then 1000, and so on, in the binary number
// system the rightmost digit has a positional value of 1, the next digit left has a
// positional value of 2, then 4, then 8, and so on. Thus, the decimal number 234 can
// be interpreted as 4*1 + 3*10 + 2*100.  The decimal equivalent of binary 1101 is
// 1*1 + 0*2 + 1*4 + 1*8 or 1+0+4+8 or 13.]


#include <stdio.h>
#include <math.h>


// Program entry function
int main(void)
{
	// Define the input, the answer, and the stepping power value
	int input, answer = 0, stepper = 0;

	// Pront the user to enter a binary number
	printf("Enter a binary number: ");
	scanf_s("%d", &input);

	// While we havn't finished calcating
	while (input != 0) {

		// Add the current binary value to the power of 2 ^ stepping
		answer += (input % 10) * pow(2, stepper);

		// Remove the current binary value we are using
		input /= 10;

		// Add 1 to stepper
		stepper++;
	}

	// Print the resulting answer
	printf("The binary converted to decimal is: %d\n", answer);
} // End entry function