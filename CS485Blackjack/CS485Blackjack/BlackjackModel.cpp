

#include "Deck.h"
#include "Player.h"
#include "Money.h"
#include "BlackjackModel.h"
#include <vector>

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

void BlackjackModel::doTurn(int seat, int play, float hands)
{

	mcvPlayers[seat].doTurn(turn);

	if (mTotalRounds == mCurrentTurn)
	{
		mTotalRounds++;
	}
	mCurrentTurn += hands;
}
void BlackjackModel::resetGame()
{

}