
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
  numHumanPlayers = 1;
  mCurrentTurn = 0;
  mFirstRun = true;

  //TextUITextWidget* pcWidget;
  mpcBlackjackPresenter = new BlackjackPresenter(this);

  mpPlayerNames.push_back(new TextUITextWidget("Dealer", "Doug"));
  mpPlayerNames.push_back(new TextUITextWidget("Player1", ""));

  Money tempMon(100, "USD");
  mpcBlackjackPresenter->addPlayer("Doug", tempMon, 0, 'D');
  mCardCounter.push_back(0);
  mbShow.push_back(false);


  mpBankAmounts.push_back(new TextUITextWidget("Bank: ", std::to_string (tempMon.getAmount())));

  mpPlayerNames.push_back(new TextUITextWidget("Player2", "NOT IN USE"));
  mpBankAmounts.push_back(new TextUITextWidget("Bank: ", "NOT IN USE"));

  mpPlayerNames.push_back(new TextUITextWidget("Player3", "NOT IN USE"));
  mpBankAmounts.push_back(new TextUITextWidget("Bank: ", "NOT IN USE"));

  mpPlayerNames.push_back(new TextUITextWidget("Player4", "NOT IN USE"));
  mpBankAmounts.push_back(new TextUITextWidget("Bank: ", "NOT IN USE"));

  mpPlayerNames.push_back(new TextUITextWidget("Player5", "NOT IN USE"));
  mpBankAmounts.push_back(new TextUITextWidget("Bank: ", "NOT IN USE"));
  
  addWidget(0, 3, mpPlayerNames[0]);
  addWidget(0, 6, mpPlayerNames[1]);
  addWidget(25, 6, mpBankAmounts[0]);
  addWidget(0, 9, mpPlayerNames[2]);
  addWidget(25, 9, mpBankAmounts[1]);
  addWidget(0, 12, mpPlayerNames[3]);
  addWidget(25, 12, mpBankAmounts[2]);
  addWidget(0, 15, mpPlayerNames[4]);
  addWidget(25, 15, mpBankAmounts[3]);
  addWidget(0, 18, mpPlayerNames[5]);
  addWidget(25, 18, mpBankAmounts[4]);

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

  onSetPlayer1Name("Player 1");
  mpcBlackjackPresenter->addPlayer("Player 1", tempMon, 1, 'H');
  mCardCounter.push_back(0);
  mbShow.push_back(false);
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

  if (numPlayers < 5) {
    addPlayer(playerType, name, cMoney);
  }
  else {
    std::cout << "Alread at max capacity";
  }
}


void TextView::onRemovePlayer(std::string yes) {
  int playerNum;

  do {
    std::cout << "Which player would you like to remove? (Please enter player number) ";
    std::cin >> playerNum;
  } while (playerNum < 0 && playerNum > 5);

  removePlayer(playerNum);
  mpcBlackjackPresenter->removePlayer(playerNum);
}


void TextView::onSetPlayer1Name(std::string name)
{
  if (mpPlayerNames[0]->getData() == "NOT IN USE")
  {
  }
  else
  {
    mpPlayerNames[1]->setData(name);
  }
}


void TextView::onSetPlayer2Name(std::string name)
{
  if (mpBankAmounts[1]->getData() == "NOT IN USE")
  {
  }
  else
  {
    mpPlayerNames[2]->setData(name);
  }
}


void TextView::onSetPlayer3Name(std::string name)
{
  if (mpBankAmounts[2]->getData() == "NOT IN USE")
  {
  }
  else
  {
    mpPlayerNames[3]->setData(name);
  }
}


void TextView::onSetPlayer4Name(std::string name)
{
  if (mpBankAmounts[3]->getData() == "NOT IN USE")
  {
  }
  else
  {
    mpPlayerNames[4]->setData(name);
  }
}


void TextView::onSetPlayer5Name(std::string name)
{
  if (mpBankAmounts[4]->getData() == "NOT IN USE")
  {
  }
  else
  {
    mpPlayerNames[5]->setData(name);
  }
}

void TextView::onDeal(std::string notused)
{
  
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
    displayHands();
}

void TextView::onClickHit (std::string yes) 
{
  float turn;
  turn = mpcBlackjackPresenter->getTurn();
  mpcBlackjackPresenter->doTurn((int)turn, 1, 1.0f);
  displayHands();
}

