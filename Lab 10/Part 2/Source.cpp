/*

// Name: -----	ID: -----

// ************************ PART 2 ************************

// Modify the pre_lab Card Shuffling and Dealing program you developed so that it deals a five-card poker hand. Then write functions to accomplish each of the following:

// a) Determine whether the hand contains a pair.

// b) Determine whether the hand contains two pairs.

// c) Determine whether the hand contains three of a kind(e.g., three jacks).

// d) Determine whether the hand contains four of a kind(e.g., four aces).

// e) Determine whether the hand contains a flush(i.e., all five cards of the same suit).

// f) Determine whether the hand contains a straight(i.e., five cards of consecutive face values).


#include <iostream>
#include <iomanip>
#include <random>
#include <time.h>

#include "DeckOfCards.h"
#include "Hand.h"


// Program entry function
int main(void)
{

	// Set random seed
	srand(time(NULL));

	// Print the title of the project (optional)
	std::cout << "-----------====== Card Shuffling and Dealing ======-----------" << std::endl;

	std::cout << "Defining DeckOfCards as deck" << std::endl;
	DeckOfCards deck = DeckOfCards();

	std::cout << "Printing current deck\n" << std::endl;

	// Print out all the cards
	for (int i = 0; i != 52; i++)
	{
		// setw and right are used to format the output
		std::cout << std::setw(20) << std::right << deck.nextCard().toString() << " | ";
		if (i % 4 == 3)
		{
			std::cout << std::endl;
		}
	}

	std::cout << "\nShuffling current current deck and drawing 5 cards" << std::endl;
	deck.shuffle();
	Hand hand = Hand(deck);

	std::cout << "Printing current hand\n" << std::endl;
	
	for (int i = 0; i != 5; i++)
	{
		// setw and right are used to format the output
		std::cout << std::setw(20) << std::right << hand.getCard(i).toString() << " | ";
		if (i % 2 == 1)
		{
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "\nChecking the hand..." << std::endl;
	hand.checkHand();

} // End entry function

*/