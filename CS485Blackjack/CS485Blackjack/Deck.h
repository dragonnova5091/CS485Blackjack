//****************************************************************************
// File name:	Deck.h
// Author:		Tyler Nakata
// Date:		  5/7/2021
// Class:		  CS 485
// Assignment:Blackjack
// Purpose:		Define a Deck class
//****************************************************************************
#pragma once
#include "Card.h"
#include <vector>


class Deck {
private:
	int mNumOfSets;
	std::vector<Card> mCards;

public:
	Deck(); 
	Deck(int);
	~Deck() {}
	void shuffleDeck();
	void stackDeck();
	Card drawCard();
	int getSize() { return mCards.size(); }
	int getNumSets() { return mNumOfSets; }

};