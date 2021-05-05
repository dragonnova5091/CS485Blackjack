

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
	Money m(0, "USD");
	return m;
}