
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
  mAfterHit = false;

  mpcBlackjackPresenter = new BlackjackPresenter(this);

  mpPlayerNames.push_back(new TextUITextWidget("Dealer", "Doug"));
  mpPlayerNames.push_back(new TextUITextWidget("Player1", ""));

  Money tempMon(100, "USD");
  mpcBlackjackPresenter->addPlayer("Doug", tempMon, 0, 'D');
  mCardCounter.push_back(0);
  mbShow.push_back(false);


  mpBankAmounts.push_back(new TextUITextWidget("Bank ", std::to_string (tempMon.getAmount())));

  mpPlayerNames.push_back(new TextUITextWidget("Player2", "NOT IN USE"));
  mpBankAmounts.push_back(new TextUITextWidget("Bank ", "NOT IN USE"));

  mpPlayerNames.push_back(new TextUITextWidget("Player3", "NOT IN USE"));
  mpBankAmounts.push_back(new TextUITextWidget("Bank ", "NOT IN USE"));

  mpPlayerNames.push_back(new TextUITextWidget("Player4", "NOT IN USE"));
  mpBankAmounts.push_back(new TextUITextWidget("Bank ", "NOT IN USE"));

  mpPlayerNames.push_back(new TextUITextWidget("Player5", "NOT IN USE"));
  mpBankAmounts.push_back(new TextUITextWidget("Bank ", "NOT IN USE"));
  
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

//***************************************************************************
// Function:    onDraw
//
// Description: draws the widgets to the screen
//
// Parameters:  None
//
// Returned:    NONE
//***************************************************************************
void TextView::onDraw() {
  drawScreen();
}

//***************************************************************************
// Function:    onAddPlayer
//
// Description: From Presenter: Add Player 
//
// Parameters:  name - the name
//
// Returned:    NONE
//***************************************************************************
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

//***************************************************************************
// Function:    onRemovePlayer
//
// Description: From Presenter: remove player 
//
// Parameters:  yes - string to remove player
//
// Returned:    NONE
//***************************************************************************
void TextView::onRemovePlayer(std::string yes) {
  int playerNum;

  do {
    std::cout << "Which player would you like to remove? (Please enter player number) ";
    std::cin >> playerNum;
  } while (playerNum < 0 && playerNum > 5);

  removePlayer(playerNum);
  mpcBlackjackPresenter->removePlayer(playerNum);
}

//***************************************************************************
// Function:    onSetPlayer1Name
//
// Description: From Presenter: sets player's 1 name
//
// Parameters:  name - the name
//
// Returned:    NONE
//***************************************************************************
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

//***************************************************************************
// Function:    onSetPlayer2Name
//
// Description: From Presenter: sets player's 2 name
//
// Parameters:  name - the name
//
// Returned:    NONE
//***************************************************************************
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

//***************************************************************************
// Function:    onSetPlayer3Name
//
// Description: From Presenter: sets player's 3 name
//
// Parameters:  name - the name
//
// Returned:    NONE
//***************************************************************************
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

//***************************************************************************
// Function:    onSetPlayer4Name
//
// Description: From Presenter: sets player's 4 name
//
// Parameters:  name - the name
//
// Returned:    NONE
//***************************************************************************
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

//***************************************************************************
// Function:    onSetPlayer5Name
//
// Description: From Presenter: sets player's 5 name
//
// Parameters:  name - the name
//
// Returned:    NONE
//***************************************************************************
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

//***************************************************************************
// Function:    onDeal
//
// Description: From Presenter: deal card
//
// Parameters:  notused - not used 
//
// Returned:    NONE
//***************************************************************************
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

