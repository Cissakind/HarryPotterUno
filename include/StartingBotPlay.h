#ifndef _STARTBOTPLAY_
#define _STARTBOTPLAY_

#include "StartingPlay.h"
#include "State.h"
#include <iostream>

using namespace std;

class StartingBotPlay: public State{
  private:

  public:
  	virtual State* handleInput(UnoGame &game, ALLEGRO_EVENT &event);
  	virtual void update(UnoGame &game);
};

#endif