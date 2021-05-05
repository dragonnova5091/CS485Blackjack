
#include "HumanPlayer.h"

HumanPlayer::HumanPlayer() : Player()
{
	
}


HumanPlayer::HumanPlayer(std::string name, Money mon)
{
	mName = name;
	mBank = mon;
}

HumanPlayer::~HumanPlayer()
{

}

Money HumanPlayer::returnBet()
{
	return mBet;
}

void HumanPlayer::setBet(Money mon)
{
	mBet = mon;
}

int HumanPlayer::doTurn(int action, int hand)
{
	int toReturn = -1;
	//check that the hand int is within range
	if (hand >= mHands.size())
	{
		//throw an error if is out fo range
		throw std::out_of_range("hand num out of range, should be 0 unless split");
	}
	else
	{
		switch (action)
		{
		case -1:
			throw std::exception::exception
			("Human player got request for computer player", 69);
			return;
		case 0:
			mbSettled = true;
			toReturn = 0;
			return;
		case 1:
			toReturn = 1;
			return;
		case 2:
			split();
			toReturn = 2;
			return;
		}
		return toReturn;
	}
}

