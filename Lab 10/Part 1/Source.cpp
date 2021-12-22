/*

// Name: -----	ID: -----

// ************************ PART 1 ************************

//  (Card Shuffling and Dealing) Create a program to shuffle and deal a deck of cards. The  
// program should consist of class Card, class DeckOfCardsand a driver program.Class Card should
// provide :

// a) Data members faceand suit of type int.
// b) A constructor that receives two ints representing the faceand suitand uses them to initialize
// the data members.
// c) Two static arrays of strings representing the facesand suits.
// d) A toString function that returns the Card as a string in the form “face of suit.” You
// can use the + operator to concatenate strings.
// Class DeckOfCards should contain :
// a) An array of Cards named deck to store the Cards.
// b) An integer currentCard representing the next card to deal.
// c) A default constructor that initializes the Cards in the deck.
// d) A shuffle function that shuffles the Cards in the deck.The shuffle algorithm should
// iterate through the array of Cards.For each Card, randomly select another Card in the
// deckand swap the two Cards.
// e) A dealCard function that returns the next Card object from the deck.
// f) A moreCards function that returns a bool value indicating whether there are more Cards
// to deal.


#include <iostream>
#include <iomanip>
#include <random>
#include <time.h>

#include "DeckOfCards.h"

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

	std::cout << "\nShuffling current current deck" << std::endl;
	deck.shuffle();
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

	std::cout << "\nChecking if there is any more cards available" << std::endl;

	if (deck.moreCards())
	{
		std::cout << "There ARE more cards avaiable" << std::endl;
	}
	else {
		std::cout << "There ARE NO more cards avaiable" << std::endl;
	}



} // End entry function

*/