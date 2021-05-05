#pragma once

#include "Player.h"
#include "PlayerBehavior.h"

class ComputerPlayer : Player
{

private:
	PlayerBehavior* mpBehavior;


public:
	ComputerPlayer(PlayerBehavior* newBehavior);
	~ComputerPlayer();
	virtual int doTurn(int action, int hand = 0);
	virtual Money returnBet();
	virtual void setBet(Money mon);
	void seeCard(Card c);
};