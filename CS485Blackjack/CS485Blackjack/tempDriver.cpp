

//#include "SDLApp.h"
//#include "TextUI.h"
#include "SDLView.h"
#include "Deck.h"

int main()
{

  SDLView cTheDisplay;

  cTheDisplay.createWindow("SDL View",
    100, 100, 640, 640);

  cTheDisplay.setWindowBackgroundColor({ 0,0,0,255 });

  cTheDisplay.gameLoop();

  cTheDisplay.cleanup();
  return EXIT_SUCCESS;
}