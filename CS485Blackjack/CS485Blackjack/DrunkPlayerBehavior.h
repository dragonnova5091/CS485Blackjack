#pragma once

#include "PlayerBehavior.h"
#include "Card.h"
#include <vector>

class DrunkPlayerBehavior : PlayerBehavior
{
private:
	std::vector<Card> usedCards;
public:
	virtual int doTurn();
	virtual Money returnBet();
	void seeCard(Card c);
};