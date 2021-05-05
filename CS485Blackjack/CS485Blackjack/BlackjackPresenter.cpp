
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
	delete mpcBJView;
}

void BlackjackPresenter::setPlayerName(int seat, std::string& name)
{
	mcBJModel.setPlayerName(seat, name);
}

void BlackjackPresenter::addPlayer(std::string name, Money cBank, int seat) 
{
	mcBJModel.addPlayer(name, cBank, seat);
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

void BlackjackPresenter::doTurn(int seat, int play, float turn)
{
	mcBJModel.doTurn(seat, play, turn);
}

float BlackjackPresenter::getTurn()
{
	return mcBJModel.getTurn();
}
void BlackjackPresenter::resetGame()
{
	mcBJModel.resetGame();
}
