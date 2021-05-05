#pragma once

#include "Money.h"
#include "Hand.h"
#include <vector>


class PlayerBehavior
{
public:
	virtual int doTurn(Hand hand) = 0;
	virtual Money returnBet() = 0;
	virtual void seeCard(Card c) {}
};