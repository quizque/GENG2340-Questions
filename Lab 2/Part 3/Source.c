// Name: -----	ID: -----

// ************************ PART 3 ************************

// Write a program that reads an integer and determines and prints whether it is odd or even. 

#include <stdio.h>


// Program entry function
int main(void)
{
	// Define int a
	int a;

	// Ask user for integer a
	printf("Enter a number: ");
	scanf_s("%d", &a);

	// Use single-line/conditional if statement to check if the number is even/odd and print the result
	if (a % 2 == 1)
		printf("The number is odd\n");
	if (a % 2 == 0)
		printf("The number is even\n");

} // End entry function