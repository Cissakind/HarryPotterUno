#ifndef _BUILDUNO_
#define _BUILDUNO_

#include <vector>
#include <iostream>
#include "UnoGame.h"

class UnoPlayer;

using namespace std;

class BuildUnoGame {
	UnoGame game;
  public:
  	BuildUnoGame();
  	UnoGame buildUno();
  	UnoGame getGame();
};

#endif