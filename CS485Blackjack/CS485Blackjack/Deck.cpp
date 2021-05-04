#include "Deck.h"
#include <algorithm>
#include <cstdlib>

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
				mCards.push_back(Card(j + 1, (Suit)i, (CardName)j));
			}
		}
	}
}

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
					mCards.push_back(Card(j + 1, (Suit)i, (CardName)j));
				}
			}
		}
	}
}

void Deck::shuffleDeck() {
	int randomInt = rand() % mCards.size();
	std::random_shuffle(mCards.begin(), mCards.end(), randomInt);
}

void Deck::stackDeck() {
	mCards.push_back(Card(10, Suit::Hearts, CardName::King));
	mCards.push_back(Card(7, Suit::Clubs, CardName::Seven));
	mCards.push_back(Card(10, Suit::Diamonds, CardName::Ten));
	mCards.push_back(Card(10, Suit::Hearts, CardName::Ten));
	mCards.push_back(Card(11, Suit::Spades, CardName::Ace));
	mCards.push_back(Card(10, Suit::Clubs, CardName::Ten));
	mCards.push_back(Card(11, Suit::Hearts, CardName::Ace));
	mCards.push_back(Card(10, Suit::Hearts, CardName::Ten));
	mCards.push_back(Card(9, Suit::Clubs, CardName::Nine));
	mCards.push_back(Card(6, Suit::Spades, CardName::Six));
	mCards.push_back(Card(8, Suit::Diamonds, CardName::Eight));
	mCards.push_back(Card(7, Suit::Diamonds, CardName::Seven));
	mCards.push_back(Card(5, Suit::Clubs, CardName::Five));
	mCards.push_back(Card(5, Suit::Hearts, CardName::Five));
	mCards.push_back(Card(10, Suit::Clubs, CardName::Queen));
	//flip this around

	//king seven ten ace ten ace nine ten eight seven
	//five nine six five queen
}

Card Deck::drawCard() {
	Card temp;
	mCards.pop_back();
	return temp;
}

//void changeNumOfSets(int numSets) {
//	mNumOfSets = numSets;
//}