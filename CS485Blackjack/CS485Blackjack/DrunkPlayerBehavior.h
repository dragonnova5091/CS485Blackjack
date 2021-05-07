#pragma once

#include "PlayerBehavior.h"
#include "Card.h"
#include <vector>

class DrunkPlayerBehavior : PlayerBehavior
{
private:
	std::vector<Card> usedCards;
	std::vector<Card> allCards;

	double drunkness = 0.0;

	void initAllcards();
	int numDuplicates();
public:
	virtual int doTurn(Hand hand, bool isSplit);
	virtual Money returnBet(Money totalBank);
	void seeCard(Card c);
};