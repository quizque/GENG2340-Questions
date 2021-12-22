// Name: -----	ID: -----

// ************************ PART 1 ************************

// (Card Shuffling and Dealing) Modify the card shuffling and dealing program in Lectur_7 so that the 
// card - dealing function deals a five - card poker hand.Then write the following additional functions :

// a) Determine if the hand contains a pair.
// b) Determine if the hand contains two pairs.
// c) Determine if the hand contains three of a kind(e.g., three jacks).
// d) Determine if the hand contains four of a kind(e.g., four aces).
// e) Determine if the hand contains a flush(i.e., all five cards of the same suit).
// f) Determine if the hand contains a straight(i.e., five cards of consecutive face values).// 


// Fig. 7.24: fig07_24.c
// Card shuffling and dealing.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SUITS 4
#define FACES 13
#define CARDS 52


// prototypes
void shuffle(unsigned int wDeck[][FACES]); // shuffling modifies wDeck
void deal(unsigned int wDeck[][FACES], const char* wFace[], const char* wSuit[], char* hand[][2]);
int checkForPair(char* hand[][2]);
int checkForTwoPair(char* hand[][2]);
int checkForThreeOfAKind(char* hand[][2]);
int checkForFourOfAKind(char* hand[][2]);
int checkForFlush(char* hand[][2]);
int checkForStraight(char* hand[][2], int ace_first);
void checkHand(char* hand[][2]);
int linearSearchRecursion(char* arr[], int size, char* target, int index);



int main(void)
{

	// initialize deck array
	unsigned int deck[SUITS][FACES] = { 0 };


	srand((unsigned int)time(NULL)); // seed random-number generator
	shuffle(deck); // shuffle the deck


	// initialize suit array
	const char* suit[SUITS] = { 
		"Hearts", "Diamonds", "Clubs", "Spades" 
	};

	// initialize face array
	const char* face[FACES] = { 
		"Two", "Three", "Four",
		"Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King", "Ace"
	};

	// Store the hand the player recives
	char* hand[5][2];

	deal(deck, face, suit, hand); // deal the deck

	// Print the hand drawn
	puts("\nThe hand contains the following: ");
	for (int i = 0; i != 5; i++)
	{
		printf(" -> %5s of %-8s\n", hand[i][0], hand[i][1]);
	}

	// Print any hands found in the deck
	checkHand(hand);
}

void checkHand(char* hand[][2])
{
	// Check the cards for possible hands
	// The order of these if statements are important as they are 
	// in order of "score" and prints the highest scoring pair found
	if (checkForFourOfAKind(hand))
	{
		puts("The hand contains a four of a kind!");
	}
	else if (checkForFlush(hand))
	{
		puts("The hand contains a flush!");
	}
	// This line checks for the edge case that the ace can be either be the
	// first or last card in terms of "worth"
	else if (checkForStraight(hand, 1) || checkForStraight(hand, 0))
	{
		puts("The hand contains a straight!");
	}
	else if (checkForThreeOfAKind(hand))
	{
		puts("The hand contains a three of a kind!");
	}
	else if (checkForTwoPair(hand))
	{
		puts("The hand contains a two pair!");
	}
	else if (checkForPair(hand))
	{
		puts("The hand contains a pair!");
	}
	else 
	{
		puts("Nothing was found in this hand!");
	}
}

int checkForStraight(char* hand[][2], int ace_first)
{
	// This code is a bit messy to deal with the fact that an
	// ace being 1 or 12 is a valid straight

	// Store the array we want to hold the right order of the face card
	// since the ace could be in the front or back of the order
	char* face[FACES];

	// This array is used to setup the face array
	char* tmp[FACES] = {
		"Ace", "Two", "Three", "Four",
		"Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King"
	};
	
	// If we are checking to see if the ace is in the front
	if (ace_first) {
		// Store all the cards in default order 
		for (int i = 0; i != 13; i++)
		{
			face[i] = tmp[i];
		}
	}
	// Otherwise
	else {
		// Store all the cards in default order EXCEPT the ace
		for (int i = 1; i != 13; i++)
		{
			face[i-1] = tmp[i];
		}
		// 
		face[12] = tmp[0];
	}

	// Get lowest value card
	int lowest_value = linearSearchRecursion(face, 13, hand[0][0], 0);

	// For all the cards in the deck
	for (int i = 1; i != 5; i++)
	{
		// Get its card "worth"
		int card_value = linearSearchRecursion(face, 13, hand[i][0], 0);
		// If it is worth less that our lowest worth card, store it
		if (lowest_value > card_value)
		{
			lowest_value = card_value;
		}
	}

	// Now that we have our lowest card, check to see if we have sequencial cards

	// Store all the face values of our card
	char* hand_face[5];

	// For all the cards in our hand, store only the face number in the array
	for (int i = 0; i != 5; i++)
	{
		hand_face[i] = hand[i][0];
	}

	// For the next four values
	for (int i = 0; i != 4; i++)
	{
		// Get what card should come after our lowest
		lowest_value += 1;
		// If its out of bounds, return 0
		if (lowest_value == 13)
		{
			return 0;
		}
		// Check to see if the next card that should come after our lowest is in our hand
		int card_value = linearSearchRecursion(hand_face, 5, face[lowest_value], 0);
		// If its not, return 0
		if (card_value == -1)
		{
			return 0;
		}
		// Otherwise, check the next numbers in the hand sequenctially four times
	}

	// If we found 5 sequential numbers, return 1
	return 1;
}

