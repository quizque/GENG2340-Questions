// Name: -----	ID: -----

// ************************ PART 7 ************************

// (Coin Tossing) Write a program that simulates coin tossing. For each toss of the coin the program should print Heads or Tails. Let the program toss the coin 100 times, and count the number of times each side of the coin appears. Print the results. The program should call a separate function flip that takes no arguments and returns 0 for tails and 1 for heads. [Note: If the program realistically simulates the coin tossing, then each side of the coin should appear approximately half the time for a total of approximately 50 heads and 50 tails.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int coinFlip();

// Program entry function
int main(void)
{
	// Set the random seed
	srand(time(NULL));

	// Define the varibles heads, tails, and runs
	int heads = 0, tails = 0, runs = 0;

	// Print the title and next process
	puts("--========= Coin Tossing =========--");
	puts("Running coin flip simulation 100 times...");

	// Run 100 times
	for (int i = 0; i != 100; i++)
	{
		// If the coinflip returns 1...
		if (coinFlip())
		{
			// Add one to head
			heads++;
		}
		else {
			// Add one to tails
			tails++;
		}

		// Add one to the runs counter
		runs++;
	}
	
	// Print the simulation result
	printf("Finished simulation!\n");
	printf("Total runs: %d\n", runs);
	printf("Total heads: %d\n", heads);
	printf("Total tails: %d\n", tails);

} // End entry function

// Define coinFlip function
int coinFlip()
{
	// If the remainder divided by 2 is zero
	if (rand() % 2 == 0)
	{
		// Return 1
		return 1;
	}

	// Return 0
	return 0;
}