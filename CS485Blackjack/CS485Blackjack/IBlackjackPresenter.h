
#pragma once
#include <vector>
#include "Hand.h"

class IBlackjackPresenter
{
public:
	virtual ~IBlackjackPresenter() {}

	virtual void setPlayerName(int seat, std::string& name) = 0;
	virtual void addPlayer(std::string name, Money cBank, int seat, char cplayerType) = 0;
	virtual void removePlayer(int seat) = 0;
	virtual void setNumPlayers(int seats) = 0;

	virtual void addBet(int seat, Money cBank) = 0;

	virtual void doTurn(float seat, int move, float hands) = 0;
	virtual float getTurn() = 0;
	virtual Card getCard() = 0;
	virtual void resetGame() = 0;
	virtual void deal() = 0;
	virtual std::vector<Hand> getHand(int seat) = 0;
	virtual bool isPlayerSplit(int player) = 0;
	virtual char getPlayerType(int player) = 0;
	virtual Money getBank(int player) = 0;
};