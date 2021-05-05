#include "SDLView.h"
#include "BlackjackPresenter.h"
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
  long long amount;
  char playerType;
  Money cMoney;

  std::cout << "Initial Bank Amount:";
  std::cin >> amount;
  cMoney.setAmount(amount);

  do {
    std::cout << "Human (H) or Computer (C) player?";
    std::cin >> playerType;
  } while ('C' == playerType || 'H' == playerType);

  if (numPlayers + 1 <= 5) {
    addPlayer(playerType, name, cMoney);
  }
  else {
    std::cout << "Alread at max capacity";
  }
}


void SDLView::onRemovePlayer(std::string yes) {
  int playerNum;

  do {
    std::cout << "Which player would you like to remove? (Please enter player number)";
    std::cin >> playerNum;
  } while (playerNum > 0 && playerNum <= 5);

  mpcBlackjackPresenter->removePlayer(playerNum);
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

void SDLView::addPlayer(char playerType, std::string playerName, Money bank) {}

void SDLView::removePlayer(int player) {
  for (int i = player; i < numPlayers; i++) {
    mpPlayerNames[i - 1]->setData(mpPlayerNames[i]->getData());
  }

  numPlayers--;
}

void SDLView::setNumPlayer(int players) {
  mpcBlackjackPresenter->setNumPlayers(players);
}

void SDLView::resetGame() {
  mpcBlackjackPresenter->resetGame();
}

void SDLView::quitGame() {}

void SDLView::handleEvent(SDL_Event event) {}

void SDLView::render() {}

void SDLView::initGame() {}