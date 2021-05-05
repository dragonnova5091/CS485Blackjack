
#include "BaseComputerBehavior.h"

int BaseComputerBehavior::doTurn(Hand hand, bool isSplit)
{
	if (hand.getHand().size() == 2 && !isSplit)
	{
		//split
		return 2;
	}
	else if (hand.getSum() < 16)
	{
		//hit	
		return 1;
	}
	else
	{
		//stay
		return 0;
	}
}

Money BaseComputerBehavior::returnBet(Money totalbank)
{
	//always bets 5 unless there is not 5 to bet
	if (totalbank.getAmount() > 5)
	{
		totalbank.setAmount(5);
	}
	return totalbank;
}