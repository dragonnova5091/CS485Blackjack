
#pragma once

#include "IBlackjackView.h"
#include "BlackjackModel.h"
#include <vector>

class BlackjackPresenter
{
private:
	const int MAXPLAYERS = 6;

	IBlackjackView *mpcBJView;
	BlackjackModel mcBJModel;

public:
	BlackjackPresenter();
	~BlackjackPresenter();

	void setPlayerName(int seat, std::string& name);
	void addPlayer(std::string name, Money cBank, int seat);
	void removePlayer(int seat);
	void setNumPlayers(int seats);

	void addBet(Money cBank);

	void doTurn(float turn);
	void resetGame();
};