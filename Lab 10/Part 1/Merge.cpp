///
///
/// Card.h
/// 
/// 

//#pragma once

#include <iostream>

class Card
{
public:
	static const std::string faces[13];
	static const std::string suits[4];

	explicit Card(int face = 0, int suit = 0);

	std::string toString() const;

private:
	int m_face;
	int m_suit;
};

///
///
/// Card.cpp
/// 
/// 

//#include "Card.h"

#include <string>

const std::string Card::faces[13] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
const std::string Card::suits[4] = { "Clubs", "Spades", "Hearts", "Diamonds" };

Card::Card(int face, int suit)
	: m_face(face),
	m_suit(suit)
{
}

std::string Card::toString() const
{
	return faces[m_face] + " of " + suits[m_suit];
}



///
///
/// DeckOfCards.h
/// 
/// 

//#pragma once

//#include "Card.h"

class DeckOfCards
{
public:
	explicit DeckOfCards();

	void shuffle();
	Card nextCard();
	bool moreCards();

private:

	Card m_deck[52];
	int m_currentCard;

};



///
///
/// DeckOfCards.cpp
/// 
/// 

//#include "DeckOfCards.h"

DeckOfCards::DeckOfCards()
	: m_currentCard(0)
{
	for (int suit = 0; suit != 4; suit++)
	{
		for (int face = 0; face != 13; face++)
		{
			// Assign all 52 cards in the deck
			m_deck[suit * 13 + face] = Card(face, suit);
		}
	}
}

void DeckOfCards::shuffle()
{
	// Reset the current card counter
	m_currentCard = 0;

	// For every card in the array
	for (int i = 0; i != 52; i++)
	{
		// Get the next card
		Card swap_a = m_deck[i];
		// Get a random card somewhere in the deck
		int new_spot = rand() % 52;
		Card swap_b = m_deck[new_spot];

		// Swap spots
		m_deck[i] = swap_b;
		m_deck[new_spot] = swap_a;
	}
}

Card DeckOfCards::nextCard()
{
	// Get next card and then increment the card counter
	return m_deck[m_currentCard++];
}

bool DeckOfCards::moreCards()
{
	// Return true if currentCard is below 52
	return m_currentCard < 52;
}


///
///
/// Source.cpp
/// 
/// 

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


//#include <iostream>
#include <iomanip>
#include <random>
#include <time.h>

//#include "DeckOfCards.h"

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