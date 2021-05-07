//***************************************************************************
// File name:  BlackjackModel.cpp
// Author:     hung Huynh
// Date:       5-6-2021
// Class:      CS485
// Assignment: BlackJack
// Purpose:    model implementation
//***************************************************************************

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


//***************************************************************************
// Function:    BlackjackModel ctor
//
// Description: ctor init private variables to defaultsk
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
BlackjackModel::BlackjackModel()
{
	mPlayerCount = 0;
	mCurrentTurn = 0.0;
	mTotalRounds = 1;
	mcDeck.stackDeck();

}

//***************************************************************************
// Function:    BlackjackModel ctor
//
// Description: ctor init private variables to defaults, sets num of players
//
// Parameters:  int numplayers - num of players
//
// Returned:    None
//***************************************************************************
BlackjackModel::BlackjackModel(int numPlayers)
{
	mPlayerCount = numPlayers;
	mCurrentTurn = 0.0;
	mTotalRounds = 1;

}

//***************************************************************************
// Function:    BlackjackModel cctor
//
// Description: ctor init private variables to defaultsk
//
// Parameters:  blackjackModel& cBJ - obj to copy
//
// Returned:    None
//***************************************************************************
BlackjackModel::BlackjackModel(const BlackjackModel& cBJ)
{
	mPlayerCount = (int)cBJ.mcvPlayers.size();
	mcDeck = cBJ.mcDeck;
	mcvPlayers = cBJ.mcvPlayers;
	mCurrentTurn = 1.0f;
	mTotalRounds = 1;
}

//***************************************************************************
// Function:    BlackjackModel dtor
//
// Description: dtor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
BlackjackModel::~BlackjackModel()
{
	for (int i = 0; i < mcvPlayers.size(); i++)
	{
		delete mcvPlayers[i];
	}
}

//***************************************************************************
// Function:    setPlayername
//
// Description: sets the chosen player's name
//
// Parameters:  int seat - the index of the player
//				string& name - the name to set to
//
// Returned:    None
//***************************************************************************
void BlackjackModel::setPlayerName(int seat, std::string& name)
{
	mcvPlayers[seat]->setName(name);
}

//***************************************************************************
// Function:    addPlayer
//
// Description: adds a player to the model
//
// Parameters:  string name - the name of the new player
//				Money cBank - the init bank
//				int seat  - the index. this is handled by the view
//				char cplayerType - human or computer
//
// Returned:    None
//***************************************************************************
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


//***************************************************************************
// Function:    removePlayer
//
// Description: get that player outta here
//
// Parameters:  int seat - the player to remove
//
// Returned:    None
//***************************************************************************
void BlackjackModel::removePlayer(int seat)
{
	delete mcvPlayers[seat];
	mcvPlayers.erase(mcvPlayers.begin() + seat);
}


//***************************************************************************
// Function:    setNumPlayers
//
// Description: sets the number of players
//
// Parameters:  int seats - the number of players
//
// Returned:    None
//***************************************************************************
void BlackjackModel::setNumPlayers(int seats)
{
	mPlayerCount = seats;
}


//***************************************************************************
// Function:    addbet
//
// Description: sets a players bet
//
// Parameters:  int seat - the chosen player
//				Money cBank - the bet. not a bank
//
// Returned:    None
//***************************************************************************
void BlackjackModel::addBet(int seat, Money cBank)
{
	mcvPlayers[seat]->setBet(cBank);
}

//***************************************************************************
// Function:    doTurn
//
// Description: ddoes the chosen player's turn
//
// Parameters:  float seat - the player who's turn it is. is x.5f if split
//				int move - the move passed from the view
//				float hands - 0.5f if split
//
// Returned:    None
//***************************************************************************
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
	
	int num = 0;
	for (int i = 0; i < mcvPlayers.size(); i++)
	{
		if (mcvPlayers[i]->getSettled())
		{
			num++;
		}
	}

	if (num == mcvPlayers.size())
	{
		finishRound();
	}
	
	//mTotalRounds += hands;


}

