
#include "DrunkPlayerBehavior.h"
#include <random>

int DrunkPlayerBehavior::doTurn(Hand hand, bool isSplit)
{
	initAllcards();

	drunkness += (rand() % 100) / 10.0;

	for (auto it = usedCards.begin(); it < usedCards.end(); it++)
	{
		for (auto i = it; i < usedCards.end(); i++)
		{
			if (i->getCardName() == it->getCardName() &&
				i->getSuit() == it->getSuit())
			{
				allCards.erase(i);
			}
		}
	}

	int numCardsSafe = 0;
	int numCardsBust = 0;

	for (auto it = usedCards.begin(); it < usedCards.end(); it++)
	{
		if (it->getValue() + hand.getSum() - 21 > 0)
		{
			numCardsBust++;
		}
		else
		{
			numCardsSafe++;
		}
	}

	if (numCardsSafe < numCardsBust && rand() % 100 > drunkness)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

Money DrunkPlayerBehavior::returnBet(Money totalBank)
{
	totalBank.setAmount(totalBank.getAmount() / 10);
	if (totalBank.getAmount() <= 0)
	{
		totalBank.setAmount(1);
	}
	return totalBank;
}

void DrunkPlayerBehavior::seeCard(Card c)
{
	usedCards.push_back(c);
}

void DrunkPlayerBehavior::initAllcards()
{
	int dup = numDuplicates();


	for (int h = 0; h < dup; h++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 13; j++) {
				if (j >= 9 && j < 12) {
					allCards.push_back(Card(10, (Suit)i, (CardName)j));
				}
				else if (j == 12) {
					allCards.push_back(Card(11, (Suit)i, (CardName)j));
				}
				else {
					allCards.push_back(Card(j + 2, (Suit)i, (CardName)j));
				}
			}
		}
	}
}

int DrunkPlayerBehavior::numDuplicates()
{
	int dup = 0;
	int biggestDup = 0;

	for (auto i = usedCards.begin(); i < usedCards.end(); i++)
	{
		for (auto it = i; it < usedCards.end(); it++)
		{
			if (i->getCardName() == it->getCardName() &&
				i->getSuit() == it->getSuit())
			{
				dup++;
			}
		}
		if (dup > biggestDup)
		{
			biggestDup = dup;
		}
	}
	

	return dup;
}