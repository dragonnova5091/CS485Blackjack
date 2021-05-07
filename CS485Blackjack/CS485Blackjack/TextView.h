
#pragma once

#include "IBlackjackView.h"
#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>
#include "TextUI.h"
#include "TextUITextWidget.h"
#include "IBlackjackPresenter.h"
#include "BlackjackPresenter.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

class TextView : public IBlackjackView, public TextUI 
{
public:
  TextView();

  virtual ~TextView() {}

  virtual void onDraw();

  //events from UI
  virtual void onAddPlayer(std::string yes);
  virtual void onRemovePlayer(std::string yes);
  virtual void onSetPlayer1Name(std::string yes);
  virtual void onSetPlayer2Name(std::string yes);
  virtual void onSetPlayer3Name(std::string yes);
  virtual void onSetPlayer4Name(std::string yes);
  virtual void onSetPlayer5Name(std::string yes);
  virtual void onSetBet(std::string yes);
  virtual void onDeal(std::string notused);
  virtual void onClickHit(std::string yes);
  virtual void onClickStay(std::string yes);
  virtual void onClickSplit(std::string yes);
  virtual Card getCard();
  virtual void removeBank(int player);
  virtual void addBank(int player, Money cBank);

  //events from Presenter
  virtual void addBet(Money Bet);
  virtual float getCurrentTurn();
  virtual void addPlayer(char playerType, std::string playerName, Money cBank);
  virtual void removePlayer(int player);
  virtual void setNumPlayer(int player);
  virtual void resetGame();
  virtual void quitGame();
  virtual std::vector<Hand> getHand(int player);
  virtual void displayHands();
  void displayBet(int row, int player, long long bet);
  std::string getCardSuit(Suit cardSuit);
  std::string getCardName(CardName cardName);

private:
  IBlackjackPresenter* mpcBlackjackPresenter;

  std::vector<TextUITextWidget*>mpPlayerNames;
  std::vector<TextUITextWidget*>mpBankAmounts;
  std::vector<TextUITextWidget*>mpBetAmounts;
  std::vector<int>mCardCounter;

  std::vector<Hand> mvHand;
  std::vector<Card> mvCards;
  std::vector<std::vector<TextUITextWidget*>> mpHandWidget;

  int numPlayers;
  int numHumanPlayers;
  int mCurrentTurn;
};