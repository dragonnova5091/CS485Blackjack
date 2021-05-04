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
	void setSuit(Suit);
	void setCardName(CardName);
	CardName getCardName();
	Suit getSuit();
};