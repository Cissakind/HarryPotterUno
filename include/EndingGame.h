#ifndef _ENDGAME_
#define _ENDGAME_

#include "State.h"
#include <iostream>

using namespace std;

class EndingGame: public State{
  private:
  public:
  	virtual State* handleInput(UnoGame &game, ALLEGRO_EVENT &event);
  	virtual void update(UnoGame &game);
};

#endif