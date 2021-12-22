// Name: -----	ID: -----

// ************************ PART 2 ************************

// (Dice  Rolling)  Write  a  program  that  simulates  the  rolling  of  two  dice.  The  program  should  use  rand  to  roll  the  first  die,  and 
// should use rand again to roll the second die.The sum of the two values should then be calculated.[Note:Since each die can show
// an integer value from 1 to 6, then the sum of the two values will vary from 2 to 12, with 7 being the most frequent sum and 2 and
// 12 the least frequent sums.].Figure_1 shows the 36 possible combinations of the two dice.Your program should roll the two dice
// 36, 000 times.Use a single - subscripted array to tally the numbers of times each possible sum appears.Print the results in a tabular
// format.Also, determine if the totals are reasonable; i.e., there are six ways to roll a 7, so approximately one - sixth of all the rolls
// should be 7.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


// Program entry function
int main(void)
{

	// Print the title of the project (optional)
	puts("--========= Dice Rolling =========--");

	// Set the random seed
	srand(time(NULL));

	// Define the array to hold the number of times we rolled a number
	int total[11] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	// Run 36 000 times and increase the result of the roll in the array
	for (int i = 0; i != 36000; i++)
	{
		total[(rand() % 6 + 1) + (rand() % 6 + 1) - 2]++;
	}

	// Print the table headers
	puts("After rolling 2 dice 36 000 times, this is the result");
	printf("   Sum   |   Total  |  Expected  |  Actual\n");

	// If the table is resonable, this will stay as 1
	int isReasonable = 1;

	// For all the values we have
	for (int i = 0; i != 11; i++)
	{
		// Calculate the expected and actual values
		float expected = (-(1.0 / 36.0) * (float)abs(i - 5) + (6.0 / 36)) * 100;
		float actual = ((float)total[i] / 36000) * 100;

		// Print the values we calculated
		printf("%6d   |%8d  |%9.3f%%  |%7.3f%%\n", i + 2, total[i], expected, actual);

		// Calculate percent error
		float percent_error = fabs((actual - expected) / expected) * 100.0;

		// If percent error is greater then 20% for any of the values,
		// it is no longer resonable so set isResonoable to 0
		if (percent_error > 20.0)
		{
			isReasonable = 0;
		}

	}

	// If the values were found to be reasonable, tell the user
	if (isReasonable)
	{
		printf("\nThe result is reasonable as the actual values are within margin of error with the expected value.\n");
	}
	// Otherwise, tell the user it wasn't reasonable
	else
	{
		printf("\nThe result is NOT reasonable as the actual values are NOT within margin of error with the expected value.\n");
	}

} // End entry function