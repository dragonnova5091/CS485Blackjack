#pragma once

#include "PlayerBehavior.h"

class DealerBehavior : PlayerBehavior
{
	virtual int doTurn();
	virtual Money returnBet();
};