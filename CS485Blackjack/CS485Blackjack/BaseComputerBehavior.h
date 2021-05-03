#pragma once

#include "PlayerBehavior.h"

class BaseComputerBehavior : PlayerBehavior
{
public: 
	virtual PlayerActionCommand doTurn();
	virtual Money returnBet();
};