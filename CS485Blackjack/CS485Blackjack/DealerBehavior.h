#pragma once

#include "PlayerBehavior.h"

class DealerBehavior : PlayerBehavior
{
	virtual int doTurn(Hand hand);
	virtual Money returnBet();
};