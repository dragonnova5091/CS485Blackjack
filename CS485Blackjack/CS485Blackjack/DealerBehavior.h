#pragma once

#include "PlayerBehavior.h"

class DealerBehavior : PlayerBehavior
{
	virtual PlayerActionCommand doTurn();
	virtual Money returnBet();
};