//***************************************************************************
// File name:  HumanPlayer.cpp
// Author:     Ethan Hunter
// Date:       5-6-2021
// Class:      CS485
// Assignment: BlackJack
// Purpose:    subclass for player implementation
//***************************************************************************


#include "HumanPlayer.h"

//***************************************************************************
// Function:    HumanPlayer ctor
//
// Description: empty ctor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
HumanPlayer::HumanPlayer() : Player()
{
	
}

//***************************************************************************
// Function:    HumanPlayer ctor
//
// Description: sets the naem and initial bank balance
//
// Parameters:  string name - the name of the player
//				Money mon - the player's initial balance
//
// Returned:    None
//***************************************************************************
HumanPlayer::HumanPlayer(std::string name, Money mon)
{
	mName = name;
	mBank = mon;
}

//***************************************************************************
// Function:    HumanPlayer dtor
//
// Description: empty dtor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
HumanPlayer::~HumanPlayer()
{

}

//***************************************************************************
// Function:    returnBet
//
// Description: returns the player's bet
//
// Parameters:  None
//
// Returned:    Money  - the bet set in the player
//***************************************************************************
Money HumanPlayer::returnBet()
{
	return mBet;
}

//***************************************************************************
// Function:    setBet
//
// Description: sets the player's bet
//
// Parameters:  Money mon - the bet to set to
//
// Returned:    None
//***************************************************************************
void HumanPlayer::setBet(Money mon)
{
	mBet = mon;
}

//***************************************************************************
// Function:    HumanPlayer ctor
//
// Description: do turn function. sets local varibles, and returns the 
//				action passed in
//
// Parameters:  int action - the action from the view
//				int hand - the hand to apply the action to. defualt to 0
//
// Returned:    int - the action the player does
//***************************************************************************
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
			return toReturn;
		case 0:
			mbSettled = true;
			toReturn = 0;
			return toReturn;
		case 1:
			toReturn = 1;
			return toReturn;
		case 2:
			split();
			toReturn = 2;
			return toReturn;
		}
	}
	return toReturn;
}

