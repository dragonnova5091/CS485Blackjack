

#include "Deck.h"
#include "Player.h"
#include "Money.h"
#include "BlackjackModel.h"
#include <math.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

BlackjackModel::BlackjackModel()
{
	mPlayerCount = 0;
	mCurrentTurn = 0.0;
	mTotalRounds = 0;
}

BlackjackModel::BlackjackModel(int numPlayers)
{
	mPlayerCount = numPlayers;
	mCurrentTurn = 0.0;
	mTotalRounds = 0;
}

BlackjackModel::BlackjackModel(const BlackjackModel& cBJ)
{
	mPlayerCount = (int)cBJ.mcvPlayers.size();
	mcvDecks = cBJ.mcvDecks;
	mcvPlayers = cBJ.mcvPlayers;
	mCurrentTurn = 0.0;
	mTotalRounds = 0;
}

BlackjackModel::~BlackjackModel()
{

}

void BlackjackModel::setPlayerName(int seat, std::string& name)
{
	mcvPlayers[seat].setName(name);
}
void BlackjackModel::addPlayer(std::string name, Money cBank, int seat)
{
	mcvPlayers[seat].setName(name);
	mcvPlayers[seat].updateMoney(cBank);
}
void BlackjackModel::removePlayer(int seat)
{
	mcvPlayers.erase(mcvPlayers.begin() + seat);
}
void BlackjackModel::setNumPlayers(int seats)
{
	mPlayerCount = seats;
}

void BlackjackModel::addBet(int seat, Money cBank)
{
	mcvPlayers[seat].setBet(cBank);
}

void BlackjackModel::doTurn(int seat, int move, float hands)
{

	mcvPlayers[seat].doTurn(move);

	if (mTotalRounds == mCurrentTurn)
	{
		mTotalRounds++;
	}
	mCurrentTurn += hands;
}

float BlackjackModel::getTurn()
{
	const float SPLIT = 0.5;
	float halfTurn = std::floor(mCurrentTurn);
	if (SPLIT == (mCurrentTurn - halfTurn))
	{
		return (halfTurn / mTotalRounds) + SPLIT;
	}
	else
	{
		return (mCurrentTurn / mTotalRounds);
	}
}

Card BlackjackModel::getCard()
{
	int randomDeck;
	srand(static_cast<unsigned int>(time(NULL)));

	randomDeck = static_cast<int>(rand()) % 6;
	return mcvDecks[randomDeck].drawCard();
}
void BlackjackModel::resetGame()
{

}