//***************************************************************************
// Function:    finishRound
//
// Description: finishes the round
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackjackModel::finishRound()
{
	int dealerSum = mcvPlayers[0]->getHand()[0].getSum();
	for (int i = 0; i < mcvPlayers.size(); i++)
	{
		if (!mcvPlayers[i]->isSplit())
		{
			if (mcvPlayers[i]->getHand()[0].getSum() > dealerSum)
			{
				mcvPlayers[i]->finishTurn(true, false);
			}
			else if (mcvPlayers[i]->getHand()[0].getSum() < dealerSum)
			{
				mcvPlayers[i]->finishTurn(false, false);
			}
			else
			{
				Money mon(0, "USD");
				mcvPlayers[i]->setBet(mon);
				mcvPlayers[i]->finishTurn(false, false);
			}
		}
		else
		{
			if (mcvPlayers[i]->getHand()[0].getSum() > dealerSum)
			{
				mcvPlayers[i]->finishTurn(true, false);
			}
			else if (mcvPlayers[i]->getHand()[0].getSum() < dealerSum)
			{
				mcvPlayers[i]->finishTurn(false, false);
			}
			else
			{
				Money mon(0, "USD");
				mcvPlayers[i]->setBet(mon);
				mcvPlayers[i]->finishTurn(false, false);
			}

			if (mcvPlayers[i]->getHand()[1].getSum() > dealerSum)
			{
				mcvPlayers[i]->finishTurn(true, false, 1);
			}
			else if (mcvPlayers[i]->getHand()[1].getSum() < dealerSum)
			{
				mcvPlayers[i]->finishTurn(false, false, 1);
			}
			else
			{
				Money mon(0, "USD");
				mcvPlayers[i]->setBet(mon);
				mcvPlayers[i]->finishTurn(false, false);
			}
		}
	}
}

//***************************************************************************
// Function:    getTurn
//
// Description: gets the current turn
//
// Parameters:  None
//
// Returned:    float - returns the current turn. x.5f if split
//***************************************************************************
float BlackjackModel::getTurn()
{

	int num = 0;
	for (int i = 0; i < mcvPlayers.size(); i++)
	{
		if (mcvPlayers[i]->getSettled())
		{
			num++;
		}
	}

	if (num == mcvPlayers.size())
	{
		return -1;
	}

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

//***************************************************************************
// Function:    getCard
//
// Description: draws a card from the deck
//
// Parameters:  None
//
// Returned:    Card - the card drawn
//***************************************************************************
Card BlackjackModel::getCard()
{
	return mcDeck.drawCard();
}


//***************************************************************************
// Function:    resetGame
//
// Description: resets teh game
//
// Parameters:  None
//
// Returned:    NONE
//***************************************************************************
void BlackjackModel::resetGame()
{
	for (auto player : mcvPlayers)
	{
		player->clearHand();
		Money mon(0, "USD");
		player->setBet(mon);
	}
}

//***************************************************************************
// Function:    deal
//
// Description: deals two cards to all players
//
// Parameters:  None
//
// Returned:    NONE
//***************************************************************************
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


//***************************************************************************
// Function:    gethand
//
// Description: gets a specified players hand
//
// Parameters:  None
//
// Returned:    std::vector<Hand> the hands of teh player
//***************************************************************************
std::vector<Hand> BlackjackModel::getHand(int seat)
{
	return mcvPlayers[seat]->getHand();
}

//***************************************************************************
// Function:    isPlayerSplit
//
// Description: checks if a player is split
//
// Parameters:  int player - the player to check
//
// Returned:    bool - if the spler is split
//***************************************************************************
bool BlackjackModel::isPlayerSplit(int player)
{
	return mcvPlayers[player]->isSplit();
}

//***************************************************************************
// Function:    getPlayerType
//
// Description: gets a specified player's type
//
// Parameters:  int player - the player to check
//
// Returned:    char - the player type
//***************************************************************************
char BlackjackModel::getPlayerType(int player)
{
	return mcvPlayers[player]->returnType();
}

//***************************************************************************
// Function:    getBank
//
// Description: gets a specified player's bank
//
// Parameters:  int player - the player to check
//
// Returned:    Money - the player's bank
//***************************************************************************
Money BlackjackModel::getBank(int player)
{
	return mcvPlayers[player]->getMoney();
}


//***************************************************************************
// Function:    reshuffle
//
// Description: reshuffle if not enough cards
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackjackModel::reshuffle() {
	if (mcDeck.getSize() < 10 * mPlayerCount + 1) {
		Deck newDeck(mcDeck.getNumSets());
		mcDeck = newDeck;
	}
}