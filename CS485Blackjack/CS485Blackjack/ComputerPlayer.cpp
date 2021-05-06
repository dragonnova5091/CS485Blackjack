

#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(PlayerBehavior* newBehavior, Money mon)
{
	mpBehavior = newBehavior;
	mBank = mon;
}

ComputerPlayer::~ComputerPlayer()
{
	delete mpBehavior;
}

int ComputerPlayer::doTurn(int action, int hand)
{
	if (action != -1)
	{
		//computer take action -1, this is what tells them to use their behaviors
		throw std::exception::exception("computer player must take action -1", 69);
	}
	if (hand >= mHands.size())
	{
		//throw an error if is out fo range
		throw std::out_of_range("hand num out of range, should be 0 unless split");
	}
	return mpBehavior->doTurn(mHands[hand], mbIsSplit);
}

void ComputerPlayer::seeCard(Card c)
{
	mpBehavior->seeCard(c);
}

Money ComputerPlayer::returnBet()
{
	mpBehavior->returnBet(mBank);
}
