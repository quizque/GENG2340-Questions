
/*
#include "TicTacToe.h"

#include <iostream>

TicTacToe::TicTacToe()
	: m_current_player(0)
{
	// Set the entire board to zero
	for (int i = 0; i != 3; i++)
	{
		for (int j = 0; j != 3; j++)
		{
			m_board[i][j] = 0;
		}
	}
}

int TicTacToe::checkWin() const
{
	// Check horizontal and vertical cells for if they are all the same value
	for (int i = 0; i != 3; i++)
	{
		if (m_board[i][0] == m_board[i][1] &&
			m_board[i][0] == m_board[i][2] &&
			m_board[i][0] != 0)
		{
			return m_board[i][0];
		}
		if (m_board[0][i] == m_board[1][i] &&
			m_board[0][i] == m_board[2][i] &&
			m_board[0][i] != 0)
		{
			return m_board[i][0];
		}
	}

	// Check diagonal (top left -> bottom right)
	if (m_board[0][0] == m_board[1][1] &&
		m_board[0][0] == m_board[2][2] &&
		m_board[0][0] != 0)
	{
		return m_board[0][0];
	}

	// Check diagonal (bottom left -> top right)
	if (m_board[2][0] == m_board[1][1] &&
		m_board[2][0] == m_board[0][2] &&
		m_board[2][0] != 0)
	{
		return m_board[2][0];
	}

	// For every element in the array
	for (int i = 0; i != 3; i++)
	{
		for (int j = 0; j != 3; j++)
		{
			// If an element is zero, return 0
			// This means a move is still possible
			if (m_board[i][j] == 0)
			{
				return 0;
			}
		}
	}

	// Otherwise, the board is full and no more moves can be made (tie)
	return -1;
}

bool TicTacToe::getNextMove()
{
	// Store the next move
	char next_move;
	
	// Ask for next move
	std::cout << "Enter next move (a, b, c, etc.): ";
	std::cin >> next_move;

	// Get the index of the next move
	int i = (int)(next_move - 'a') / 3;
	int j = (int)(next_move - 'a') % 3;

	// If that part of the board is 0 (meaning its open)
	if (m_board[i][j] == 0)
	{
		// Store the current player
		m_board[i][j] = getCurrentPlayer();
		// Change the current player
		m_current_player = !m_current_player;
		// Return true meaning that the move was valid
		return true;
	}

	// Otherwise, return false, meaning that the move was NOT valid
	return false;
}

void TicTacToe::printBoard() const
{
	// For all x values
	for (int i = 0; i != 3; i++)
	{
		// If we aren't the first row, print a line
		if (i != 0)
		{
			std::cout << "----------------------" << std::endl;
		}

		// For all y values
		for (int j = 0; j != 3; j++)
		{
			// print a spacer
			std::cout << "   ";

			// If that part of the board is 0, print the character repersenttion of that part instead
			if (m_board[i][j] == 0)
			{
				std::cout << (char)((i * 3 + j) + 'a');
			}
			// Otherwise, print the player that is currently in that spot
			else {
				std::cout << m_board[i][j];
			}
			
			// If we aren't the final number in that row, add a wall
			if (j != 2)
			{
				std::cout << "   |";
			}
		}
		// Newline
		std::cout << std::endl;
	}
}

int TicTacToe::getCurrentPlayer() const
{
	// Return the current player + 1 (because we store it as 1/0 but we want it as 1/2)
	return m_current_player + 1;
}
*/