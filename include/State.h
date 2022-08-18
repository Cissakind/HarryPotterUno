#ifndef _UNOSTATE_
#define _UNOSTATE_

#include "UnoGame.h"

class State{

  public:
  	virtual ~State() {};
  	virtual State* handleInput(UnoGame &game, ALLEGRO_EVENT &event) = 0;
  	virtual void update(UnoGame &game) = 0;
};

#endif