//***************************************************************************
// File name:  ComputerPlayer.h
// Author:     Ethan Hunter
// Date:       5-6-2021
// Class:      CS485
// Assignment: BlackJack
// Purpose:    subclass for player
//***************************************************************************

#pragma once

#include "Player.h"
#include "PlayerBehavior.h"

class ComputerPlayer : public Player
{

private:
	PlayerBehavior* mpBehavior;


public:
	ComputerPlayer(PlayerBehavior* newBehavior, Money mon);
	~ComputerPlayer();
	virtual int doTurn(int action, int hand = 0);
	virtual Money returnBet();
	virtual void setBet(Money mon);
	void seeCard(Card c);
};