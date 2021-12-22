//Name: Hunter Thomas		//ID: 110034583
#include <stdio.h>
// Fig. 7.24: fig07_24.c
// Card shuffling and dealing.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

// prototypes
void shuffle(unsigned int wDeck[SUITS][FACES]); // shuffling modifies wDeck
void deal(unsigned int wDeck[][FACES], const char* wFace[], const char* wSuit[], int pHand[][2]); // dealing doesn't modify the arrays
void pair(int pHand[][2], const char* wFace[]);

int main(void)
{
	// initialize deck array
	unsigned int deck[SUITS][FACES] = { 0 };
	srand(time(NULL)); // seed random-number generator
	shuffle(deck); // shuffle the deck

	// initialize suit array
	const char* suit[SUITS] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	// initialize face array
	const char* face[FACES] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

	// initialize the poker hand 
	int poker[5][2];
	deal(deck, face, suit, poker); // deal the deck
	pair(poker, face);
}

// shuffle cards in deck
void shuffle(unsigned int wDeck[SUITS][FACES])
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
void deal(unsigned int wDeck[SUITS][FACES], const char* wFace[], const char* wSuit[], int pHand[5][2])
{
	// deal each of the cards
	for (int card = 1; card <= 5; card++) { //Edited for loop to print only 5 cards
		// loop through rows of wDeck
		for (size_t row = 0; row < SUITS; ++row) {
			// loop through columns of wDeck for current row
			for (size_t column = 0; column < FACES; ++column) {
				// if slot contains current card, display card
				if (wDeck[row][column] == card) {
					pHand[card - 1][0] = row;
					pHand[card - 1][1] = column;
					printf("%5s of %-8s\n", wFace[column], wSuit[row]);
				}
			}
		}
	}
}

void pair(int pHand[5][2], const char* wFace[]) {
	int p[FACES] = { 0 };
	for (int i = 0; i != 5; i++) {
		++p[pHand[i][1]];
	}
	for (int search = 0; search < 13; search++) {
		if (p[search] == 2) {
			printf("Pair of &s\n", wFace[search]);
		}
	}
}