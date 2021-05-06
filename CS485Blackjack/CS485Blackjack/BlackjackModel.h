
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

	void addBet(int seat, Money cBank);

	void doTurn(int seat, int move, float hands);
	float getTurn();
	Card getCard();
	void resetGame();
	void deal();
};