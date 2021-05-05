
#pragma once

class IBlackjackPresenter
{
public:
	virtual ~IBlackjackPresenter() {}

	virtual void setPlayerName(int seat, std::string& name) = 0;
	virtual void addPlayer(std::string name, Money cBank, int seat) = 0;
	virtual void removePlayer(int seat) = 0;
	virtual void setNumPlayers(int seats) = 0;

	virtual void addBet(int seat, Money cBank) = 0;

	virtual void doTurn(int seat, int play, float turn) = 0;
	virtual void resetGame() = 0;
};