// Name: -----	ID: -----

// ************************ PART 5 ************************

// Write a program to estimate the value of e5 using the first 15 terms of the following formula.


#include <stdio.h>
#include <math.h>

// Define the function signiture
double calcE(int power, int terms);
double factorialRecursive(double num);


// Program entry function
int main(void)
{

	// Print the title of the project
	puts("--========= Calculate e^5 =========--");

	// Notify the user this might take a bit and calculate e^5 with 15 terms
	puts("This might take a bit, please wait!");
	double e = calcE(5, 15);
	puts("Done!");

	// Print the calculated value of e!
	printf("The calculated value of e^5 with 15 terms is: %f\n", e);

} // End entry function

double calcE(int power, int terms)
{
	// Define e
	double e = 1;
	// For 1 -> terms (15 in this case)
	for (int i = 1; i <= terms; i++)
	{
		// Add (power of e)^i divideded by factorial i
		e += pow(power, i) / factorialRecursive(i);
	}

	// Return e
	return e;
}

double factorialRecursive(double num)
{
	// If the number is 2, we can quit
	if (num == 2.0)
	{
		// Then return
		return 2.0;
	}

	// If its 0 or 1, just return, don't print
	if (num == 0.0 || num == 1.0)
	{
		return 1.0;
	}

	// Return the number times a call to the factorial function 
	return num * factorialRecursive(num - 1);
}