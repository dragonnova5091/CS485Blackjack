
#pragma once

#include "IBlackjackView.h"
#include "BlackjackModel.h"
#include "BlackjackPresenter.h"
#include <vector>

BlackjackPresenter::BlackjackPresenter()
{
	*mpcBJView = new IBlackjackView*();
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

void BlackjackPresenter::addBet(Money cBank)
{
	mcBJModel.addBet(cBank);
}

void BlackjackPresenter::doTurn(float turn)
{
	mcBJModel.doTurn(turn);
}
void BlackjackPresenter::resetGame()
{
	mcBJModel.resetGame();
}
