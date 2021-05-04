#include "Card.h"

Card::Card(int value, Suit suit, CardName cardName) {
	mValue = value;
	mSuit = suit;
	mCardName = cardName;
}

void Card::setSuit(Suit suit) {
	mSuit = suit;
}

void Card::setCardName(CardName cardName) {
	mCardName = cardName;
}

CardName Card::getCardName() {
	return mCardName;
}

Suit Card::getSuit() {
	return mSuit;
}