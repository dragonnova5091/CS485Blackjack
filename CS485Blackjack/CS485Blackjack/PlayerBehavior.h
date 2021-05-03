#pragma once


#include "PlayerActionCommand.h"
#include "Money.h"


class PlayerBehavior
{
public:
	virtual PlayerActionCommand doTurn() = 0;
	virtual Money returnBet() = 0;
};