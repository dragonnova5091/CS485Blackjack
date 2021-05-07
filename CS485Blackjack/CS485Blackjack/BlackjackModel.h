//***************************************************************************
// File name:  BlackjackModel.h
// Author:     hung Huynh
// Date:       5-6-2021
// Class:      CS485
// Assignment: BlackJack
// Purpose:    model header
//***************************************************************************

#pragma once

#include "Deck.h"
#include "Player.h"
#include "Money.h"
#include <vector>

class BlackjackModel
{
private:
	const int MAXPLAYERS = 6;

	Deck mcDeck;
	std::vector<Player*>mcvPlayers;
	int mPlayerCount;
	float mCurrentTurn;
	float mTotalRounds;

public:
	BlackjackModel();
	BlackjackModel(int numPlayers);
	BlackjackModel(const BlackjackModel& cBJ);
	~BlackjackModel();

	void setPlayerName (int seat, std::string& name);
	void addPlayer(std::string name, Money cBank, int seat, char cplayerType);
	void removePlayer(int seat);
	void setNumPlayers(int seats);
	void finishRound();

	void addBet(int seat, Money cBank);

	void doTurn(float seat, int move, float hands);
	float getTurn();
	Card getCard();
	void resetGame();
	void deal();
	std::vector<Hand> getHand(int seat);
	bool isPlayerSplit(int player);
	char getPlayerType(int player);
	Money getBank(int player);
};