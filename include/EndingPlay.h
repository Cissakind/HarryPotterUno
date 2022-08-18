#ifndef _ENDPLAY_
#define _ENDPLAY_

#include "State.h"
#include "GameOver.h"
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <iostream>

using namespace std;

class StartingBotPlay;
class EndingPlay: public State{
  private:
  	int changeColor;

  	ALLEGRO_BITMAP *color = NULL;

	ALLEGRO_SAMPLE      *gryffindor;
	ALLEGRO_SAMPLE      *hufflepuff;
	ALLEGRO_SAMPLE      *ravenclaw;
	ALLEGRO_SAMPLE      *slytherin;

  public:
  	EndingPlay();
    ~EndingPlay();
  	virtual State* handleInput(UnoGame &game, ALLEGRO_EVENT &event);
  	virtual void update(UnoGame &game);
  	int insideColor(int x, int y);
};

#endif