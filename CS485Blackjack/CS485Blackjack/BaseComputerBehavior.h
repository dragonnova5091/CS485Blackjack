//***************************************************************************
// File name:  BaseComputerBehavior.h
// Author:     Ethan Hunter
// Date:       5-6-2021
// Class:      CS485
// Assignment: BlackJack
// Purpose:    defines the strategy pattern for base computer behaviors
//***************************************************************************

#pragma once

#include "PlayerBehavior.h"

class BaseComputerBehavior : public PlayerBehavior
{
public: 
	virtual int doTurn(Hand hand, bool isSplit);
	virtual Money returnBet(Money totalBank);
};

