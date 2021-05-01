#pragma once
#include <string>


enum class CardName {
	Ace,
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
};

enum class Suit : char {
	Diamond,
	Hearts,
	Spades,
	Clover,
};

class Card {
private:
	int mValue;
	Suit mSuit;
	CardName mCardName;

public: 
	Card();
	Card(int, Suit, CardName);
	void setSuit(Suit);
	void setCardName(CardName);
	CardName getCardName();
	Suit getSuit();
};