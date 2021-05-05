#pragma once

#include "Money.h"
#include "Hand.h"
#include <vector>


class PlayerBehavior
{
public:
	virtual int doTurn(Hand hand, bool isSplit) = 0;
	virtual Money returnBet(Money totalBank) = 0;
	virtual void seeCard(Card c) {}
};