// Name: ----- ID: -----

// ************************ PART 3 ************************

// Most likely, the Brute-Force approaches produced a relatively short tour. Now modify the program to attempt 1000 tours. Use a single-subscripted array to keep track of the number of tours of each length. When your program finishes attempting the 1000 tours, it should print this information in neat tabular format. What was the best result?

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isValidMove(int x, int y, int board[8][8]);

// Program entry function
int main(void)
{

	// Print the title of the project
	puts("-----------========= Knight's Tour =========-----------");

	// Store the all the max moves each loop made
	int max_moves[1000];

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

	for (int loop = 0; loop != 1000; loop++)
	{
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

		// Store the amount of moves this board made
		max_moves[loop] = currentMove;

		// If it was higher then what we've seen before,
		// store the new board and score
		if (best_board_score < currentMove)
		{
			// Store the new best score
			best_board_score = currentMove;
			best_board_index = loop;

			// Replace the best board with the current board
			for (int _x = 0; _x != 8; _x++)
			{
				for (int _y = 0; _y != 8; _y++)
				{
					best_board[_x][_y] = board[_x][_y];
				}
			}
		}

		if (loop % 100 == 0) {
			printf("Finished %d/1000 loops\n", loop);
		}
	}

	// Print finished
	puts("Finished!");

	// Pretty print a table of all the runs
	puts("---------============ Table of All Runs ============---------");
	puts("    run -> moves    |    run -> moves    |    run -> moves    |    run -> moves    ");
	for (int i = 0; i != 250; i++)
	{
		printf("%6d  -> %4d     |%7d  -> %4d    |%7d  -> %4d    |%7d  -> %4d\n", i, max_moves[i], i + 250, max_moves[i + 250], i + 500, max_moves[i + 500], i + 750, max_moves[i + 750]);
	}

	// Print the best run index and count
	puts("\n\n");
	printf("The best iteration was found to be run %d with a total move count of %d!\n", best_board_index, best_board_score);

	// Print the moves made on the best table
	puts("The moves made on that board are:");
	printf("    0  1  2  3  4  5  6  7\n\n");
	for (int _x = 0; _x != 8; _x++)
	{
		printf("%d ", _x);
		for (int _y = 0; _y != 8; _y++)
		{
			printf("%3d", best_board[_x][_y]);
		}

		printf("\n\n");
	}
} // End entry function

int isValidMove(int x, int y, int board[8][8])
{
	// If the x,y is within 0 -> 7 AND the score of the spot isn't 0...
	return (0 <= x && x <= 7) && (0 <= y && y <= 7) && board[x][y] != 0;
}