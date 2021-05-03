
#include "TextView.h"
//#include "BlackjackPresenter.h"
#include <sstream>

//***************************************************************************
// Constructor: TextView
//
// Description: Initialize the on-screen widgets, hookup event handlders,
//              load fonts, register widgets with TextUI
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

TextView::TextView() : TextUI(std::cout, std::cin)
{
  TextUITextWidget* pcWidget;
  //mpcBlackjackPresenter = new BlackJackPresenter(this);

  //mpPlayers[0] = new HumanPlayer
  mpPlayerNames.push_back(new TextUITextWidget("Player1", ""));
  //mpDealer = new Dealer();
  mpDealerWidget = new TextUITextWidget("Dealer", "");

  addWidget(0, 7, mpPlayerNames[0]);
  addWidget(0, 5, mpDealerWidget);

  registerEvent("READY TO PLACE BETS?",
    std::bind
    (&TextView::onSetBet, this, std::placeholders::_1));

  registerEvent("ADD PLAYER",
    std::bind
    (&TextView::onAddPlayer, this, std::placeholders::_1));

  registerEvent("SET PLAYER1 NAME",
    std::bind
    (&TextView::onSetPlayer1Name, this, std::placeholders::_1));

  onSetPlayer1Name("Player1");

}


void TextView::onDraw() {
  drawScreen();
}


void TextView::onAddPlayer(std::string name) {
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

  //if (numPlayers + 1 <= 5) {
    numPlayers++;
    //mpcBlackjackPresenter.addPlayer(name, cMoney, numPlayers)
    mpPlayerNames.push_back(new TextUITextWidget("Player" + numPlayers, name));
    if ('C' == playerType) {
      //mpPlayers.push_back(new ComputerPlayer(name, cMoney));
    }
    else {
      //mpPlayer.push_bank(new HumanPlayer(name, cMoney));
    }
  //}
  //else {
    //std::cout << "Alread at max capacity";
  //}

  if (numPlayers == 2) {
    addWidget(0, 9, mpPlayerNames[1]);

    registerEvent(("SET PLAYER2 NAME"),
      std::bind
      (&TextView::onSetPlayer2Name, this, std::placeholders::_1));

    onSetPlayer2Name(name);
  }
  else if (numPlayers == 3) {
    addWidget(0, 11, mpPlayerNames[2]);

    registerEvent(("SET PLAYER3 NAME"),
      std::bind
      (&TextView::onSetPlayer3Name, this, std::placeholders::_1));

    onSetPlayer3Name(name);
  }
  else if (numPlayers == 4) {
    addWidget(0, 13, mpPlayerNames[3]);

    registerEvent(("SET PLAYER4 NAME"),
      std::bind
      (&TextView::onSetPlayer4Name, this, std::placeholders::_1));

    onSetPlayer4Name(name);
  }
  else if (numPlayers == 5) {
    addWidget(0, 15, mpPlayerNames[4]);

    registerEvent(("SET PLAYER5 NAME"),
      std::bind
      (&TextView::onSetPlayer5Name, this, std::placeholders::_1));

    onSetPlayer5Name(name);
  }

  onDraw();
}


void TextView::onSetPlayer1Name(std::string name)
{
  mpPlayerNames[0]->setData(name);
}


void TextView::onSetPlayer2Name(std::string name)
{
  mpPlayerNames[1]->setData(name);
}


void TextView::onSetPlayer3Name(std::string name)
{
  mpPlayerNames[2]->setData(name);
}


void TextView::onSetPlayer4Name(std::string name)
{
  mpPlayerNames[3]->setData(name);
}


void TextView::onSetPlayer5Name(std::string name)
{
  mpPlayerNames[4]->setData(name);
}

void TextView::deal()
{

}

void TextView::onClickHit () {}

void TextView::onClickStay() {}

void TextView::onClickSplit() {}

void TextView::onSetBet(std::string) {}

Card TextView::drawCard () {}

void TextView::addBet (Money bet) {}

float TextView::getCurrentTurn () {}

void TextView::addPlayer(std::string playerName, Money bank) {}

void TextView::removePlayer (int player) {}

void TextView::setNumPlayer (int players) {}

void TextView::resetGame () {}

void TextView::quitGame() {}