void TextView::onClickStay(std::string yes) 
{
  float turn;
  turn = mpcBlackjackPresenter->getTurn();

  mpcBlackjackPresenter->doTurn((int) turn, 0, 1.0f);
  displayHands();
}

void TextView::onClickSplit(std::string yes) 
{
  float turn;
  turn = mpcBlackjackPresenter->getTurn();

  mpcBlackjackPresenter->doTurn((int ) turn, 2, 0.5f);
  displayHands();
}

void TextView::onSetBet(std::string yes) 
{
  Money cMoney;
  long long bet;
  int row = 1;
  for (int i = 0; i < numPlayers; i++) {
    std::cout << "Enter Bet: ";
    std::cin >> bet;
    cMoney.setAmount(bet);
    mpcBlackjackPresenter->addBet(i, cMoney);
    displayBet(row + 1, i, bet);
    row++;
  }
  registerEvent("DEAL",
    std::bind(&TextView::onDeal, this, std::placeholders::_1));
}

Card TextView::getCard () 
{
  return mpcBlackjackPresenter->getCard();
}

std::vector<Hand> TextView::getHand(int player)
{
  return mpcBlackjackPresenter->getHand(player);
}

void TextView::displayHands()
{
  const int BASE = 2;
  int row = 1;

  if (mbShow[numPlayers] == true && static_cast<int>(getCurrentTurn()) == 0)
  {

    mbShow[numPlayers] = false;
    mbShow[0] = true;
    mpHandWidget[numPlayers][0]->setVisible(false);
    mpHandWidget[0][0]->setVisible(true);
  }
  if (mFirstRun == false)
  {
    for (int i = 1; i <= numPlayers; i++)
    {
      if (static_cast<int>(getCurrentTurn()) == i)
      {
        if (mbShow[i - 1] == true)
        {
          mbShow[i - 1] = false;
          mbShow[i] = true;
          mpHandWidget[i - 1][0]->setVisible(false);
          mpHandWidget[i][0]->setVisible(true);
          i = numPlayers + 1;
        }
      }
    }
  }
  
  mpHandWidget.resize(numPlayers + 1);
  for (int i = 0; i < numPlayers + 1; i++)
  {
    int col = 1;
    //player split
    mvHand = getHand(i);
    mvCards = mvHand[0].getHand();
    
    if (static_cast<int>(mvCards.size()) == BASE && mCardCounter[i] != BASE)
    {
      for (int k = 0; k < mvCards.size(); k++)
      {
        //First two cards
        Suit cardSuit = mvCards[k].getSuit();
        CardName cardName = mvCards[k].getCardName();
        mpHandWidget[i].push_back(new TextUITextWidget(getCardSuit(cardSuit),
          getCardName(cardName)));
        addWidget((17 * col), (row * 3) + 1, mpHandWidget[i][k]);
        col++;
        if (k == 0 && static_cast<int>(getCurrentTurn() != i))
        {
          mpHandWidget[i][k]->setVisible(false);
          mbShow[i] = false;
        }
        else
        {
          mbShow[i] = true;
        }
      }
    }
    else
    {
      //After hit and added card
      int nextIndex = static_cast<int>(mvCards.size() - 1);
      Suit cardSuit = mvCards[nextIndex].getSuit();
      CardName cardName = mvCards[nextIndex].getCardName();
      mpHandWidget[i].push_back(new TextUITextWidget(getCardSuit(cardSuit),
        getCardName(cardName)));
      addWidget((17 * (nextIndex + 1)), (row * 3) + 1, mpHandWidget[i][nextIndex]);
    }
    mCardCounter[i] = static_cast<int>(mvCards.size());
    row++;
  }
  mFirstRun = false;
}

void TextView::displayBet(int row, int player, long long bet)
{
  mpBetAmounts.push_back(new TextUITextWidget("Bet", std::to_string(bet)));
  addWidget(0, (row * 3) + 1, mpBetAmounts[player]);
}

void TextView::addBet (Money bet) 
{
  mpcBlackjackPresenter->addBet(mpcBlackjackPresenter->getTurn(), bet);
}

