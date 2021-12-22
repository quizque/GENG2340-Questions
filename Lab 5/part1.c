// Name: -----	ID: -----

// ************************ PART 1 ************************

//  (Knight’s Tour) One of the more interesting puzzlers for chess buffs is the Knight’s Tour problem, originally proposed 
// by the mathematician Euler.The question is this: Can the chess piece called the knight move around an empty chessboard
// and touch each of the 64 squares once and only once ? We study this intriguing problem in depth here.

// Write a version of the Knight’s Tour program using a double-subscripted accessibility array. At any time, the knight should 
// move to the square with the lowest accessibility number.In case of a tie, the knight may move to any of the tied squares.[Note:
// As the knight moves around the chessboard, your program should reduce the accessibility numbers as more and more squares
// become occupied.In this way, at any given time during the tour, each available square’s accessibility number will remain equal
// to precisely the number of squares from which that square may be reached.

// Run the program 64 times, one from each square of the chessboard.Determine and print the moves on the chessboard for each
// run separately.How many full tours did you get(a full tour consists of 64 moves) ?


#include <stdio.h>

int isValidMove(int x, int y, int board[8][8]);

// Program entry function
int main(void)
{

	// Print the title of the project
	puts("-----------========= Knight's Tour =========-----------");

	// Store the total number of full tours and unfinished tours
	int full_tours = 0;
	int unfinished_tours = 0;

	// For every possible possition in an 8x8 grid
	for (int curr_iter = 0; curr_iter != 64; curr_iter++)
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
		int x = curr_iter / 8;
		int y = curr_iter % 8;

		// Store the current best move
		int currentMove = 0;

		// Print the position we are currently working on
		printf("****** Starting Knights Tour from { %2d, %2d  } ******\n", x, y);

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

			// For all the possible move positons
			for (int i = 0; i != 8; i++)
			{
				// Get the new x and y positon
				int test_x = x + moves[i][0];
				int test_y = y + moves[i][1];

				// Check to make sure it is a valid pos
				if (isValidMove(test_x, test_y, accessibility))
				{
					// Subtract a score to from the accessability table
					// since the spot we are on will no longer
					// be accessable
					accessibility[test_x][test_y] -= 1;

					// If the current spot has a better score then
					// what we currently have
					if (accessibility[test_x][test_y] < best_score)
					{
						// Set the new best score and direction
						best_score = accessibility[test_x][test_y];
						best_direction = i;
					}
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

		// Print the total moves we ended in
		printf("The tour ended with a total of %d moves.\n", currentMove);

		// If the current moves is 64, we have a full tour
		if (currentMove == 64)
		{
			full_tours += 1;
			printf("This tour was a full tour!\n\n");
		}
		// Otherwise, we didn't complete a full tour
		else {
			unfinished_tours += 1;
			printf("This tour was NOT a full tour!\n\n");
		}

		// Print the total number of unfinished and finished tours
		printf("Total number of Full Tours: %d\n", full_tours);
		printf("Total number of Unfinished Tours: %d\n\n", unfinished_tours);

		// Print the moves we made this tour
		printf("The moves this tour made are:\n");

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
		//return 0;
	}


} // End entry function


int isValidMove(int x, int y, int board[8][8])
{
	// If the x,y is within 0 -> 7 AND the score of the spot isn't 0...
	return (0 <= x && x <= 7) && (0 <= y && y <= 7) && board[x][y] != 0;
}