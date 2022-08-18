#ifndef _STARTUNO_
#define _STARTUNO_

#include "State.h"
#include "StartingPlay.h"
#include "EndingGame.h"

class UnoGame;

class StartingUno: public State{
  public:
  	virtual State* handleInput(UnoGame &game, ALLEGRO_EVENT &event);
  	virtual void update(UnoGame &game);
};

#endif