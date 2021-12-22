/*

#pragma once

#include "Card.h"
#include "DeckOfCards.h"

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

*/