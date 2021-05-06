
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
  virtual void onAddPlayer(std::string);
  virtual void onRemovePlayer(std::string);
  virtual void onSetPlayer1Name(std::string);
  virtual void onSetPlayer2Name(std::string);
  virtual void onSetPlayer3Name(std::string);
  virtual void onSetPlayer4Name(std::string);
  virtual void onSetPlayer5Name(std::string);
  virtual void onSetBet(std::string);
  virtual void onDeal(std::string notused);
  virtual void onClickHit(std::string);
  virtual void onClickStay(std::string);
  virtual void onClickSplit(std::string);
  virtual Card drawCard();

  //events from Presenter
  virtual void addBet(Money Bet);
  virtual float getCurrentTurn();
  virtual void addPlayer(char, std::string, Money);
  virtual void removePlayer(int);
  virtual void setNumPlayer(int);
  virtual void resetGame();
  virtual void quitGame();

private:
  IBlackjackPresenter* mpcBlackjackPresenter;

  std::vector<TextUITextWidget*>mpPlayerNames;
  std::vector<TextUITextWidget*>mpBankAmounts;
  std::vector<TextUITextWidget*>mpBetAmounts;
  TextUITextWidget *mpDealerWidget;

  std::vector<Hand> mvHands;

  int numPlayers;
  int mCurrentTurn;
};