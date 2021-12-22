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

	int getFace();
	int getSuit();

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

int Card::getFace()
{
	return m_face;
}

int Card::getSuit()
{
	return m_suit;
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
	Card& nextCard();
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

#include <random>

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

Card& DeckOfCards::nextCard()
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
/// Hand.h
/// 
///

//#pragma once

//#include "Card.h"
//#include "DeckOfCards.h"

class Hand
{
public:
	explicit Hand(DeckOfCards& deck);

	void checkHand();

	Card& getCard(int index);

private:

	int checkForStraight();
	int checkForFlush();
	int checkForFourOfAKind();
	int checkForThreeOfAKind();
	int checkForTwoPair();
	int checkForPair();

	Card m_hand[5];
};

///
///
/// Hand.cpp
/// 
///

//#include "Hand.h"

//#include <stdio.h>

Hand::Hand(DeckOfCards& deck)
{
	for (int i = 0; i != 5; i++)
	{
		m_hand[i] = deck.nextCard();
	}
}

void Hand::checkHand()
{
	// Check the cards for possible hands
	// The order of these if statements are important as they are 
	// in order of "score" and prints the highest scoring pair found
	if (checkForFourOfAKind())
	{
		puts("The hand contains a four of a kind!");
	}
	else if (checkForFlush())
	{
		puts("The hand contains a flush!");
	}
	// This line checks for the edge case that the ace can be either be the
	// first or last card in terms of "worth"
	else if (checkForStraight())
	{
		puts("The hand contains a straight!");
	}
	else if (checkForThreeOfAKind())
	{
		puts("The hand contains a three of a kind!");
	}
	else if (checkForTwoPair())
	{
		puts("The hand contains a two pair!");
	}
	else if (checkForPair())
	{
		puts("The hand contains a pair!");
	}
	else
	{
		puts("Nothing was found in this hand!");
	}
}

Card& Hand::getCard(int index)
{
	return m_hand[index];
}

int Hand::checkForStraight()
{
	// Get lowest card	

	Card lowest_card = m_hand[0];

	for (int i = 1; i != 5; i++)
	{
		if (m_hand[i].getFace() <= lowest_card.getFace())
		{
			lowest_card = m_hand[i];
		}
	}

	// Check if they are in order
	int next_card_to_find = lowest_card.getFace() + 1;
	int count = 1;

	for (int i = 0; i != 5; i++)
	{
		if (next_card_to_find == m_hand[i].getFace())
		{
			next_card_to_find++;
			count++;
			continue;
		}
	}

	if (count == 5)
	{
		return 1;
	}
	else {
		return 0;
	}
}

int Hand::checkForFlush()
{
	// For all the card in the deck
	for (int card = 1; card != 5; card++)
	{
		// If the suit is the same as what we are checking
		if (m_hand[0].getFace() != m_hand[card].getFace())
		{
			return 0;
		}
	}

	return 1;
}

int Hand::checkForFourOfAKind()
{
	// For all the card in the hand
	for (int card = 0; card != 5; card++)
	{
		// Store the count of cards
		int pairCount = 0;

		for (int checking = card + 1; checking != 5; checking++)
		{
			// If the card we are checking has another card of face value
			if (m_hand[card].getFace() == m_hand[checking].getFace())
			{
				// Increment the counter
				pairCount++;

				// If we found 4 of the same card, return 1
				if (pairCount == 3)
				{
					return 1;
				}
			}
		}
	}

	return 0;
}

int Hand::checkForThreeOfAKind()
{
	// For all the cars in the deck
	for (int card = 0; card != 5; card++)
	{
		// Store the count of cards
		int pairCount = 0;

		for (int checking = card + 1; checking != 5; checking++)
		{
			// If the card we are checking has another card of face value
			if (m_hand[card].getFace() == m_hand[checking].getFace())
			{
				// Increment the counter
				pairCount++;

				// If we found 3 of the same card, return 1
				if (pairCount == 2)
				{
					return 1;
				}
			}
		}
	}

	return 0;
}

int Hand::checkForTwoPair()
{
	// Store the pairs found
	int pairCount = 0;

	// For all the cards in the deck
	for (int card = 0; card != 5; card++)
	{
		for (int checking = card + 1; checking != 5; checking++)
		{
			// If we found another face card of same value, increment pair cound
			if (m_hand[card].getFace() == m_hand[checking].getFace())
			{
				pairCount++;

				// Return 1 if we found 2 pairs
				if (pairCount == 2)
				{
					return 1;
				}

				break;
			}
		}
	}

	return 0;
}

int Hand::checkForPair()
{
	// Check every card for another card of the same face
	for (int card = 0; card != 5; card++)
	{
		for (int checking = card + 1; checking != 5; checking++)
		{
			// If found, return 1
			if (m_hand[card].getFace() == m_hand[checking].getFace())
			{
				return 1;
			}
		}
	}

	// Otherwise, return 0
	return 0;
}

///
///
/// Source.cpp
/// 
///


// Name: -----	ID: -----

// ************************ PART 2 ************************

// Modify the pre_lab Card Shuffling and Dealing program you developed so that it deals a five-card poker hand. Then write functions to accomplish each of the following:

// a) Determine whether the hand contains a pair.

// b) Determine whether the hand contains two pairs.

// c) Determine whether the hand contains three of a kind(e.g., three jacks).

// d) Determine whether the hand contains four of a kind(e.g., four aces).

// e) Determine whether the hand contains a flush(i.e., all five cards of the same suit).

// f) Determine whether the hand contains a straight(i.e., five cards of consecutive face values).


//#include <iostream>
#include <iomanip>
//#include <random>
#include <time.h>

//#include "DeckOfCards.h"
//#include "Hand.h"


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