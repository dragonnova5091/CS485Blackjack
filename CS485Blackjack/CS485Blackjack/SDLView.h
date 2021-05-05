#pragma once
#include "IBlackjackView.h"
#include <string>
#include <map>
#include <functional>
#include <vector>
#include "SDLApp.h"
#include "SDLTextWidget.h"
#include "SDLSprite.h"
#include "IBlackjackPresenter.h"
#include "Player.h"

class SDLView : public IBlackjackView, public SDLApp
{
public:
	SDLView();
	virtual ~SDLView();

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
  virtual void deal();
  virtual void onClickHit();
  virtual void onClickStay();
  virtual void onClickSplit();
  virtual Card drawCard();

  //events from Presenter
  virtual void addBet(Money Bet);
  virtual float getCurrentTurn();
  virtual void addPlayer(char, std::string, Money);
  virtual void removePlayer(int);
  virtual void setNumPlayer(int);
  virtual void resetGame();
  virtual void quitGame();

  virtual void onSetPlayer1NameWidget(SDLTextWidget* pcWidget);
  virtual void onSetPlayer2NameWidget(SDLTextWidget* pcWidget);
  virtual void onSetPlayer3NameWidget(SDLTextWidget* pcWidget);
  virtual void onSetPlayer4NameWidget(SDLTextWidget* pcWidget);
  virtual void onSetPlayer5NameWidget(SDLTextWidget* pcWidget);

  virtual void handleEvent(SDL_Event event);
  virtual void render();
  virtual void initGame();

private:

  IBlackjackPresenter* mpcBlackjackPresenter;

  // UI control

  std::vector<ISDLWidget*> mcDrawableWidgets;

  std::vector<SDLTextWidget*>mpPlayerNames;
  std::vector<SDLTextWidget*>mpBankAmounts;
  SDLTextWidget* mpDealerWidget;

  std::vector<std::vector<Card>> mvCards;

  int numPlayers;
};