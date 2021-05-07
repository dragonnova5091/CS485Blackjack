

#include "Deck.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "DealerBehavior.h"
#include "BaseComputerBehavior.h"
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

	PlayerBehavior* behavior = new DealerBehavior();
	Money mon(0, "USD");
	Player* pdealer = new ComputerPlayer(behavior, mon);
	mcvPlayers.push_back(pdealer);
}

BlackjackModel::BlackjackModel(int numPlayers)
{
	mPlayerCount = numPlayers;
	mCurrentTurn = 0.0;
	mTotalRounds = 0;

	PlayerBehavior* behavior = new DealerBehavior();
	Money mon(0, "USD");
	Player* pdealer = new ComputerPlayer(behavior, mon);
	mcvPlayers.push_back(pdealer);
}

BlackjackModel::BlackjackModel(const BlackjackModel& cBJ)
{
	mPlayerCount = (int)cBJ.mcvPlayers.size();
	mcDeck = cBJ.mcDeck;
	mcvPlayers = cBJ.mcvPlayers;
	mCurrentTurn = 0.0;
	mTotalRounds = 0;
}

BlackjackModel::~BlackjackModel()
{
	for (int i = 0; i < mcvPlayers.size(); i++)
	{
		delete mcvPlayers[i];
	}
}

void BlackjackModel::setPlayerName(int seat, std::string& name)
{
	mcvPlayers[seat]->setName(name);
}
void BlackjackModel::addPlayer(std::string name, Money cBank, int seat, char cplayerType)
{
	Player* ptemp;

	if (cplayerType == 'C')
	{
		ptemp = new ComputerPlayer( new BaseComputerBehavior(), cBank);
	}
	else if (cplayerType == 'H')
	{
		ptemp = new HumanPlayer(name, cBank);
	}

	mcvPlayers.push_back(ptemp);
}
void BlackjackModel::removePlayer(int seat)
{
	delete mcvPlayers[seat];
	mcvPlayers.erase(mcvPlayers.begin() + seat);
}
void BlackjackModel::setNumPlayers(int seats)
{
	mPlayerCount = seats;
}

void BlackjackModel::addBet(int seat, Money cBank)
{
	mcvPlayers[seat]->setBet(cBank);
}

void BlackjackModel::doTurn(int seat, int move, float hands)
{

	mcvPlayers[seat]->doTurn(move);

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
	return mcDeck.drawCard();
}
void BlackjackModel::resetGame()
{

}

void BlackjackModel::deal()
{
	Card c;
	
	//two cards per player
	for (size_t i = 0; i < mcvPlayers.size() * 2; i++)
	{
		c = getCard();
		mcvPlayers[i % mcvPlayers.size()]->addCard(c);

	}
}

std::vector<Hand> BlackjackModel::getHand(int seat)
{
	return mcvPlayers[seat]->getHand();
}

bool BlackjackModel::isPlayerSplit(int player)
{
	return mcvPlayers[player]->isSplit();
}