#ifndef _BUILDUNO_
#define _BUILDUNO_

#include "UnoGame.h"
#include "MenuState.h"

class UnoPlayer;

class BuildUnoGame {
	UnoGame game;
	ALLEGRO_BITMAP *fundo = NULL;
	ALLEGRO_FONT   *font = NULL;

  public:
  	BuildUnoGame();
  	~BuildUnoGame();
  	UnoGame &buildUno();
  	UnoGame getGame();

  	ALLEGRO_BITMAP* cardsverm[14];
	ALLEGRO_BITMAP* cardsverd[14];
	ALLEGRO_BITMAP* cardsamar[14];
	ALLEGRO_BITMAP* cardsazul[14];
	ALLEGRO_BITMAP* cardsneu[2];
	ALLEGRO_BITMAP* cardsback = NULL;
};

#endif