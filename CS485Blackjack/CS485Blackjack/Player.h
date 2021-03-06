
#pragma once

#include "Money.h"
#include "Hand.h"
#include <string>

class Player
{
protected:
	std::string mName;
	Money mBank;
	Money mBet;
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
	bool isSplit() { return mbIsSplit; }
	std::vector<Hand> getHand() { return mHands; }

	void updateMoney(Money mon);
	void addCard(Card c, int hand = 0);
	void finishTurn(bool bWin, bool b21, int hand = 0);
	void split();

	void clearHand();
	virtual int doTurn(int action, int hand = 0) = 0;
	virtual Money returnBet() = 0;
	virtual void seeCard(Card c) {}
	virtual void setBet(Money mon);
	virtual char returnType() = 0;
	



};