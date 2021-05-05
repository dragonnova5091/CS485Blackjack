#pragma once

#include "Money.h"
#include "Card.h"


class PlayerBehavior
{
public:
	virtual int doTurn() = 0;
	virtual Money returnBet() = 0;
	virtual void seeCard(Card c) {}
};