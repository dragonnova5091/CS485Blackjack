#pragma once

#include "PlayerBehavior.h"

class BaseComputerBehavior : PlayerBehavior
{
public: 
	virtual int doTurn();
	virtual Money returnBet();
};