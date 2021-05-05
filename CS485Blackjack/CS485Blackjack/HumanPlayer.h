
#pragma once

#include "Player.h"

class HumanPlayer : Player
{
private:

public:
	HumanPlayer();
	HumanPlayer(std::string name, Money mon);
	~HumanPlayer();

	virtual int doTurn(int action);
	virtual Money returnBet();
	virtual void setBet(Money mon);

};