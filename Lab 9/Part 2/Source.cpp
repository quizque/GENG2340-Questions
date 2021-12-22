/*

// Name: -----	ID: -----

// ************************ PART 2 ************************

// (TicTacToe Class) Create a class TicTacToe that will enable you to write a complete program to play 
// the game of tic - tac - toe.The class contains as private data a 3 - by - 3 two - dimensional array of integers.
// The  constructor  should  initialize  the  empty  board  to  all  zeros.Allow  two  human  players.Wherever
// the first player moves, place a 1 in the specified square.Place a 2 wherever the second player moves.
// Each move must be to an empty square.After each move, determine whether the game has been won
// or is a draw

#include <iostream>
#include "TicTacToe.h"

// Program entry function
int main(void)
{

	// Print the title of the project (optional)
	std::cout << "-----------====== TicTacToe Class ======-----------" << std::endl;

	TicTacToe game = TicTacToe();

	while (game.checkWin() == 0)
	{
		std::cout << "\n\n\nIt is currently player " << game.getCurrentPlayer() << "'s turn!" << std::endl;
		game.printBoard();
		
		// If it wasn't a valid move
		if (!game.getNextMove())
		{
			std::cout << "That move was invalid!! Try again..." << std::endl;
		}
	}

	if (game.checkWin() == -1)
	{
		std::cout << "\n\n\nThats game! Its a tie!" << std::endl;
		game.printBoard();
	}
	else {
		std::cout << "\n\n\nThats game! Player " << game.checkWin() << " wins!" << std::endl;
		game.printBoard();
	}

	

} // End entry function


*/