int checkForFlush(char* hand[][2])
{
	// For all the card in the deck
	for (int card = 0; card != 5; card++)
	{
		// Store the pair found
		int pairCount = 0;

		for (int checking = card + 1; checking != 5; checking++)
		{
			// If the suit is the same as what we are checking
			if (hand[card][1] == hand[checking][1])
			{
				// Increment the counter
				pairCount++;

				// If all cards have the same suit, return 1
				if (pairCount == 4)
				{
					return 1;
				}
			}
		}
	}

	return 0;
}

int checkForFourOfAKind(char* hand[][2])
{
	// For all the card in the hand
	for (int card = 0; card != 5; card++)
	{
		// Store the count of cards
		int pairCount = 0;

		for (int checking = card + 1; checking != 5; checking++)
		{
			// If the card we are checking has another card of face value
			if (hand[card][0] == hand[checking][0])
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

int checkForThreeOfAKind(char* hand[][2])
{
	// For all the cars in the deck
	for (int card = 0; card != 5; card++)
	{
		// Store the count of cards
		int pairCount = 0;

		for (int checking = card + 1; checking != 5; checking++)
		{
			// If the card we are checking has another card of face value
			if (hand[card][0] == hand[checking][0])
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

int checkForTwoPair(char* hand[][2])
{
	// Store the pairs found
	int pairCount = 0;

	// For all the cards in the deck
	for (int card = 0; card != 5; card++)
	{
		for (int checking = card + 1; checking != 5; checking++)
		{
			// If we found another face card of same value, increment pair cound
			if (hand[card][0] == hand[checking][0])
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

int checkForPair(char* hand[][2])
{
	// Check every card for another card of the same face
	for (int card = 0; card != 5; card++)
	{
		for (int checking = card + 1; checking != 5; checking++)
		{
			// If found, return 1
			if (hand[card][0] == hand[checking][0])
			{
				return 1;
			}
		}
	}

	// Otherwise, return 0
	return 0;
}

int linearSearchRecursion(char* arr[], int size, char* target, int index)
{
	// If the index we are checking is the target, return
	if (arr[index] == target)
	{
		return index;
	}
	// Otherwise, if we reached the end, return -1 (not found)
	else if (index == size)
	{
		return -1;
	}
	// Finally, if we havn't reached the end or found it, increase the index by one
	else {
		return linearSearchRecursion(arr, size, target, index + 1);
	}
}

// shuffle cards in deck
void shuffle(unsigned int wDeck[][FACES])
{
	// for each of the cards, choose slot of deck randomly
	for (size_t card = 1; card <= CARDS; ++card) {
		size_t row; // row number
		size_t column; // column number


			// choose new random location until unoccupied slot found
		do {
			row = rand() % SUITS;
			column = rand() % FACES;

		} while (wDeck[row][column] != 0); // end do...while
			 // place card number in chosen slot of deck
		wDeck[row][column] = card;

	}
}

// deal cards in deck
void deal(unsigned int wDeck[][FACES], const char* wFace[], const char* wSuit[], char* hand[][2])
{
	// Keep track of 5 cards
	int index = 0;

	// deal each of the cards but only 5 times
	for (size_t card = 1; card <= 5; ++card) {
		// loop through rows of wDeck
		for (size_t row = 0; row < SUITS; ++row) {
			// loop through columns of wDeck for current row
			for (size_t column = 0; column < FACES; ++column) {
				// if slot contains current card, display card
				if (wDeck[row][column] == card) {
					// Store the card in the hand
					hand[index][0] = (char*)wFace[column];
					hand[index][1] = (char*)wSuit[row];
					// Increment the index we store
					index++;
				}
			}

		}

	}
}