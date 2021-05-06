
#pragma once

#include "IBlackjackView.h"
#include "BlackjackModel.h"
#include "IBlackjackPresenter.h"
#include <vector>

class BlackjackPresenter : public IBlackjackPresenter
{
private:
	const int MAXPLAYERS = 6;

	IBlackjackView *mpcBJView;
	BlackjackModel mcBJModel;

public:
	BlackjackPresenter(IBlackjackView* theView);
	BlackjackPresenter(BlackjackPresenter &BlackjackPresenter);
	~BlackjackPresenter();

	void setPlayerName(int seat, std::string& name);
	void addPlayer(std::string name, Money cBank, int seat, char cplayerType);
	void removePlayer(int seat);
	void setNumPlayers(int seats);

	void addBet(int seat, Money cBank);

	void doTurn(int seat, int move, float hands);
	float getTurn();
	Card getCard();
	void resetGame();
	void deal();
};