// Name: -----	ID: -----

// ************************ PART 8 ************************

// (Calculating the Compound Interest with Integers) Use only integers to calculate the compound interest of the following problem. [Hint: Treat all monetary amounts as integral numbers of pennies. Then “break” the result into its dollar portion and cents portion by using the division and remainder operations, respectively. Insert a period.]


// Consider the following problem statement :

// A person invests $1000.00 in a savings account yielding 5 % interest.Assuming that all interest is left on deposit in the account, calculateand print the amount of money in the account at the end of each year for 10 years.Use the following formula for determining these amounts : a = p(1 + r)n     where p is the original amount invested(i.e., the principal)
// r is the annual interest rate
// n is the number of years
// a is the amount on deposit at the end of the nth year.


#include <stdio.h>
#include <math.h>


// Program entry function
int main(void)
{
	// Define the original amount 
	int originalAmount = 100000;

	// For year 1 -> 10
	for (int year = 1; year <= 10; year++)
	{
		// Calculate the new amount
		int newTotal = originalAmount * pow((1.05), year);

		// Calculate the dollars and cents
		int dollars = newTotal / 100;
		int cents = newTotal - (dollars * 100);

		// Print the total at the end of the year
		printf("The ammount at the end of the year %d is: $%d.%.2d\n", year, dollars, cents);
	}



} // End entry function