#include "SDLView.h"
//#include "BlackjackPresenter.h"
#include <sstream>

//***************************************************************************
// Constructor: SDLView
//
// Description: 
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

SDLView::SDLView()
{
}


void SDLView::onDraw() {
}


void SDLView::onAddPlayer(std::string name) {
}


void SDLView::onSetPlayer1Name(std::string name)
{
  mpPlayerNames[0]->setData(name);
}


void SDLView::onSetPlayer2Name(std::string name)
{
  mpPlayerNames[1]->setData(name);
}


void SDLView::onSetPlayer3Name(std::string name)
{
  mpPlayerNames[2]->setData(name);
}


void SDLView::onSetPlayer4Name(std::string name)
{
  mpPlayerNames[3]->setData(name);
}


void SDLView::onSetPlayer5Name(std::string name)
{
  mpPlayerNames[4]->setData(name);
}

void SDLView::deal()
{

}

void SDLView::onClickHit() {}

void SDLView::onClickStay() {}

void SDLView::onClickSplit() {}

void SDLView::onSetBet(std::string) {}

Card SDLView::drawCard() {}

void SDLView::addBet(Money bet) {}

float SDLView::getCurrentTurn() {}

void SDLView::addPlayer(std::string playerName, Money bank) {}

void SDLView::removePlayer(int player) {}

void SDLView::setNumPlayer(int players) {}

void SDLView::resetGame() {}

void SDLView::quitGame() {}

void SDLView::handleEvent(SDL_Event event) {}

void SDLView::render() {}

void SDLView::initGame() {}