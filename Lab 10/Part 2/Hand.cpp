/*

#include "Hand.h"

#include <stdio.h>

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

*/