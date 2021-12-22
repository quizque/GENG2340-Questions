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