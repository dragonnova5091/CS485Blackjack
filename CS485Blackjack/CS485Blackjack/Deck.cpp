#include "Deck.h"

Deck::Deck() {
	mNumOfSets = 1;

}

Deck::Deck(int numSets) {
	mNumOfSets = numSets;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			mCards.push_back(Card(j + 1, (Suit)i, (CardName)j));
		}
	}
}

void Deck::shuffleDeck() {
	
	
}

void Deck::stackDeck() {

}

//Card Deck::drawCard() {
//	Card temp;
//	temp = mCards.pop_back();
//	return temp;
//}

//void changeNumOfSets(int numSets) {
//	mNumOfSets = numSets;
//}