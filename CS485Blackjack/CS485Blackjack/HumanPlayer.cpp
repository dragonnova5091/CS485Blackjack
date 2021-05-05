
#include "HumanPlayer.h"

HumanPlayer::HumanPlayer() : Player()
{
	
}


HumanPlayer::HumanPlayer(std::string name, Money mon)
{
	mName = name;
	mBank = mon;
}
