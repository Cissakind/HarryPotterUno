#ifndef _MENUSTATE_
#define _MENUSTATE_
//#include <allegro5/bitmap_io.h>

#include "StartingUno.h"
#include "State.h"
#include "EndingGame.h"
//#include "bitmap.h"

class MenuState: public State{
  private:
  	ALLEGRO_BITMAP* menu;
  public:
  	MenuState();
  	~MenuState();
    virtual State* handleInput(UnoGame &game, ALLEGRO_EVENT &event);
    virtual void update(UnoGame &game);
    int insideColor(int x, int y);
};

#endif
