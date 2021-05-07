//****************************************************************************
// File name:	Deck.cpp
// Author:		Tyler Nakata
// Date:		  5/7/2021
// Class:		  CS 485
// Assignment:Blackjack
// Purpose:		Deck
//****************************************************************************
#include "Deck.h"
#include "Card.h"
#include <algorithm>
#include <ctime>


//***************************************************************************
// Constructor:   Deck
//
// Description:		Initialize a Deck with a single set
//
// Parameters:		None
//
// Returned:			None
//***************************************************************************
Deck::Deck() {
	mNumOfSets = 1;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			if (j >= 9 && j < 12) {
				mCards.push_back(Card(10, (Suit)i, (CardName)j));
			}
			else if (j == 12) {
				mCards.push_back(Card(11, (Suit)i, (CardName)j));
			}
			else {
				mCards.push_back(Card(j + 2, (Suit)i, (CardName)j));
			}
		}
	}

	shuffleDeck();
}

//***************************************************************************
// Constructor:   Deck
//
// Description:		Initialize a Deck with a given number of sets
//
// Parameters:		numSets - number of sets
//
// Returned:			None
//***************************************************************************
Deck::Deck(int numSets) {
	mNumOfSets = numSets;
	for (int h = 0; h < mNumOfSets; h++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 13; j++) {
				if (j >= 9 && j < 12) {
					mCards.push_back(Card(10, (Suit)i, (CardName)j));
				}
				else if (j == 12) {
					mCards.push_back(Card(11, (Suit)i, (CardName)j));
				}
				else {
					mCards.push_back(Card(j + 2, (Suit)i, (CardName)j));
				}
			}
		}
	}
	shuffleDeck();
}

//***************************************************************************
// Function:    shuffleDeck
//
// Description: Algorithm to randomly shuffle a deck
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void Deck::shuffleDeck() {
	std::srand(std::time(NULL));
	for (int i = mCards.size() - 1; i > 0; i--) {
		int numCards = i;
		int randPos = (int)std::rand() % numCards;
		Card temp = mCards.at(i);
		mCards.at(i) = mCards.at(randPos);
		mCards.at(randPos) = temp;
	}
}

//***************************************************************************
// Function:    stackDeck
//
// Description: Stacks a deck to have true blackjack, blackjack, lose, win,
//							and bust for 4 players
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void Deck::stackDeck() {
	mCards.push_back(Card(10, Suit::Clubs, CardName::Queen));
	mCards.push_back(Card(10, Suit::Spades, CardName::Five));
	mCards.push_back(Card(6, Suit::Spades, CardName::Six));
	mCards.push_back(Card(9, Suit::Hearts, CardName::Nine));
	mCards.push_back(Card(5, Suit::Clubs, CardName::Five));
	mCards.push_back(Card(5, Suit::Diamonds, CardName::Five));
	mCards.push_back(Card(7, Suit::Diamonds, CardName::Seven));
	mCards.push_back(Card(8, Suit::Diamonds, CardName::Eight));
	mCards.push_back(Card(10, Suit::Clubs, CardName::Ten));
	mCards.push_back(Card(9, Suit::Clubs, CardName::Nine));
	mCards.push_back(Card(11, Suit::Hearts, CardName::Ace));
	mCards.push_back(Card(10, Suit::Hearts, CardName::Ten));
	mCards.push_back(Card(11, Suit::Spades, CardName::Ace));
	mCards.push_back(Card(10, Suit::Diamonds, CardName::Ten));
	mCards.push_back(Card(7, Suit::Clubs, CardName::Seven));
	mCards.push_back(Card(10, Suit::Hearts, CardName::King));
}

//***************************************************************************
// Function:    drawCard
//
// Description: Removes a card from the deck and returns it
//
// Parameters:  None
//
// Returned:    c - card to be dealt
//***************************************************************************
Card Deck::drawCard() {
	Card c = mCards.back();
	mCards.pop_back();
	return c;

}
