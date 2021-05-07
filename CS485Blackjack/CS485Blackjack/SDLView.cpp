

#include "SDLView.h"
#include "BlackjackPresenter.h"
#include <math.h>
#include <sstream>
#include "SDLApp.h"

//***************************************************************************
// Constructor: SDLView
//
// Description: 
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

SDLView::SDLView() {
  mpcBlackjackPresenter = new BlackjackPresenter(this);
  mpPlayerNames.push_back(new SDLTextWidget("Player1", "", 10, 20, 1, 
    { 255,255,255,255 }));
  mpDealerWidget = new SDLTextWidget("Dealer", "", 10, 120, 1,
    { 255,255,255,255 });

  //enableTextInput();

  registerTextWidget(mpPlayerNames[0]);
  registerTextWidget(mpDealerWidget);

  mcDrawableWidgets.push_back(mpPlayerNames[0]);
  mcDrawableWidgets.push_back(mpDealerWidget);
  mCurrentTurn = 0;
  mNumPlayers = 0;
}

SDLView::~SDLView() {

  delete mpcBlackjackPresenter;
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

  if (mNumPlayers + 1 <= 5) {
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

void SDLView::onDeal(std::string notused)
{
  int dealTable = 0;
  int maxDeal = 2;
  while (dealTable < maxDeal)
  {
    for (int i = 0; i < static_cast<int>(mpPlayerNames.size()) + 1; i++)
    {
      mvCards[i].push_back(drawCard());
      //first time though load the card back
      if (dealTable == 0)
      {
        mcCards[i][0].loadSprite(this, "Sprites//CardBack.PNG", 100, i * 20);
      }
      else
      {
        //Somehow get sprite of card drawn
        //mcCards[i][1].loadSprite(this, "Sprites//CardBack.PNG", 200, 400);
      }
    }
    dealTable++;
  }
}

/*Hung"Sorry i realized i names the params bad. the arguments should go
int seat- which plays(index 0-5), int move(stay, split, hit I think),
float hands(if they have one hand then 0.0 if they have 2 then pass 0.5."*/
void SDLView::onClickHit(std::string) {
  Card drawnCard;
  drawnCard = drawCard();
  int currentTurn;
  currentTurn = static_cast<int>(std::floor(getCurrentTurn()));
  mvCards[currentTurn].push_back(drawnCard);
  //Somehow get sprite of card drawn
  //mcCard.loadSprite (this, "Sprites\\Card.png", 400, 400);
  mpcBlackjackPresenter->doTurn(currentTurn, 2, 1);
}

/*Hung"Sorry i realized i names the params bad. the arguments should go
int seat- which plays(index 0-5), int move(stay, split, hit I think),
float hands(if they have one hand then 0.0 if they have 2 then pass 0.5."*/
void SDLView::onClickStay(std::string) {
  int currentTurn;
  currentTurn = static_cast<int>(std::floor(getCurrentTurn()));
  mpcBlackjackPresenter->doTurn(currentTurn, 0, 1);
}

/*Hung"Sorry i realized i names the params bad. the arguments should go
int seat- which plays(index 0-5), int move(stay, split, hit I think),
float hands(if they have one hand then 0.0 if they have 2 then pass 0.5."*/
void SDLView::onClickSplit(std::string) {
  int currentTurn;
  currentTurn = static_cast<int>(std::floor(getCurrentTurn()));
  mpcBlackjackPresenter->doTurn(currentTurn, 1, 0.5);
}

void SDLView::onSetBet(std::string) {}

Card SDLView::drawCard() {
  Card drawnCard;
  drawnCard = mpcBlackjackPresenter->getCard();
  return drawnCard;
}

void SDLView::addBet(Money bet) {
  int currentTurn;
  currentTurn = static_cast<int>(std::floor(getCurrentTurn()));

  mpcBlackjackPresenter->addBet(currentTurn, bet);
}

float SDLView::getCurrentTurn() {
  return mpcBlackjackPresenter->getTurn();
}

void SDLView::addPlayer(char playerType, std::string playerName, Money cBank) {

  mNumPlayers++;
  mpcBlackjackPresenter->addPlayer(playerName, cBank, mNumPlayers, playerType);
  mpPlayerNames.push_back(new SDLTextWidget("Player" + mNumPlayers, "",
    10, 20 * mNumPlayers, 1, { 255,255,255,255 }));
  registerTextWidget(mpPlayerNames[mNumPlayers]);
  mcDrawableWidgets.push_back(mpPlayerNames[mNumPlayers]);

  if (mNumPlayers == 2) {

    mpPlayerNames[1]->registerStateChangeEventHandler
    (std::bind
    (&SDLView::onSetPlayer2NameWidget, this, mpPlayerNames[1]));

    onSetPlayer2Name(playerName);
  }
  else if (mNumPlayers == 3) {
  
    mpPlayerNames[2]->registerStateChangeEventHandler
    (std::bind
    (&SDLView::onSetPlayer2NameWidget, this, mpPlayerNames[2]));

    onSetPlayer3Name(playerName);
  }
  else if (mNumPlayers == 4) {

    mpPlayerNames[3]->registerStateChangeEventHandler
    (std::bind
    (&SDLView::onSetPlayer2NameWidget, this, mpPlayerNames[3]));

    onSetPlayer4Name(playerName);
  }
  else if (mNumPlayers == 5) {

    mpPlayerNames[4]->registerStateChangeEventHandler
    (std::bind
    (&SDLView::onSetPlayer2NameWidget, this, mpPlayerNames[4]));

    onSetPlayer5Name(playerName);
  }
}

void SDLView::removePlayer(int player) {
  for (int i = player; i < mNumPlayers; i++) {
    mpPlayerNames[i - 1]->setData(mpPlayerNames[i]->getData());
  }

  mNumPlayers--;
}

void SDLView::setNumPlayer(int players) {
  mpcBlackjackPresenter->setNumPlayers(players);
}

void SDLView::resetGame() {
  mpcBlackjackPresenter->resetGame();
}

void SDLView::quitGame() {}

void SDLView::onSetPlayer1NameWidget (SDLTextWidget* pcWidget) {
  onSetPlayer1Name(pcWidget->getData());
}
void SDLView::onSetPlayer2NameWidget (SDLTextWidget* pcWidget) {
  onSetPlayer2Name(pcWidget->getData());
}
void SDLView::onSetPlayer3NameWidget (SDLTextWidget* pcWidget) {
  onSetPlayer3Name(pcWidget->getData());
}
void SDLView::onSetPlayer4NameWidget (SDLTextWidget* pcWidget) {
  onSetPlayer4Name(pcWidget->getData());
}
void SDLView::onSetPlayer5NameWidget (SDLTextWidget* pcWidget) {
  onSetPlayer5Name(pcWidget->getData());
}

void SDLView::handleEvent(SDL_Event event) {
  int x, y;

  if (event.type == SDL_MOUSEBUTTONDOWN &&
    event.button.button == SDL_BUTTON_LEFT)
  {
    x = event.button.x;
    y = event.button.y;
    // Check if the rectangle over the textWidget of the action is clicked 
    //What ever action is clicked call onClick(Action)
  }
}

void SDLView::render() {
  for (auto value : mcDrawableWidgets) {
    if (value->isVisible()) {
      value->draw(*this);
    }
  }
  // Draw cards next to player
}

void SDLView::initGame() {}

Card SDLView::getCard()
{
    return mpcBlackjackPresenter->getCard();
}

std::vector<Hand> SDLView::getHand(int player)
{
    return mpcBlackjackPresenter->getHand(player);
}

void SDLView::displayHand()
{
    //yay
}