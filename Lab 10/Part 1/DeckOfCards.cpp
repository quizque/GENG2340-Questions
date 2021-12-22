/*

#include "DeckOfCards.h"

#include <random>
#include <time.h>

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

*/