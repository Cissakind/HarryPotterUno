#include <vector>
#include <iostream>

#include "UnoPlayer.h"

class UnoGame;
class UnoPlayer;

using namespace std;


class UnoState {
	// currentState;
	UnoPlayer currentPlayer;
  public:
  	UnoState();

  	int startGame(UnoGame &game);
    int startPlay(UnoGame &game);
    int endPlay(UnoGame &game);
  	//virtual UnoState changeState(UnoPlayer currentPlayer);

  	enum gamestate {
  		STARTGAME,
  		STARTPLAY,
  		ENDPLAY,
  		ENDGAME,
      FINISHGAME
  	};

};