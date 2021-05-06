
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
  numPlayers = 1;

  TextUITextWidget* pcWidget;
  mpcBlackjackPresenter = new BlackjackPresenter(this);

  mpPlayerNames.push_back(new TextUITextWidget("Computer 1", ""));

  Money tempMon(100, "USD");
  mpcBlackjackPresenter->addPlayer("Computer 1", tempMon, 0);

  mpBankAmounts.push_back(new TextUITextWidget("Bank: ", std::to_string (tempMon.getAmount())));
  mpDealerWidget = new TextUITextWidget("Dealer", "");

  addWidget(0, 6, mpPlayerNames[0]);
  addWidget(25, 6, mpBankAmounts[0]);
  addWidget(0, 3, mpDealerWidget);

  registerEvent("PLACEBETS",
    std::bind
    (&TextView::onSetBet, this, std::placeholders::_1));

  registerEvent("ADDPLAYER",
    std::bind
    (&TextView::onAddPlayer, this, std::placeholders::_1));

  registerEvent("REMOVEPLAYER",
    std::bind
    (&TextView::onRemovePlayer, this, std::placeholders::_1));

  registerEvent("SETPLAYER1NAME",
    std::bind
    (&TextView::onSetPlayer1Name, this, std::placeholders::_1));
  
  registerEvent("DEAL",
    std::bind(&TextView::onDeal, this, std::placeholders::_1));



  onSetPlayer1Name("Computer 1");

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
  } while ('C' != playerType && 'H' != playerType);

  if (numPlayers + 1 <= 5) {
    addPlayer(playerType, name, cMoney);
  }
  else {
    std::cout << "Alread at max capacity";
  }
}


void TextView::onRemovePlayer(std::string yes) {
  int playerNum;
 
  //
  //if (std::stoi(yes) >= 1 && std::stoi(yes) <= 5)
  //{
  //  mpcBlackjackPresenter->removePlayer(std::stoi(yes) - 1);
  //}

  do {
    std::cout << "Which player would you like to remove? (Please enter player number)";
    std::cin >> playerNum;
  } while (playerNum < 0 && playerNum > 5);

  removePlayer(playerNum);
  mpcBlackjackPresenter->removePlayer(playerNum - 1);
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

void TextView::onDeal(std::string notused)
{
  
  //cCard = mpcBlackjackPresenter.

  registerEvent("HIT",
    std::bind
    (&TextView::onClickHit, this, std::placeholders::_1));

  registerEvent("SPLIT(IFYOUCAN)",
    std::bind
    (&TextView::onClickSplit, this, std::placeholders::_1));

  registerEvent("STAY",
    std::bind
    (&TextView::onClickStay, this, std::placeholders::_1));



    mpcBlackjackPresenter->deal();

}

void TextView::onClickHit (std::string yes) 
{
  float turn;
  turn = mpcBlackjackPresenter->getTurn();

  /*Hung"Sorry i realized i names the params bad. the arguments should go 
  int seat- which plays(index 0-5), int move(stay, split, hit I think), 
  float hands(if they have one hand then 0.0 if they have 2 then pass 0.5."*/
  mpcBlackjackPresenter->doTurn(turn, 0, 0.0);
}

void TextView::onClickStay(std::string yes) 
{
  float turn;
  turn = mpcBlackjackPresenter->getTurn();

  mpcBlackjackPresenter->doTurn(turn, 2, 0.0);
}

void TextView::onClickSplit(std::string yes) 
{
  float turn;
  turn = mpcBlackjackPresenter->getTurn();

  mpcBlackjackPresenter->doTurn(turn, 1, 0.5);
}

void TextView::onSetBet(std::string yes) 
{
  Money cMoney;
  long long bet;

  for (int i = 0; i < numPlayers; i++) {
    std::cout << "Enter Bet: ";
    std::cin >> bet;
    cMoney.setAmount(bet);
    mpcBlackjackPresenter->addBet(i, cMoney);
  }


}

Card TextView::drawCard () 
{
    Card drawnCard = mpcBlackjackPresenter->getCard();
    return drawnCard;
}

void TextView::addBet (Money bet) 
{
  mpcBlackjackPresenter->addBet(mpcBlackjackPresenter->getTurn(), bet);
}

float TextView::getCurrentTurn () 
{
  return mpcBlackjackPresenter->getTurn();
}

void TextView::addPlayer(char playerType, std::string playerName, Money cBank) 
{
  numPlayers++;
  mpcBlackjackPresenter->addPlayer(playerName, cBank, numPlayers);
  mpPlayerNames.push_back(new TextUITextWidget("Player" +  std::to_string (numPlayers), playerName));
  mpBankAmounts.push_back(new TextUITextWidget("Bank: ", std::to_string(cBank.getAmount())));


  if (numPlayers == 2) {
    addWidget(0, 9, mpPlayerNames[1]);
    addWidget(25, 9, mpBankAmounts[1]);

    registerEvent(("SETPLAYER2NAME"),
      std::bind
      (&TextView::onSetPlayer2Name, this, std::placeholders::_1));

    onSetPlayer2Name(playerName);
  }
  else if (numPlayers == 3) {
    addWidget(0, 12, mpPlayerNames[2]);
    addWidget(25, 12, mpBankAmounts[2]);

    registerEvent(("SETPLAYER3NAME"),
      std::bind
      (&TextView::onSetPlayer3Name, this, std::placeholders::_1));

    onSetPlayer3Name(playerName);
  }
  else if (numPlayers == 4) {
    addWidget(0, 15, mpPlayerNames[3]);
    addWidget(25, 15, mpBankAmounts[3]);

    registerEvent(("SETPLAYER4NAME"),
      std::bind
      (&TextView::onSetPlayer4Name, this, std::placeholders::_1));

    onSetPlayer4Name(playerName);
  }
  else if (numPlayers == 5) {
    addWidget(0, 18, mpPlayerNames[4]);
    addWidget(25, 18, mpBankAmounts[4]);

    registerEvent(("SETPLAYER5NAME"),
      std::bind
      (&TextView::onSetPlayer5Name, this, std::placeholders::_1));

    onSetPlayer5Name(playerName);
  }

  onDraw();
}

void TextView::removePlayer (int player) 
{
  auto it = mpPlayerNames.begin();
  it += player - 1;
  delete mpPlayerNames[player - 1];
  mpPlayerNames.erase(it);

  auto iter = mpBankAmounts.begin();
  iter += player - 1;
  delete mpBankAmounts[player - 1];
  mpBankAmounts.erase(iter);

  numPlayers--;
  
  /*for (int i = player; i < numPlayers; i++) {
    mpPlayerNames[i - 1]->setData(mpPlayerNames[i]->getData());
  }*/
}

void TextView::setNumPlayer (int players) 
{
  mpcBlackjackPresenter->setNumPlayers(players);
}

void TextView::resetGame () 
{
  mpcBlackjackPresenter->resetGame();
}

void TextView::quitGame() 
{
}