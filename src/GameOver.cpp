#include "GameOver.h"
#include "bitmap.h"


GameOver::GameOver()
{
	g = al_load_bitmap("assets/cards/gr.png");
	s = al_load_bitmap("assets/cards/sl.png");
	h = al_load_bitmap("assets/cards/hp.png");
	r = al_load_bitmap("assets/cards/rv.png");
}

GameOver::~GameOver()
{
	al_destroy_bitmap(g);
	al_destroy_bitmap(s);
	al_destroy_bitmap(h);
	al_destroy_bitmap(r);
}

State* GameOver::handleInput(UnoGame &game, ALLEGRO_EVENT &event)
{
	if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	{
		return new EndingGame();
	}

    else
    {
        game.update();
        return NULL;
    }
}

void GameOver::update(UnoGame &game)
{
    al_clear_to_color(al_map_rgb(0, 0, 0));
    if(game.getPlayers()[game.getCurrentPlayer()].getPlayerHouse() == 1)
    {
    	al_draw_bitmap(g, 0, 0, 0);
    }
    else if(game.getPlayers()[game.getCurrentPlayer()].getPlayerHouse() == 2)
    {
    	al_draw_bitmap(s, 0, 0, 0);
    }
    else if(game.getPlayers()[game.getCurrentPlayer()].getPlayerHouse() == 3)
    {
    	al_draw_bitmap(h, 0, 0, 0);
    } 
    else
    {
    	al_draw_bitmap(r, 0, 0, 0);
    }

  	al_flip_display();
}
