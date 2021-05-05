#pragma once

#include "PlayerBehavior.h"

class DealerBehavior : PlayerBehavior
{
	virtual int doTurn(Hand hand, bool isSplit);
	virtual Money returnBet(Money totalBank);
};