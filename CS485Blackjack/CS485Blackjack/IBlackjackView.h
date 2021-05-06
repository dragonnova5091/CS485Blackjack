//***************************************************************************
// File name:  BlackjackView.h
// Author:     Michael Timmerman
// Date:       4/30/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    View of Blackjack
//***************************************************************************
#pragma once
#include <string>
#include "Card.h"
#include "Money.h"

class IBlackjackView
{
public:
	//events from UI
	virtual void onDraw() = 0;
	virtual void onAddPlayer(std::string) = 0;
	virtual void onRemovePlayer(std::string) = 0;
	virtual void onSetPlayer1Name(std::string) = 0;
	virtual void onSetPlayer2Name(std::string) = 0;
	virtual void onSetPlayer3Name(std::string) = 0;
	virtual void onSetPlayer4Name(std::string) = 0;
	virtual void onSetPlayer5Name(std::string) = 0;
	virtual void deal() = 0;
	virtual void onClickHit() = 0;
	virtual void onClickStay() = 0;
	virtual void onClickSplit() = 0;
	virtual void onSetBet(std::string) = 0;
	virtual Card drawCard() = 0;

	//events from Presenter
	virtual void addBet(Money bet) = 0;
	virtual float getCurrentTurn() = 0;
	virtual void addPlayer(char playerType, std::string playerName, Money bank) = 0;
	virtual void removePlayer(int player) = 0;
	virtual void setNumPlayer(int players) = 0;
	virtual void resetGame() = 0;
	virtual void quitGame() = 0;

	/*We cant have a private member here because then it isnt an interface <3. So I put in the subclasses. -Hung*/
};