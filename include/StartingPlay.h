#ifndef _STARTPLAY_
#define _STARTPLAY_

#include "State.h"
#include "EndingPlay.h"
#include "EndingGame.h"


class StartingPlay: public State{
  private:
  	int movement;
  	Card auxCard;
  public:
  	StartingPlay();
  	virtual State* handleInput(UnoGame &game, ALLEGRO_EVENT &event);
  	int insideDeck(int x, int y);
  	int insideTable(int x, int y);
  	int insideNext(int x, int y);
  	int insideCard(int x, int y, UnoGame &game);
  	virtual void update(UnoGame &game);
};

#endif