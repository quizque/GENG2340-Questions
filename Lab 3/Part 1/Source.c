// Name: -----    ID: -----

// ************************ PART 1 ************************

// A palindrome is a number or a text phrase that reads the same backward as forward. For example, each
// of the following five - digit integers is a palindrome : 12321, 55555, 45554 and 11611. Write a program that
// reads  in  a five - digit  integer and determines  whether or not it’s  a  palindrome.[Hint:Use  the  division and
// remainder operators to separate the number into its individual digits


#include <stdio.h>


// Program entry function
int main(void)
{
	// Define varible to hold user input
	int num;

	// Ask user to enter a five digit number and store
	// it in varible num
	printf("Enter a five digit number: ");
	scanf_s("%d", &num);

	// Get the two left most digits
	int left = num / 1000;

	// Get the two right most digits reversed
	int right = (num - (num / 10) * 10) * 10 + (num - (num / 100) * 100) / 10;

	// If the left most digits is equal right most digits reversed,
	// print that it is a palindrome
	if (left == right) {
		printf("The number is a palindrome!\n");
	}
	else {
		printf("The number is NOT a palindrome!\n");
	}

} // End entry function