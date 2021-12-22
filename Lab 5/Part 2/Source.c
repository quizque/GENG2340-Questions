// Name: ----- ID: -----

// ************************ PART 2 ************************

// Most likely, the Brute-Force approaches produced a relatively short tour. Run a random tour once from any spot

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isValidMove(int x, int y, int board[8][8]);

// Program entry function
int main(void)
{

	// Print the title of the project
	puts("-----------========= Knight's Tour Random Walk @ { 0, 0 } =========-----------");


	// Max amount of random iterations
	int MAX_ITERATIONS = 10000;

	// Store the best board found
	int best_board[8][8] = {
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	};;

	// Store the best board score
	int best_board_score = 0;

	// Store the best board index
	int best_board_index = 0;

	// Set random seed
	srand(time(NULL));

	// Print warning
	puts("This might take a bit, please be patient...");

	// Create the accessibility grid
	int accessibility[8][8] = {
	 { 2, 3, 4, 4, 4, 4, 3, 2 },
	 { 3, 4, 6, 6, 6, 6, 4, 3 },
	 { 4, 6, 8, 8, 8, 8, 6, 4 },
	 { 4, 6, 8, 8, 8, 8, 6, 4 },
	 { 4, 6, 8, 8, 8, 8, 6, 4 },
	 { 4, 6, 8, 8, 8, 8, 6, 4 },
	 { 3, 4, 6, 6, 6, 6, 4, 3 },
	 { 2, 3, 4, 4, 4, 4, 3, 2 },
	};

	// Create the board to store moves
	int board[8][8] = {
	 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0,
	};

	// Store the possible moves
	int moves[8][2] = {
	 {2, -1}, {1, -2}, {-1, -2}, {-2, -1},
	 {-2, 1}, {-1, 2}, {1, 2}, {2, 1},
	};

	// Get the current x and y cords
	int x = 0;
	int y = 0;

	// Store the current best move
	int currentMove = 0;



	// For forever
	while (1)
	{
		// Add one to current move and store
		// the current move count in the current
		// positon we are at
		board[x][y] = ++currentMove;

		// Store varibles to hold
		// the next spot we will move to
		int best_direction = 0;
		int best_score = 9;

		// For max iterations
		for (int i = 0; i != MAX_ITERATIONS; i++)
		{
			// Generate random direction
			int dir = rand() % 8;

			// Get the new x and y for testing 
			int new_x = x + moves[dir][0];
			int new_y = y + moves[dir][1];

			// Check if it is a valid move and we havn't been
			// to it yet
			if (isValidMove(new_x, new_y, accessibility))
			{
				// Set our new best score and direction then leave the loop
				best_score = accessibility[new_x][new_y];
				best_direction = dir;
				break;
			}
		}

		// If the best score is 9, meaning
		// we didn't find a new best direction
		if (best_score == 9)
		{
			// Break, because it means we
			// have a hit a dead end
			break;
		}

		// Set the current accessability score
		// of where we are to zero since we can
		// no longer go back to it
		accessibility[x][y] = 0;

		// Set the new x and y to the best found positon
		x = x + moves[best_direction][0];
		y = y + moves[best_direction][1];
	}

	// Print finished
	puts("Finished!");

	// Print the best run index and count
	puts("\n\n");
	printf("The random walk made a total of %d moves!\n", currentMove);

	// Print the moves made on the best table
	puts("The moves made on that board are:");
	printf("    0  1  2  3  4  5  6  7\n\n");
	for (int _x = 0; _x != 8; _x++)
	{
		printf("%d ", _x);
		for (int _y = 0; _y != 8; _y++)
		{
			printf("%3d", board[_x][_y]);
		}

		printf("\n\n");
	}
} // End entry function

int isValidMove(int x, int y, int board[8][8])
{
	// If the x,y is within 0 -> 7 AND the score of the spot isn't 0...
	return (0 <= x && x <= 7) && (0 <= y && y <= 7) && board[x][y] != 0;
}