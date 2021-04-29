#include "Deck.h"

Deck::Deck() {
	mNumOfSets = 1;
}

Deck::Deck(int numSets) {
	mNumOfSets = numSets;
}
void Deck::shuffleDeck() {

}

void Deck::stackDeck() {

}

Card Deck::drawCard() {
	
}

void changeNumOfSets(int numSets) {
	mNumOfSets = numSets;
}