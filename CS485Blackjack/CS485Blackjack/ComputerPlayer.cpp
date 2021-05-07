//***************************************************************************
// File name:  Computerplayer.cpp
// Author:     Ethan Hunter
// Date:       5-6-2021
// Class:      CS485
// Assignment: BlackJack
// Purpose:    subclass for player, implements functions
//***************************************************************************

#include "ComputerPlayer.h"


//***************************************************************************
// Function:    ComputerPlayer ctor
//
// Description: initializes the player with behavior and a starting balance
//
// Parameters:  PlayerBehavior* newBehavior - the behavior when performing 
//											  the turn
//				Money mon - starting balance
//
// Returned:    None
//***************************************************************************
ComputerPlayer::ComputerPlayer(PlayerBehavior* newBehavior, Money mon) : Player()
{
	mpBehavior = newBehavior;
	mBank = mon;
}


//***************************************************************************
// Function:    ~ComputerPlayer dtor
//
// Description: deletes the behavior
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
ComputerPlayer::~ComputerPlayer()
{
	delete mpBehavior;
}


//***************************************************************************
// Function:    do turn
//
// Description: performs the turn
//
// Parameters:  int action - the action passed from the view, should be -1
//							 unless passed to a human player
//				int hand - the hand the player should use. defaults to 0, but
//						   will be 1 if the player has split and is acting on
//						   the second hand
//
// Returned:    int - the action request code to perform in the model
//***************************************************************************
int ComputerPlayer::doTurn(int action, int hand)
{
	if (hand >= mHands.size())
	{
		//throw an error if is out of range
		throw std::out_of_range("hand num out of range, should be 0 unless split");
	}
	//returns the behavior choice
	int request = mpBehavior->doTurn(mHands[hand], mbIsSplit);
	if (request == 0)
	{
		mbSettled = true;
	}
	return request;
}


//***************************************************************************
// Function:    seeCard
//
// Description: allows the behaviors to see what card is drawn, and store it
//
// Parameters:  Card c - teh card drawn
//
// Returned:    None
//***************************************************************************
void ComputerPlayer::seeCard(Card c)
{
	mpBehavior->seeCard(c);
}

//***************************************************************************
// Function:    returnBet
//
// Description: returns the bet through the behavior
//
// Parameters:  None
//
// Returned:    Money - the bet used;
//***************************************************************************
Money ComputerPlayer::returnBet()
{
	return mpBehavior->returnBet(mBank);
}

//***************************************************************************
// Function:    setBet
//
// Description: sets the Bet in the player
//
// Parameters:  Money mon -  the bet to set to
//
// Returned:    None
//***************************************************************************
void ComputerPlayer::setBet(Money mon)
{
	mBet = mon;
}