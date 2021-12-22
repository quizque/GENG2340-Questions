// Name: -----	ID: -----

// ************************ PART 3 ************************

// (Maze Traversal) The following grid is a double-subscripted array representation of a maze. 
 
  
// The # symbols represent the walls of the maze, and the periods(.) represent squares in the possible
// paths through the maze.
// There  is  a  simple  algorithm  for  walking  through  a  maze  that  guarantees  finding  the  exit(assuming
// there is an exit).If there is not an exit, you’ll arrive at the starting location again.Place your right hand
// on  the  wall  to  your  rightand begin  walking  forward.Never  remove  your  hand  from  the  wall.If  the
// maze turns to the right, you follow the wall to the right.As long as you do not remove your hand from
// the wall, eventually you’ll arrive at the exit of the maze.There may be a shorter path than the one you
// have taken, but you’re guaranteed to get out of the maze.Write recursive function mazeTraverse  to
// walk  through  the  maze.The  function  should  receive  as  arguments  a  12 - by - 12  character  array
// representing the maze and the starting location of the maze.As mazeTraverse  attempts to locate the
// exit  from  the  maze, it  should  place  the  character  X  in  each  square  in  the  path.The  function  should
// display the maze after each move so the user can watch as the maze is solved.


#include <stdio.h>

// Define directions
#define DIR_NORTH 0
#define DIR_EAST 1
#define DIR_SOUTH 2
#define DIR_WEST 3

// Define function signitures
void mazeTraverse(char maze[12][12], int pos[2], int previous_pos[2], int heading);
int validMove(char maze[12][12], int pos[2], int prev_pos[2]);
void printMaze(char maze[12][12], int pos[2]);


// Program entry function
int main(void)
{

	// Print the title of the project
	puts("----------========= Maze Traversal - Right Wall Follow =========----------");
	puts("Following right wall...");

	// This maze will be indexed by { y, x }
	// Otherwise, print what is in the maze right now
	// # - Wall
	// X - Previous position - moveable
	// . - Empty spot - movable
	char maze[12][12] = { 
		{ "############" },
		{ "#...#......#" },
		{ "..#.#.####.#" },
		{ "###.#....#.#" },
		{ "#....###.#.." },
		{ "####.#.#.#.#" },
		{ "#..#.#.#.#.#" },
		{ "##.#.#.#.#.#" },
		{ "#........#.#" },
		{ "######.###.#" },
		{ "#......#...#" },
		{ "############" },
	};

	// Define where we start
	int start_pos[2] = { 2, 0 };

	
	///
	/// NOTE: The information prints have been left in so you can
	///		  understand what is going with every move. Directions
	///       can be found out by looking at the definitons above
	///		  the main function
	///

	// Call the recursive function
	mazeTraverse(maze, start_pos, start_pos, DIR_EAST);

	// Once we are are at an exit, print that we are
	puts("An exit has been located!");
	puts("# - Wall");
	puts(". - Empty space (moveable)");
	puts("X - Previous positon (moveable)");

} // End entry function

void mazeTraverse(char maze[12][12], int pos[2], int previous_pos[2], int heading)
{
	// NOTE: position is in { Y, X }
	// { Y, X }
	
	// Define the possible movements
	int moves[4][2] = {
		{ -1, 0 }, // north
		{ 0, 1 }, // east
		{ 1, 0 },  // south
		{ 0, -1 }, // west
	};

	// Print the current heading
	printf("[INFO] Current dir %d \n", heading);

	//
	// Check if we found an exit
	//

	// Define a varible that forcefully checks forward, reguardless if its valid or not
	int force_forward[2] = { pos[0] + moves[heading][0], pos[1] + moves[heading][1] };
	// Check if it out of bounds of our 12x12 grid
	if (force_forward[0] == -1 || force_forward[0] == 12 || force_forward[1] == 12 || force_forward[1] == -1)
	{
		// Print the maze and then leave the function
		printMaze(maze, pos);
		return;
	}

	//
	/////////////// Check relative right ///////////////
	//

	// Get the position to our right relative to our heading
	int pos_right[2] = { pos[0] + moves[(heading + 1) % 4][0], pos[1] + moves[(heading + 1) % 4][1] };
	// Check if is moveable
	if (validMove(maze, pos_right, previous_pos))
	{
		// Print that we are turning right
		puts("[EXEC] Turn right");
		// Run the function again but facing 90 degrees to the right
		mazeTraverse(maze, pos, previous_pos, (heading + 1) % 4);
		return;
	}

	//
	/////////////// Check forward ///////////////
	//

	// Get the position to our front relative to our heading
	int pos_forward[2] = { pos[0] + moves[heading][0], pos[1] + moves[heading][1] };
	// Check if is moveable
	if (validMove(maze, pos_forward, previous_pos))
	{
		// Print that we are moving forward
		puts("[EXEC] Move forward");
		// Print the maze
		printMaze(maze, pos);
		// Set the x in the maze defining that we where here
		maze[pos[0]][pos[1]] = 'X';
		// Call the function again with our new position
		mazeTraverse(maze, pos_forward, pos, heading);
		return;
	}

	//
	/////////////// Check relative left ///////////////
	//

	// Get the position to our left relative to our heading
	int pos_left[2] = { pos[0] + moves[(heading + 3) % 4][0], pos[1] + moves[(heading + 3) % 4][1] };
	// Check if is moveable
	if (validMove(maze, pos_left, previous_pos))
	{
		// Print that we are turning left
		puts("[EXEC] Turn left");
		// Run the function again but facing 90 degrees to the left
		mazeTraverse(maze, pos, previous_pos, (heading + 3) % 4);
		return;
	}

	// If none of the if statements above trigged, we hit a dead end
	// Turn round and go the other direction
	mazeTraverse(maze, pos, pos, (heading + 2) % 4);
}


int validMove(char maze[12][12], int pos[2], int prev_pos[2])
{
	// If the position is outside out boundary
	if (!(0 <= pos[0] && pos[0] <= 11) && !(0 <= pos[1] && pos[1] <= 11))
	{
		return 0;
	}
	// If the position is a wall
	if (maze[pos[0]][pos[1]] == '#')
	{
		return 0;
	}
	// If the positon is where we already where
	if (pos[0] == prev_pos[0] && pos[1] == prev_pos[1])
	{
		return 0;
	}

	// Otherwise, return that it is safe to move here
	return 1;
}

void printMaze(char maze[12][12], int pos[2])
{
	// Print a new line
	puts(" ");

	// For all the y and x values
	for (int y = 0; y != 12; y++)
	{
		for (int x = 0; x != 12; x++)
		{
			// If it where we currently are, print an O
			if (x == pos[1] && y == pos[0])
			{
				printf("O ");
			}
			// Otherwise, print what is in the maze right now
			// # - Wall
			// X - Previous position - moveable
			// . - Empty spot - movable
			else
			{
				printf("%c ", maze[y][x]);
			}
		}

		// Print a new line
		puts("");
	}
}