float TextView::getCurrentTurn () 
{
  mCurrentTurn = mpcBlackjackPresenter->getTurn();
  return mpcBlackjackPresenter->getTurn();
}

void TextView::addPlayer(char playerType, std::string playerName, Money cBank) 
{
  mCardCounter.push_back(0);
  mbShow.push_back(false);
  addBank(numPlayers, cBank);
  numPlayers++;
  mpcBlackjackPresenter->addPlayer(playerName, cBank, numPlayers, playerType);

  if (numPlayers == 2) {
    

    registerEvent(("SETPLAYER2NAME"),
      std::bind
      (&TextView::onSetPlayer2Name, this, std::placeholders::_1));

    onSetPlayer2Name(playerName);
  }
  else if (numPlayers == 3) {
    

    registerEvent(("SETPLAYER3NAME"),
      std::bind
      (&TextView::onSetPlayer3Name, this, std::placeholders::_1));

    onSetPlayer3Name(playerName);
  }
  else if (numPlayers == 4) {
    

    registerEvent(("SETPLAYER4NAME"),
      std::bind
      (&TextView::onSetPlayer4Name, this, std::placeholders::_1));

    onSetPlayer4Name(playerName);
  }
  else if (numPlayers == 5) {
    

    registerEvent(("SETPLAYER5NAME"),
      std::bind
      (&TextView::onSetPlayer5Name, this, std::placeholders::_1));

    onSetPlayer5Name(playerName);
  }

  onDraw();
}

void TextView::addBank(int player, Money cBank)
{
  mpBankAmounts[player]->setData(std::to_string(cBank.getAmount()));
}

void TextView::removeBank(int player)
{
  mpBankAmounts[player - 1]->setData("NOT IN USE");
}

void TextView::removePlayer (int player) 
{

  if (player == 2) {

    onSetPlayer2Name("NOT IN USE");
  }
  else if (player == 3) {

    onSetPlayer3Name("NOT IN USE");
  }
  else if (player == 4) {

    onSetPlayer4Name("NOT IN USE");
  }
  else if (player == 5) {

    onSetPlayer5Name("NOT IN USE");
  }
  removeBank(player);
  

  for (int i = player; i <= numPlayers; i++)
  {
    if (i < 5)
    {
      mpPlayerNames[i]->setData(mpPlayerNames[i + 1]->getData());
      mpBankAmounts[i - 1]->setData(mpBankAmounts[i]->getData());
    }
    else
    {
      mpPlayerNames[i]->setLabel("Player5");
      mpPlayerNames[i]->setData("NOT IN USE");
      mpBankAmounts[i - 1]->setData("NOT IN USE");
    }
    
  }
  

    numPlayers--;
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

std::string TextView::getCardSuit(Suit cardSuit)
{
  std::string toReturn;
  if (cardSuit == Suit::Clubs)
  {
    toReturn = "Clubs";
    
  }
  else if (cardSuit == Suit::Diamonds)
  {
    toReturn = "Diamonds";
  }
  else if (cardSuit == Suit::Hearts)
  { 
    toReturn = "Hearts";
  }
  else
  {
    toReturn = "Spades";
  }

  return toReturn;
}

std::string TextView::getCardName(CardName cardName)
{
  std::string toReturn;
  if (cardName == CardName::Ace)
  {
    toReturn = "Ace";

  }
  else if (cardName == CardName::Two)
  {
    toReturn = "Two";
  }
  else if (cardName == CardName::Three)
  {
    toReturn = "Three";
  }
  else if (cardName == CardName::Four)
  {
    toReturn = "Four";
  }
  else if (cardName == CardName::Five)
  {
    toReturn = "Five";
  }
  else if (cardName == CardName::Six)
  {
    toReturn = "Six";
  }
  else if (cardName == CardName::Seven)
  {
    toReturn = "Seven";
  }
  else if (cardName == CardName::Eight)
  {
    toReturn = "Eight";
  }
  else if (cardName == CardName::Nine)
  {
    toReturn = "Nine";
  }
  else if (cardName == CardName::Ten)
  {
    toReturn = "Ten";
  }
  else if (cardName == CardName::Jack)
  {
    toReturn = "Jack";
  }
  else if (cardName == CardName::Queen)
  {
    toReturn = "Queen";
  }
  else
  {
    toReturn = "King";
  }

  return toReturn;
}