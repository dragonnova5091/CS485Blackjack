#pragma once

#include "PlayerBehavior.h"

class BaseComputerBehavior : PlayerBehavior
{
public: 
	virtual int doTurn(Hand hand, bool isSplit);
	virtual Money returnBet(Money totalBank);
};