//****************************************************************************
// File name:	Card.h
// Author:		Tyler Nakata
// Date:		  5/7/2021
// Class:		  CS 485
// Assignment:Blackjack
// Purpose:		Define a Card class
//****************************************************************************
#pragma once
#include <string>


enum class CardName {
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
	Ace,
};

enum class Suit : char {
	Diamonds,
	Hearts,
	Spades,
	Clubs,
};

class Card {
private:
	int mValue;
	Suit mSuit;
	CardName mCardName;

public: 
	Card();
	Card(int, Suit, CardName);
	~Card() {}
	CardName getCardName() { return mCardName; }
	Suit getSuit() { return mSuit; }
	int getValue() { return mValue; }
	void setValue(int);
};