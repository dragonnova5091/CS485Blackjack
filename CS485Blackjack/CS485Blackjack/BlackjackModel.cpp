

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
	mcDeck = cBJ.mcDeck;
	mcvPlayers = cBJ.mcvPlayers;
	mCurrentTurn = 1.0f;
	mTotalRounds = 1;
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
	else if (cplayerType == 'D')
	{
		ptemp = new ComputerPlayer( new DealerBehavior(), cBank);
	}


	mcvPlayers.push_back(ptemp);
	mPlayerCount++;
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

void BlackjackModel::doTurn(float seat, int move, float hands)
{

	int request = mcvPlayers[static_cast<int>(seat)]->doTurn(move);
	
	if (request == 0)
	{
		if (mcvPlayers[seat]->isSplit())
		{
			mTotalRounds += 0.5f;
		}
		else
		{
			mTotalRounds += 1.0f;
		}
		if (mTotalRounds > mPlayerCount + 0.5f)
		{
			mTotalRounds = 0.0f;
		}
	}
	else if (request == 1)
	{
		Card c = getCard();
		for (size_t j = 0; j < mcvPlayers.size(); j++)
		{
			mcvPlayers[j]->seeCard(c);
		}

		if (mcvPlayers[seat]->isSplit())
		{
			if (hands == 0.5f)
			{
				mcvPlayers[seat]->addCard(c, 1);
			}
			else
			{
				mcvPlayers[seat]->addCard(c);
			}
		}
		else
		{
			mcvPlayers[seat]->addCard(c);
		}
		
	}
	else if (request == 2)
	{
		mcvPlayers[seat]->split();
	}
	
	
	//mTotalRounds += hands;
}

float BlackjackModel::getTurn()
{

	const float SPLIT = 0.5;
	float halfTurn = std::floor(mTotalRounds);
	if (SPLIT == (mTotalRounds - halfTurn))
	{
		return (static_cast<int>(mTotalRounds - SPLIT) % mPlayerCount) + SPLIT;
	}
	else
	{
		return (static_cast<int>(mTotalRounds) % mPlayerCount);
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
		for (size_t j = 0; j < mcvPlayers.size(); j++)
		{
			mcvPlayers[j]->seeCard(c);
		}

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