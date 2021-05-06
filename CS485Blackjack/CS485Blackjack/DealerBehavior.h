#pragma once

#include "PlayerBehavior.h"

class DealerBehavior : public PlayerBehavior
{
	virtual int doTurn(Hand hand, bool isSplit);
	virtual Money returnBet(Money totalBank);
};