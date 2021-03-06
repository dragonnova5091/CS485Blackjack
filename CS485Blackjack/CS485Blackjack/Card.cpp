//****************************************************************************
// File name:	Card.cpp
// Author:		Tyler Nakata
// Date:		  5/7/2021
// Class:		  CS 485
// Assignment:Blackjack
// Purpose:		Card
//****************************************************************************
#include "Card.h"

//***************************************************************************
// Constructor:   Card
//
// Description:		Creates a card with arbitrary values @Ethan
//
// Parameters:		None
//
// Returned:			None
//***************************************************************************
Card::Card()
{
	mValue = 2;
	mSuit = Suit::Diamonds;
	mCardName = CardName::Two;
}

//***************************************************************************
// Constructor:   Card
//
// Description:		Creates a card with given values
//
// Parameters:		value			- value of the card
//								suit			- suit of the card
//								cardName	- name of the card
//
// Returned:			None
//***************************************************************************
Card::Card(int value, Suit suit, CardName cardName) {
	mValue = value;
	mSuit = suit;
	mCardName = cardName;
}

//***************************************************************************
// Constructor:   setValue
//
// Description:		sets the card value
//
// Parameters:		value	- value to change the card to
//								
//
// Returned:			None
//***************************************************************************
void Card::setValue(int value) {
	mValue = value;
}
