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
	CardName getCardName() { return mCardName; }
	Suit getSuit() { return mSuit; }
	int getValue() { return mValue; }
};