//***************************************************************************
// Function:    onClickHit
//
// Description: From Presenter: Action Hit
//
// Parameters:  yes - to register Hit move
//
// Returned:    NONE
//***************************************************************************
void TextView::onClickHit (std::string yes) 
{
  float turn;
  turn = mpcBlackjackPresenter->getTurn();
  mpcBlackjackPresenter->doTurn((int)turn, 1, 1.0f);
  mAfterHit = true;
  displayHands();

  if (mpcBlackjackPresenter->getTurn() == -1)
  {
    clearTable();
    resetGame();
  }
}
//***************************************************************************
// Function:    onClickStay
//
// Description: From Presenter: Action Stay
//
// Parameters:  yes - to register Stay move
//
// Returned:    NONE
//***************************************************************************
void TextView::onClickStay(std::string yes) 
{
  float turn;
  turn = mpcBlackjackPresenter->getTurn();

  mpcBlackjackPresenter->doTurn((int) turn, 0, 1.0f);
  displayHands();
  turn = mpcBlackjackPresenter->getTurn();
  if (turn == -1)
  {
    clearTable();
    resetGame();
  }
}
//***************************************************************************
// Function:    onClickSplit
//
// Description: From Presenter: Action Split
//
// Parameters:  yes - to register Split move
//
// Returned:    NONE
//***************************************************************************
void TextView::onClickSplit(std::string yes) 
{
  float turn;
  turn = mpcBlackjackPresenter->getTurn();

  mpcBlackjackPresenter->doTurn((int ) turn, 2, 0.5f);
  displayHands();
}
//***************************************************************************
// Function:    onSetBet
//
// Description: From Presenter: Action Bet
//
// Parameters:  yes - to register Bet move
//
// Returned:    NONE
//***************************************************************************
void TextView::onSetBet(std::string yes) 
{
  Money cMoney;
  long long bet;
  int row = 1;
  for (int i = 1; i <= numPlayers; i++) {
    std::cout << "Enter Bet: ";
    std::cin >> bet;
    cMoney.setAmount(bet);
    mpcBlackjackPresenter->addBet(i, cMoney);
    displayBet(row + 1, i -1, bet);
    row++;
  }
  registerEvent("DEAL",
    std::bind(&TextView::onDeal, this, std::placeholders::_1));
}
//***************************************************************************
// Function:    getCard
//
// Description: From Presenter: get a card from deck
//
// Parameters:  NONE
//
// Returned:    Card that was drawn
//***************************************************************************
Card TextView::getCard () 
{
  return mpcBlackjackPresenter->getCard();
}
//***************************************************************************
// Function:    getHand
//
// Description: From Presenter: Gets player hand
//
// Parameters:  player - player's hand to get
//
// Returned:    NONE
//***************************************************************************
std::vector<Hand> TextView::getHand(int player)
{
  return mpcBlackjackPresenter->getHand(player);
}
//***************************************************************************
// Function:    displayHands
//
// Description: Displays all player's hands
//
// Parameters:  NONE
//
// Returned:    NONE
//***************************************************************************
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
    else if (i == static_cast<int>(getCurrentTurn()) && mAfterHit)
    {
      //After hit
      int Index = static_cast<int>(getCurrentTurn());
      int prevIndex = static_cast<int>(mvCards.size() - 1);
      Suit cardSuit = mvCards[prevIndex].getSuit();
      CardName cardName = mvCards[prevIndex].getCardName();
      mpHandWidget[Index].push_back(new TextUITextWidget(getCardSuit(cardSuit),
        getCardName(cardName)));
      addWidget((17 * (prevIndex + 1)), (row * 3) + 1, mpHandWidget[Index][prevIndex]);
      mAfterHit = false;
    }
    mCardCounter[i] = static_cast<int>(mvCards.size());
    row++;
  }
  mFirstRun = false;
}
//***************************************************************************
// Function:    displayBet
//
// Description: display bet
//
// Parameters:  row    - row that player is displayed on
//              player - player to show bet
//              bet    - bet amount
//
// Returned:    NONE
//***************************************************************************
void TextView::displayBet(int row, int player, long long bet)
{
  mpBetAmounts.push_back(new TextUITextWidget("Bet", std::to_string(bet)));
  addWidget(0, (row * 3) + 1, mpBetAmounts[player]);
}
//***************************************************************************
// Function:    addBet
//
// Description: Add player's bet
//
// Parameters:  bet - amount of Bet
//
// Returned:    NONE
//***************************************************************************
void TextView::addBet (Money bet) 
{
  mpcBlackjackPresenter->addBet(mpcBlackjackPresenter->getTurn(), bet);
}
//***************************************************************************
// Function:    getCurrentTurn
//
// Description: Get current Turn
//
// Parameters:  NONE
//
// Returned:    NONE
//***************************************************************************
float TextView::getCurrentTurn () 
{
  mCurrentTurn = mpcBlackjackPresenter->getTurn();
  return mpcBlackjackPresenter->getTurn();
}
//***************************************************************************
// Function:    addPlayer
//
// Description: add player
//
// Parameters:  playertype - human or computer
//              playerName - Player's name
//              cBank      - Player's bank
//
// Returned:    NONE
//***************************************************************************
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
//***************************************************************************
// Function:    addBank
//
// Description: sets player's bank
//
// Parameters:  player - player's bank to add
//              cBank  - bank account to add
//
// Returned:    NONE
//***************************************************************************
void TextView::addBank(int player, Money cBank)
{
  mpBankAmounts[player]->setData(std::to_string(cBank.getAmount()));
}
//***************************************************************************
// Function:    removeBank
//
// Description: removes player's bank
//
// Parameters:  player - player's bank to remove
//
// Returned:    NONE
//***************************************************************************
void TextView::removeBank(int player)
{
  mpBankAmounts[player - 1]->setData("NOT IN USE");
}
//***************************************************************************
// Function:    removePlayer
//
// Description: remove Player
//
// Parameters:  player - player to remove
//
// Returned:    NONE
//***************************************************************************
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
//***************************************************************************
// Function:    setNumPlayer
//
// Description: sets Number of players
//
// Parameters:  players - number of players
//
// Returned:    NONE
//***************************************************************************
void TextView::setNumPlayer (int players) 
{
  mpcBlackjackPresenter->setNumPlayers(players);
}
//***************************************************************************
// Function:    resetGame
//
// Description: Resets the Game
//
// Parameters:  NONE
//
// Returned:    NONE
//***************************************************************************
void TextView::resetGame () 
{
  mpcBlackjackPresenter->resetGame();
}
//***************************************************************************
// Function:    quitGame
//
// Description: Quits the game
//
// Parameters:  NONE
//
// Returned:    NONE
//***************************************************************************
void TextView::quitGame() 
{
}
//***************************************************************************
// Function:    getCardSuit
//
// Description: Get the Card Suit
//
// Parameters:  cardSuit - suit of card
//
// Returned:    Card suit
//***************************************************************************
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
//***************************************************************************
// Function:    getCardName
//
// Description: get the Card Name
//
// Parameters:  cardName - card Name 
//
// Returned:    String of card name
//***************************************************************************
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
//***************************************************************************
// Function:    clearTable
//
// Description: Clears widgets after round is finished
//
// Parameters:  None
//
// Returned:    NONE
//***************************************************************************
void TextView::clearTable()
{
  int row = 1;
  auto it = mpBetAmounts.begin();
  for (int i = 0; i < numPlayers + 1; i++)
  {
    int col = 1;
    mvHand = getHand(i);
    mvCards = mvHand[0].getHand();
    for (int k = 0; k < mvCards.size(); k++)
    {
      removeWidget(17 * col, (row * 3) + 1);
      delete mpHandWidget[i][k];
      col++;
    }
    mpHandWidget[i].clear();
    row++;
  }

  for (int i = 0; i < numPlayers; i++)
  {
    updateBank(i);
  }
  
  row = 2;
  for (int i = 0; i < mpBetAmounts.size(); i++)
  {
    removeWidget(0, (row * 3) + 1);
    delete mpBetAmounts[i];
    
    row++;
  }
  mpBetAmounts.clear();
}
//***************************************************************************
// Function:    updateBank
//
// Description: Updates bank amount
//
// Parameters:  player - player's bank that needs to be updated
//
// Returned:    NONE
//***************************************************************************
void TextView::updateBank(int player)
{
  mpBankAmounts[player]->setData(std::to_string
  (mpcBlackjackPresenter->getBank(player + 1).getAmount()));
}