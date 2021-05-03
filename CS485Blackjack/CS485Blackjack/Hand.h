
#pragma once

#include "Card.h"
#include <vector>

class Hand
{
private :
	std::vector<Card> mHand;
	int mSum;

public:
	Hand();
	~Hand();

	void addCard(Card c) { mHand.push_back(c); }
	std::vector<Card> getHand() { return mHand; }
	void clear() { mHand.clear(); }




};