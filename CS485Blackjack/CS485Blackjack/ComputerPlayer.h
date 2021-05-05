#pragma once

#include "Player.h"
#include "PlayerBehavior.h"

class ComputerPlayer : Player
{

private:
	PlayerBehavior* mpBehavior;


public:
	ComputerPlayer(PlayerBehavior* newBehavior);
	virtual int doTurn(int action);
	virtual Money returnBet();
	virtual void setBet(Money mon);
};