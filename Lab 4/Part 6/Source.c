// Name: -----	ID: -----

// ************************ PART 6 ************************

// (Perfect Numbers) An integer number is said to be a perfect number if its factors, including 1 (but not the number itself), sum to the number. For example, 6 is a perfect number because 6 =1 + 2 + 3. Write a function perfect that determines if parameter number is a perfect number. Use this function in a program that determines and prints all the perfect numbers between 1 and 1000. Print the factors of each perfect number to confirm that the number is indeed perfect. Challenge the power of your computer by testing numbers much larger than 1000.


#include <stdio.h>

// Define isPerfectNumber signiture
int isPerfectNumber(int num);

// Program entry function
int main(void)
{

	// Print the title
	puts("--========= Perfect Numbers =========--");

	// For every number from 1 to 1000
	for (int i = 1; i <= 1000; i++)
	{
		// If it is perfect
		if (isPerfectNumber(i))
		{
			// Print the number
			printf("%d is a perfect number!\n", i);
		}
	}


} // End entry function

// Define isPerfectNumber
int isPerfectNumber(int num)
{
	// Define currNum
	int currNum = 0;

	// For every number from 1 -> number
	for (int i = 1; i < num; i++)
	{
		// If it is divisible, add it to the
		// current number
		if (num % i == 0)
		{
			currNum += i;
		}
	}

	// If the calculated number is not the number we expected, return 0
	if (currNum != num)
	{
		return 0;
	}

	// Return 1 otherwise
	return 1;
}