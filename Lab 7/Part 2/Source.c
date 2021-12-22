// Name: -----	ID: -----

// ************************ PART 1 ************************

// (Card Shuffling and Dealing Modification)  Modify the card shuffling and dealing program so the 
// shufflingand dealing operations are performed by the same function(shuffle - AndDeal).The function
// should contain one nested looping structure that is similar to function shuffle in the card shufflingand
// dealing program.


// Fig. 7.24: fig07_24.c
// Card shuffling and dealing.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SUITS 4
#define FACES 13
#define CARDS 52


// prototypes
void shuffleAndDeal(const char* wFace[], const char* wSuit[]);

int main(void)
{


	srand((unsigned int)time(NULL)); // seed random-number generator


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

	shuffleAndDeal(face, suit); // deal the deck
}

// deal cards in deck
void shuffleAndDeal(const char* wFace[], const char* wSuit[])
{
	// initialize deck array
	unsigned int deck[SUITS][FACES] = { 0 };

	for (size_t card = 1; card <= CARDS; ++card) {

		size_t row; // row number
		size_t column; // column number

		// Find next open spot
		do {
			row = rand() % SUITS;
			column = rand() % FACES;

		} while (deck[row][column] != 0); // end do...while
		// place card number in chosen slot of deck
		deck[row][column] = card;

		// For 52 cards
		for (size_t spot = 0; spot < CARDS; ++spot) {
			
			// If the spot we are checking is the open spot we just found above, print the card in that spot
			if (deck[spot / FACES][spot % FACES] == card) {
				printf("%5s of %-8s%c", wFace[column], wSuit[row],
					card % 2 == 0 ? '\n' : '\t');
			}

		}

	}
}