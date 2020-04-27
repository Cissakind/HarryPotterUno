#include "UnoPlayer.h"
#include <vector>
#include <iostream>

using namespace std;
#include "UnoState.h"
#include "UnoGame.h"

class StartingPlay: public UnoState{
	UnoState currentState;
	UnoPlayer currentPlayer;

  public:
  	StartingPlay();
  	UnoState createState(UnoPlayer currentPlayer);
  	int doAction(UnoGame game);
  	void setCurrentPlayer(UnoPlayer currentPlayer);
  	UnoPlayer getCurrentPlayer();

};