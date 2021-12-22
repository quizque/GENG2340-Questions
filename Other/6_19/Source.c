// Name: -----	ID: -----

// ************************ PART 6.19 ************************

// Dice Rolling) Write a program that simulates the rolling of two dice. The program should
// use rand twice to roll the first dieand second die, respectively.The sum of the two values should
// then be calculated.[Note:Because each die can show an integer value from 1 to 6, then the sum of
// the two values will vary from 2 to 12, with 7 being the most frequent sum and 2 and 12 the least
// frequent sums.] Figure 6.24 shows the 36 possible combinations of the two dice.Your program
// should roll the two dice 36, 000 times.Use a one - dimensional array to tally the numbers of times
// each possible sum appears.Print the results in a tabular format.Also, determine if the totals are reasonable; i.e., there are six ways to roll a 7, so approximately one - sixth of all the rolls should be 7


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Program entry function
int main(void)
{

	// Print the title of the project (optional)
	puts("--========= Dice Rolling =========--");

	srand(time(NULL));

	int total[11] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	for (int i = 0; i != 36000; i++)
	{
		total[(rand() % 6 + 1) + (rand() % 6 + 1) - 2]++;
	}

	puts("After rolling 36 000 dice, this is the result");
	printf("   Number   |   # Of Times Rolled\n");

	for (int i = 0; i != 11; i++)
	{
		printf("%7d     |  %10d\n", i + 2, total[i]);
	}

	puts("\nThis gives us the following graph:");

	int graph[11][8] = {
		{ 0, 0, 0, 0, 0 ,0 ,0 ,0 },
		{ 0, 0, 0, 0, 0 ,0 ,0 ,0 },
		{ 0, 0, 0, 0, 0 ,0 ,0 ,0 },
		{ 0, 0, 0, 0, 0 ,0 ,0 ,0 },
		{ 0, 0, 0, 0, 0 ,0 ,0 ,0 },
		{ 0, 0, 0, 0, 0 ,0 ,0 ,0 },
		{ 0, 0, 0, 0, 0 ,0 ,0 ,0 },
		{ 0, 0, 0, 0, 0 ,0 ,0 ,0 },
		{ 0, 0, 0, 0, 0 ,0 ,0 ,0 },
		{ 0, 0, 0, 0, 0 ,0 ,0 ,0 },
		{ 0, 0, 0, 0, 0 ,0 ,0 ,0 },
	};

	for (int i = 0; i != 11; i++)
	{
		for (int o = 0; o != (total[i] / 950); o++)
		{
			graph[i][7 - o] = 1;
		}
	}

	for (int x = 0; x != 8; x++)
	{
		for (int y = 0; y != 11; y++)
		{
			if (graph[y][x] == 1)
			{
				printf("  O  ");
			}
			else
			{
				printf("     ");
			}
		}
		puts("");
	}

	puts("  2    3    4    5    6    7    8    9    10   11   12  ");

	int followsNomralDistro = 1;
	int prevNum = total[0];

	for (int i = 0; i != 6; i++)
	{
		if (prevNum <= total[i])
		{
			prevNum = total[i];
		}
		else {
			followsNomralDistro = 0;
			break;
		}
	}

	prevNum = total[5];
	for (int i = 5; i != 11; i++)
	{
		if (prevNum >= total[i])
		{
			prevNum = total[i];
		}
		else {
			followsNomralDistro = 0;
			break;
		}
	}

	if (followsNomralDistro)
	{
		puts("\nFrom this, we can tell that the graph is resonable since it follows a normal distrobution!");
	}
	else {
		puts("\nFrom this, we can tell that the graph is NOT resonable since it follows a normal distrobution!");
	}

} // End entry function