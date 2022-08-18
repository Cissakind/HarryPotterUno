#ifndef _GAMEOVER_
#define _GAMEOVER_
#include <allegro5/bitmap_io.h>

#include "State.h"
#include "EndingGame.h"


class GameOver: public State{
  private:
  	ALLEGRO_BITMAP* g;
	ALLEGRO_BITMAP* s;
	ALLEGRO_BITMAP* h;
	ALLEGRO_BITMAP* r;

  public:
  	GameOver();
  	~GameOver();
    virtual State* handleInput(UnoGame &game, ALLEGRO_EVENT &event);
    virtual void update(UnoGame &game);
};

#endif
