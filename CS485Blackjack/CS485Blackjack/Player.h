
#pragma once

#include "Money.h"
#include "Hand.h"
#include "PlayerActionCommand.h"
#include <string>

class Player
{
private:
	std::string mName;
	Money mBank;
	std::vector<Hand> mHands;
	bool mbSettled;
	bool mbIsSplit;

public:
	Player();
	~Player();

	void setName(std::string name) { mName = name; }
	std::string getName() { return mName; }
	Money getMoney() { return mBank; }
	bool getSettled() { return mbSettled; }

	void updateMoney(Money mon);
	void addCard(Card c);
	void finishTurn();
	void split();

	void clearHand();
	virtual PlayerActionCommand doTurn() = 0;
	virtual Money returnBet() = 0;
	virtual void seeCard(Card c) {}
	virtual void setBet(Money mon);




};