
// Name: -----	ID: -----

// ************************ PART 1 ************************

// Print "welcome to c!\n"

// Part 1
//
#include <stdio.h>

// Program entry function
int main(void)
{
	// Print "Welcome to C!"
	printf("Welcome");
	printf("to C!\n");
} // End entry function


// ************************ PART 2 ************************

// Write a single C statement to accomplish each of the following:

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


// ************************ PART 3 ************************

// Part 3
//
#include <stdio.h>

// Write a program to 
// (a) prompt the user to enter three integers.
// (b) read the integers from the keyboard and store them in the variables x, y and z.
// (c) calculate the product of three integers and print the result.

// Program entry function
int main(void)
{
	// Define integers x, y, z and result
	int x, y, z, result;

	// Get integer from user for value x
	printf("Enter a integer for x: ");
	scanf_s("%d", &x);

	// Get integer from user for value y
	printf("Enter a integer for y: ");
	scanf_s("%d", &y);

	// Get integer from user for value z
	printf("Enter a integer for z: ");
	scanf_s("%d", &z);

	// Calculate the product of x, y, and z
	result = x * y * z;

	// Print the product of x, y, z
	printf("The product of x, y, z is %d\n", result);
} // End entry function