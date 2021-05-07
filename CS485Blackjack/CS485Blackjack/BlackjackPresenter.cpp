
#pragma once

#include "IBlackjackView.h"
#include "BlackjackModel.h"
#include "BlackjackPresenter.h"
#include <vector>

BlackjackPresenter::BlackjackPresenter(IBlackjackView* theView)
{
	
	mpcBJView = theView;
}

BlackjackPresenter::~BlackjackPresenter()
{

}

void BlackjackPresenter::setPlayerName(int seat, std::string& name)
{
	mcBJModel.setPlayerName(seat, name);
}

void BlackjackPresenter::addPlayer(std::string name, Money cBank, int seat, char cplayerType)
{
	mcBJModel.addPlayer(name, cBank, seat, cplayerType);
}

void BlackjackPresenter::removePlayer(int seat)
{
	mcBJModel.removePlayer(seat);
}

void BlackjackPresenter::setNumPlayers(int seats)
{
	mcBJModel.setNumPlayers(seats);
}

void BlackjackPresenter::addBet(int seat, Money cBank)
{
	mcBJModel.addBet(seat, cBank);
}

void BlackjackPresenter::doTurn(float seat, int move, float hands)
{
	mcBJModel.doTurn(static_cast<int>(seat), move, hands);
}

float BlackjackPresenter::getTurn()
{
	return mcBJModel.getTurn();
}

Card BlackjackPresenter::getCard()
{
	return mcBJModel.getCard();
}
void BlackjackPresenter::resetGame()
{
	mcBJModel.resetGame();
}


void BlackjackPresenter::deal()
{
	mcBJModel.deal();
}

std::vector<Hand> BlackjackPresenter::getHand(int seat)
{
	return mcBJModel.getHand(seat);
}

bool BlackjackPresenter::isPlayerSplit(int player)
{
	return mcBJModel.isPlayerSplit(player);
}