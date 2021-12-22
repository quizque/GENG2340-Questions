// Part 2
//
#include <stdio.h>

// Write a single C statement to accomplish each of the following:

// Program entry function
int main(void)
{
	// a) Define the variables c, thisVariable, q76354 and number to be of type int.
	//***********
	// NOTE: GA SAID TO USE VARIBLE "a" WHICH IS REQUIRED TO BE DEFINED
	//***********
	int c, thisVariable, q76354, number, a;

	// b)Prompt the user to enter an integer. End your prompting message with a colon
	// (:) followed by a spaceand leave the cursor positioned after the space.
	printf("Enter an integer: ");

	// c) Read an integer from the keyboard and store the value entered in integer
	// variable a
	scanf_s("%d", &a);

	// d) If number is not equal to 7, print "The variable number is not equal to 7.“
	//***********
	// NOTE: THE GA SAID TO USE VARIBLE "a" INSTED OF "number"
	//***********
	if (a != 7) { printf("The variable number is not equal to 7\n"); }

	// e) Print the message "This is a C program." with each word on a separate line.
	printf("This\nis\na\nC\nprogram.\n");

	// f) Print the message "This is a C program." with the words separated by tabs.
	printf("This\tis\ta\tC\tprogram.\n");
} // End entry function