//***************************************************************************
// File name:  BlackjackPresenter.h
// Author:     Hung Huynh
// Date:       5-6-2021
// Class:      CS485
// Assignment: BlackJack
// Purpose:    concrete class for the presenter
//***************************************************************************

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

	void doTurn(float seat, int move, float hands);
	float getTurn();
	Card getCard();
	void resetGame();
	void deal();
	std::vector<Hand> getHand(int seat);
	bool isPlayerSplit(int player);
	char getPlayerType(int player);
};