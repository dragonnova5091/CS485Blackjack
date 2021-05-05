
#include "DrunkPlayerBehavior.h"

int DrunkPlayerBehavior::doTurn(Hand hand, bool isSplit)
{


	return 0;
}

Money DrunkPlayerBehavior::returnBet(Money totalBank)
{
	totalBank.setAmount(totalBank.getAmount() / 10);
	if (totalBank.getAmount() <= 0)
	{
		totalBank.setAmount(1);
	}
	return totalBank;
}

void DrunkPlayerBehavior::seeCard(Card c)
{
	usedCards.push_back(c);
}