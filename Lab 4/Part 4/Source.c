// Name: -----	ID: -----

// ************************ PART 4 ************************

// (Even or Odd) Write a program that inputs a series of integers and passes them one at a time to function is Even, which uses the remainder operator to determine whether an integer is even. The function should take an integer argument and return 1 if the integer is even and 0 otherwise.


#include <stdio.h>

// Signiture for isEven function
int isEven(int num);


// Program entry function
int main(void)
{
	// Print the title
	puts("--========= Even Or Odd =========--");

	// Define number 0
	int num = 0;

	// For forever
	while (1)
	{
		// Ask the user for a number and store it in num
		printf("Enter a number (-1 to exit): ");
		scanf_s("%d", &num);

		// If num is -1, quit
		if (num == -1)
		{
			break;
		}

		// If the number is even, print that it is even
		if (isEven(num)) 
		{
			puts("The number is even!");
		}
		// Otherwise, say its not!
		else 
		{
			puts("The number is NOT even!");
		}
	}



} // End entry function


// Define isEven function
int isEven(int num)
{
	// If it is divisible by 2, return 1
	if (num % 2 == 0)
	{
		return 1;
	}


	// If it isn't divisible by two, return 0
	return 0;
}