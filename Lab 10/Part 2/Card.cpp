/*

#include "Card.h"

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

*/