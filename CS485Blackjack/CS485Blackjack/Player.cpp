//***************************************************************************
// File name:  Player.cpp
// Author:     Ethan Hunter
// Date:       5-6-2021
// Class:      CS485
// Assignment: BlackJack
// Purpose:    player abstract class implementation
//***************************************************************************


#include "Player.h"

//***************************************************************************
// Function:    Player ctor
//
// Description: ctor init private variables to defaultsk
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
Player::Player()
{
	mbIsSplit = false;
	mbSettled = false;
	Hand baseHand;
	mHands.push_back(baseHand);
}

//***************************************************************************
// Function:    HumanPlayer ctor
//
// Description: empty ctor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
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

void Player::addCard(Card c, int hand )
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

void Player::finishTurn(bool bWin, bool b21, int hand )
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
			//check to make sure the hand is not already handled
			if (mHands[hand].getHand().size() > 0)
			{
				//clear the hand and 
				mHands[hand].clear();
				if (!b21)
				{
					mBank = mBank + mBet;
				}
				else
				{
					mBank.setAmount(mBank.getAmount() + 
						(long long) (mBet.getAmount() * 1.5));
				}
				
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

void Player::split()
{
	if (mHands.size() == 1)
	{
		if ((mBank - mBet - mBet).getAmount() >= 0)
		{
			Hand h;
			std::vector<Card> tempHand = mHands[0].getHand();
			if (tempHand.size() != 2)
			{
				throw std::exception::exception("Already Hit, Cannot Split", 69);
			}
			mHands[0].clear();
			mHands[0].addCard(tempHand[0]);
			mHands.push_back(h);
			mHands[1].addCard(tempHand[1]);
		}
	}
	else
	{
		throw std::exception::exception("Hand Already Split", 69);
	}
}

void Player::clearHand()
{
	mHands.clear();
}


void Player::setBet(Money mon)
{
	mBet = mon;
}