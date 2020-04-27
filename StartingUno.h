/*#ifndef _STARTUNO_
#define _STARTUNO_

#include "UnoState.h"
#include "UnoPlayer.h"
#include <vector>
#include <iostream>

using namespace std;

class UnoGame;

class StartingUno: public UnoState{
	UnoState currentState;
	UnoPlayer currentPlayer;

  public:
  	StartingUno();
  	UnoState createState(UnoPlayer currentPlayer);
  	int doAction(UnoGame game);
  	void setCurrentPlayer(UnoPlayer currentPlayer);
  	UnoPlayer getCurrentPlayer();

};

#endif*/