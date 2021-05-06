
#pragma once

#include "Card.h"
#include <vector>

class Hand
{
private :
	std::vector<Card> mHand;
	int mSum;

public:
	Hand() { mSum = 0; }
	~Hand() {}

	void addCard(Card c) { mHand.push_back(c); }
	std::vector<Card> getHand() { return mHand; }
	void clear() { mHand.clear(); }
	int getSum() 
	{
		for (int i = 0; i < static_cast<int>(mHand.size()); i++)
		{
			mSum += mHand[i].returnValue();
		}
		return mSum;
	}
};