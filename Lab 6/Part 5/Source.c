// Name: -----	ID: -----

// ************************ PART 5 ************************

// (The Sieve of Eratosthenes) A prime integer is any integer greater than 1 that can be divided evenly only by itself and 1. The Sieve of Eratosthenes is a method of finding prime numbers. It works as follows:

 

// Create an array with all elements initialized to 1 (true).Array elements with prime subscripts will remain 1. All other array elements will eventually be set to zero.Starting with array subscript 2 (subscript 1 is not prime), every time an array element is found whose value is 1, loop through the remainder of the arrayand set to zero every element whose subscript is a multiple of the subscript for the element with value 1. For array subscript 2, all elements beyond 2 in the array that are multiples of 2 will be set to zero(subscripts 4, 6, 8, 10, and so on.).For array subscript 3, all elements beyond 3 in the array that are multiples of 3 will be set to zero(subscripts 6, 9, 12, 15, and so on.).When this process is complete, the array elements that are still set to 1 indicate that the subscript is a prime number.// 
// Write a program that uses an array of 1000 elements to determine and print the prime numbers between 1 and 999. Ignore element 0 of the array.

#include <stdio.h>


// Program entry function
int main(void)
{
	// Define the array
	int arr[1000];

	// Set all values to 1
	for (int i = 0; i != 1000; i++)
	{
		arr[i] = 1;
	}

	// 1 is not a prime
	arr[0] = 0;

	// Print the title of the project
	puts("--========= Sieve of Eratosthenes =========--");
	puts("Calculating...\n");

	// For all the elements
	for (int i = 1; i != 1000; i++)
	{
		// If the element is still active (meaning its prime)
		if (arr[i] == 1)
		{
			// Starting at index 2*i + 1 (next divisible number) going up by i + 1
			for (int j = i + i + 1; j < 1000; j += i+1)
			{
				// Set that index to zero
				arr[j] = 0;
			}
		}
	}

	puts("Heres the primes we found between 1 and 999: ");

	// Print the prime numbers we found only if its array spot is 1
	for (int i = 0; i != 1000; i++)
	{
		if (arr[i] == 1)
		{
			printf("| -> %d\n", i + 1);
		}
	}


} // End entry function