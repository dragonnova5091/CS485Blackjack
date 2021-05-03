
#pragma once

#include "IBlackjackView.h"
#include <string>
#include <map>
#include <functional>
#include <vector>
#include "TextUI.h"
#include "TextUITextWidget.h"
#include "IBlackjackPresenter.h"
#include "Player.h"

class TextView : public IBlackjackView, public TextUI 
{
public:
  TextView();

  virtual ~TextView();

  virtual void onDraw();

  //events from UI
  virtual void onAddPlayer(std::string);
  virtual void onSetPlayer1Name(std::string);
  virtual void onSetPlayer2Name(std::string);
  virtual void onSetPlayer3Name(std::string);
  virtual void onSetPlayer4Name(std::string);
  virtual void onSetPlayer5Name(std::string);
  virtual void onSetBet(std::string);
  virtual void deal();
  virtual void onClickHit();
  virtual void onClickStay();
  virtual void onClickSplit();
  virtual Card drawCard();

  //events from Presenter
  virtual void addBet(Money Bet);
  virtual float getCurrentTurn();
  virtual void addPlayer(std::string, Money);
  virtual void removePlayer(int);
  virtual void setNumPlayer(int);
  virtual void resetGame();
  virtual void quitGame();

private:
  //IBlackjackPresenter* mpcBlackjackPresenter;

  std::vector<TextUITextWidget*>mpPlayerNames;
  std::vector<TextUITextWidget*>mpBankAmounts;
  //std::vector<Player*>mpPlayers;
  TextUITextWidget *mpDealerWidget;
  //Dealer *mpDealer;

  int numPlayers;
};