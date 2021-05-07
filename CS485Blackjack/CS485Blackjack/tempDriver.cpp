


#include "SDLView.h"
#include "TextView.h"
#include "Deck.h"

int main(int argc, char* argv[])
{

  /*SDLView cTheDisplay;

  cTheDisplay.createWindow("SDL View",
    100, 100, 640, 640);

  cTheDisplay.setWindowBackgroundColor({ 0,0,0,255 });

  cTheDisplay.gameLoop();

  cTheDisplay.cleanup();*/
  TextView cView;

  cView.UIEventLoop();

  /*SDLView view;
  view.createWindow("Blackjack",
    100, 100, 640, 640);;
  view.setWindowBackgroundColor({ 0,0,0,255 });
  view.gameLoop();
  view.cleanup();*/

  return EXIT_SUCCESS;
}