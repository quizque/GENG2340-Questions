// Name: -----	ID: -----

// ************************ PART 2 ************************

// (Prime Numbers) An integer is said to be prime if it’s divisible by only 1 and itself.  
//
// a) Write a function that determines if a number is prime.
// b) Use this function in a program that determinesand prints all the prime numbers between 1 and 10, 000.
// How many of these 10, 000 numbers do you really have to test before being sure that you have found all
// the primes ?
// c) Initially you might think that n / 2 is the upper limit for which you must test to see if a number is prime,
// but  you  need  go  only  as  high as  the  square  root  of  n.Why ? Rewrite  the program, and run  it  both ways.
// Estimate the performance improvement


// ANSWERS FOR THE QUESTIONS ABOVE
// b) You only need to test ODD numbers because primes can't be divsible by two.
//    By knowing this, we can go up by twos starting from 3in the main loop as 
//    long as we print 2 (which is the first prime) before we start the loop.
// c) We only need to go up to the square root of the number because once we reach
//    the value of the square root, any number bigger then it will result in us
//    repeating possible values, which we don't need, so we stop at that point.

#include <stdio.h>
#include <math.h>

// Define the isPrimePartA signiture
int isPrimePartA(int number);

// Define the isPrimePartB signiture
int isPrimePartB(int number);

// Define the isPrimePartC signiture
int isPrimePartC(int number);

// Program entry function
int main(void)
{
	// Print the title and description
	puts("--========= Prime Printer =========--");
	puts("Printing the prime numbers from 1 -> 10,000");

	// Define a varible for formatting
	int format_counter = 0;

	// Loop from 2 all the way to 10,000
	for (int i = 1; i <= 10000; i += 1)
	{
		// If the number is prime
		if (isPrimePartC(i))
		{
			// Print the number
			printf("%d\t", i);

			// Increment the format counter
			format_counter++;

			// If we have printed 10 prime numbers
			// print a new line
			if (format_counter % 10 == 0)
				puts("");
		}
	}
} // End entry function

// Define isPrimePartA function
int isPrimePartA(int number)
{
	// Prime numbers can be 2 or 3
	// We return here to speed the loop up later
	if (number == 2 || number == 3)
		return 1;

	// Prime numbers MUST be odd and greater or equal then 2
	if (number % 2 == 0 || number < 2)
		return 0;

	// For every number, starting from 2, count up until
	// the  number minus one passed to the function
	// If the number is divisible, return 0
	for (int i = 2; i <= number - 1; i += 1)
		if (number % i == 0)
			return 0;

	// If the number has passed all checks,
	// return true
	return 1;
}

// Define isPrimePartA function
int isPrimePartB(int number)
{
	// Prime numbers can be 2 or 3
	// We return here to speed the loop up later
	if (number == 2 || number == 3)
		return 1;

	// Prime numbers MUST be odd and greater or equal then 2
	if (number % 2 == 0 || number < 2)
		return 0;

	// For every number, starting from 2, count up until
	// HALF of the number passed to the function
	// If the number is divisible, return 0
	for (int i = 2; i <= number / 2; i += 1)
		if (number % i == 0)
			return 0;

	// If the number has passed all checks,
	// return true
	return 1;
}

// Define isPrimePartC function
int isPrimePartC(int number)
{
	// Prime numbers can be 2 or 3
	// We return here to speed the loop up later
	if (number == 2 || number == 3)
		return 1;

	// Prime numbers MUST be odd and greater or equal then 2
	if (number % 2 == 0 || number < 2)
		return 0;

	// For every number, starting from 3, count up by two until
	// the sqrt of the number passed to the function
	// If the number is divisible, return 0
	for (int i = 3; i <= sqrt(number); i += 2)
		if (number % i == 0)
			return 0;

	// If the number has passed all checks,
	// return true
	return 1;
}