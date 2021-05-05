
#include "Player.h"

Player::Player()
{
	//yeet
}

Player::~Player()
{
	//lol
}


void Player::updateMoney(Money mon)
{
	//if the balance is the same
	if (mBank.getCurrency().getCurrencyType() == \
		mon.getCurrency().getCurrencyType())
	{
		//set the balance
		mBank.setAmount(mon.getAmount());
	}
	else
	{
		//don't be here
		throw CurrencyMismatchException(69);
	}
}

void Player::addCard(Card c, int hand = 0)
{
	//check that the hand int is within range
	if (hand >= mHands.size())
	{
		//throw an error if is out fo range
		throw std::out_of_range("hand num out of range, should be 0 unless split");
	}
	else
	{
		//add to hand
		mHands[hand].addCard(c);
	}
}

void Player::finishTurn(bool bWin, int hand = 0)
{
	mbSettled = true;
	if (bWin)
	{
		//check that the hand int is within range
		if (hand >= mHands.size())
		{
			//throw an error if is out fo range
			throw std::out_of_range("hand num out of range, should be 0 unless split");
		}
		else
		{
			if (mHands[hand].getHand().size() > 0)
			{
				mHands[hand].clear();
				mBank + mBet;
			}
			else 
			{
				throw std::exception::exception("Hand already cleared");
			}
			
		}
		bool tempbool = false;
		for (int i = 0; i < mHands.size(); i++)
		{
			if (mHands[i].getHand().size() > 0)
			{
				tempbool = true;
			}
		}
		if (!tempbool)
		{
			Hand h;
			mBet.setAmount(0);
			mHands.clear();
			mHands.push_back(h);
		}
	}
}