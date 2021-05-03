#pragma once

#include "Player.h"
#include "PlayerActionCommand.h"
#include "PlayerBehavior.h"

class ComputerPlayer : Player
{

private:
	PlayerActionCommand mAction;
	PlayerBehavior* mpBehavior;


public:
	ComputerPlayer(PlayerBehavior* newBehavior);
	virtual PlayerActionCommand doTurn();
	virtual Money returnBet();
	virtual void setBet(Money mon);
};