//***************************************************************************
// File name:  BlackjackPresenter.cpp
// Author:     hung Huynh
// Date:       5-6-2021
// Class:      CS485
// Assignment: BlackJack
// Purpose:    presenter implementation
//***************************************************************************


#pragma once

#include "IBlackjackView.h"
#include "BlackjackModel.h"
#include "BlackjackPresenter.h"
#include <vector>


//***************************************************************************
// Function:    BlackjackPresenter ctor
//
// Description: ctor
//
// Parameters:  IBlackjackView* theView
//
// Returned:    None
//***************************************************************************
BlackjackPresenter::BlackjackPresenter(IBlackjackView* theView)
{
	
	mpcBJView = theView;
}

//***************************************************************************
// Function:    BlackjackPresenter dtor
//
// Description: dtor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
BlackjackPresenter::~BlackjackPresenter()
{

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
void BlackjackPresenter::setPlayerName(int seat, std::string& name)
{
	mcBJModel.setPlayerName(seat, name);
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
void BlackjackPresenter::addPlayer(std::string name, Money cBank, int seat, char cplayerType)
{
	mcBJModel.addPlayer(name, cBank, seat, cplayerType);
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
void BlackjackPresenter::removePlayer(int seat)
{
	mcBJModel.removePlayer(seat);
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
void BlackjackPresenter::setNumPlayers(int seats)
{
	mcBJModel.setNumPlayers(seats);
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
void BlackjackPresenter::addBet(int seat, Money cBank)
{
	mcBJModel.addBet(seat, cBank);
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
void BlackjackPresenter::doTurn(float seat, int move, float hands)
{
	mcBJModel.doTurn(static_cast<int>(seat), move, hands);
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
float BlackjackPresenter::getTurn()
{
	return mcBJModel.getTurn();
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
Card BlackjackPresenter::getCard()
{
	return mcBJModel.getCard();
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
void BlackjackPresenter::resetGame()
{
	mcBJModel.resetGame();
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
void BlackjackPresenter::deal()
{
	mcBJModel.deal();
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
std::vector<Hand> BlackjackPresenter::getHand(int seat)
{
	return mcBJModel.getHand(seat);
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
bool BlackjackPresenter::isPlayerSplit(int player)
{
	return mcBJModel.isPlayerSplit(player);
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
char BlackjackPresenter::getPlayerType(int player)
{
	return mcBJModel.getPlayerType(player);
}