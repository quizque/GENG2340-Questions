// Name: -----	ID: -----

// ************************ PART 4 ************************

// (Generating Mazes Randomly) Write a function mazeGenerator that takes as an argument a double - subscripted 12 - by - 12 character array and randomly produces a maze.The function should also provide the starting and ending locations of the maze.Try your function mazeTraverse from Pre_Lab Question 3 using several randomly generated mazes.



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mazeGenerate(int maze[][12]);
void printMaze(int maze[12][12]);
int validMove(int maze[12][12], int x, int y);


// Program start function
int main(void)
{
	srand((unsigned int)time(NULL));


	// Print the title of the project (optional)
	puts("--========= Random Maze Generator =========--");

	int maze[12][12];

	for (int i = 0; i != 12; i++)
	{
		for (int x = 0; x != 12; x++)
		{
			maze[i][x] = 1;
		}
	}

	//
	// NOTE: This question is very hard, why'd you only us 2 hours????
	//

	mazeGenerate(maze, 1, 1);
	printMaze(maze);

} // End start function

void printMaze(int maze[12][12])
{
	// Print the maze
	puts("\n");
	for (int x = 0; x != 12; x++)
	{
		for (int y = 0; y != 12; y++)
		{
			if (maze[x][y] == 1)
			{
				printf("%c ", '#');
			}
			else {
				printf("%c ", '.');
			}
		}
		puts("");
	}
}


void mazeGenerate(int maze[][12])
{
	// Generate maze using binary tree

	// Clear the first row
	for (int i = 1; i != 11; i++)
	{
		maze[1][i] = 0;
	}

	// Define that every other cell is open
	for (int y = 3; y < 11; y += 2)
	{
		for (int x = 1; x < 11; x += 2)
		{
			maze[y][x] = 0;
		}
	}

	// Create the enterence and exit
	maze[9][10] = 0;
	maze[9][11] = 0;
	maze[1][0] = 0;

	// For all open y cells
	for (int y = 1; y < 11; y += 2)
	{
		// Print the maze
		printMaze(maze);
		// For all open x cells
		for (int i = 1; i < 11; i += 2)
		{
			// Randomly choose to open the east or north cell
			int randDir = rand() % 2 == 0;

			if (randDir == 1 && maze[y + 1][i] == 1)
			{
				maze[y + 1][i] = 0;
			}
			else {
				maze[y][i + 1] = 0;
			}
		}
	}
}

int validMove(int maze[12][12], int x, int y)
{
	// If the position is outside out boundary
	if (!(0 <= x && x <= 11) || !(0 <= y && y <= 11))
	{
		return 0;
	}
	// If the position is a wall
	if (maze[y][x] == 0)
	{
		return 0;
	}

	// Otherwise, return that it is safe to move here
	return 1;
}