//***************************************************************************
// File name:  HumanPlayer.h
// Author:     Ethan Hunter
// Date:       5-6-2021
// Class:      CS485
// Assignment: BlackJack
// Purpose:    subclass for player
//***************************************************************************

#pragma once

#include "Player.h"

class HumanPlayer : public Player
{
private:

public:
	HumanPlayer();
	HumanPlayer(std::string name, Money mon);
	~HumanPlayer();

	virtual int doTurn(int action, int hand = 0 );
	virtual Money returnBet();
	virtual void setBet(Money mon);

};