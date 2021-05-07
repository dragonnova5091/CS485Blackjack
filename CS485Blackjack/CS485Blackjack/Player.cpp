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
// Function:    Player dtor
//
// Description: empty dtor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
Player::~Player()
{
	//lol
}

//***************************************************************************
// Function:    updateMoney
//
// Description: updates the bank
//
// Parameters:  Money mon - the balance to set to
//
// Returned:    None
//***************************************************************************
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


//***************************************************************************
// Function:    addCard
//
// Description: adds a card to the specified hand
//
// Parameters:  Card c - the card to add
//				int hand - the hand to add to. default 0
//
// Returned:    None
//***************************************************************************
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
		if (mHands[hand].getSum() > 21)
		{
			bool temp = true;
			int i = 0;
			do
			{
				if (mHands[hand].getHand()[i].getCardName() == CardName::Ace 
					&& mHands[hand].getHand()[i].getValue() == 11)
				{
					
					auto v = mHands[hand].getHand();
					v[i].setValue(1);
					mHands[hand].clear();
					for (int i = 0; i <v.size(); i++)
					{
						mHands[hand].addCard(v[i]);
					}
				}
				i++;
			} while (mHands[hand].getSum() > 21 && i < mHands[hand].getHand().size());

			if (i >= mHands[hand].getHand().size())
			{
				finishTurn(false, false, hand);
				return;
			}

		}
		else if (mHands[hand].getSum() == 21)
		{
			finishTurn(true, true, hand);
			return;
		}
		else
		{
			mbSettled = false;
		}
	}
	
}

//***************************************************************************
// Function:    finish turn
//
// Description: finishes the players turn. updates betting, banks, and hands
//
// Parameters:  bool bWin - if the player won
//				bool b21 - if the player got blackjack
//				int hand - the hand to apply to
//
// Returned:    None
//***************************************************************************
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
				//mHands[hand].clear();
				if (!b21)
				{
					mBank.setAmount(mBank.getAmount() + mBet.getAmount());
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
			//Hand h;
			mBet.setAmount(0);
			//mHands.clear();
			//mHands.push_back(h);
		}
	}
	else
	{
		mBank.setAmount(mBank.getAmount() - mBet.getAmount());
	}
}

//***************************************************************************
// Function:    split
//
// Description: splits the player's hand
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
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

//***************************************************************************
// Function:    clear hand
//
// Description: clears all cards from the player
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void Player::clearHand()
{
	mHands.clear();
}

//***************************************************************************
// Function:    setBet
//
// Description: sets the bet
//
// Parameters:  Money mon -  the bet to set to
//
// Returned:    None
//***************************************************************************
void Player::setBet(Money mon)
{
	mBet = mon;
}