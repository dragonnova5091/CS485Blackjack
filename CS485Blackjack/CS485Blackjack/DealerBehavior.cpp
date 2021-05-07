//***************************************************************************
// File name:  DealerBehavior.cpp
// Author:     Ethan Hunter
// Date:       5-6-2021
// Class:      CS485
// Assignment: BlackJack
// Purpose:    subclass for player behavior for the dealer
//***************************************************************************

#include "DealerBehavior.h"

int DealerBehavior::doTurn(Hand hand, bool isSplit)
{
	if (hand.getSum() >= 16)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

Money DealerBehavior::returnBet(Money totalBank)
{
	totalBank.setAmount(totalBank.getAmount() / 5);
	return totalBank;
}