#include "MenuState.h"
#include "bitmap.h"

#define DISPLAY_WIDTH 2400
#define DISPLAY_HEIGHT 1799

MenuState::MenuState()
{
	menu = al_load_bitmap("assets/cards/hg.png");
}

MenuState::~MenuState()
{
	al_destroy_bitmap(menu);
}

State* MenuState::handleInput(UnoGame &game, ALLEGRO_EVENT &event)
{
	game.update();
	if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	{
		return new EndingGame();
	}
	else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
	{
		game.getPlayers()[0].setPlayerHouse(insideColor(event.mouse.x, event.mouse.y));
		int j = game.getPlayers()[0].getPlayerHouse();
		cout << "house  " << j << endl;

		for(int i = 1; i < 4; i++)
		{
			j = j + 1;
			if(j == 5)
				j = 1;
			game.getPlayers()[i].setPlayerHouse(j); 
			cout << "house  " << j << endl;
		}

		return new StartingUno();
	}
	return NULL;
}

void MenuState::update(UnoGame &game)
{
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(menu, 0, 0, 0);
  	al_flip_display();
}

int MenuState::insideColor(int x, int y)
{
	if(x < DISPLAY_WIDTH/2.0 && y < DISPLAY_HEIGHT/2.0)
		return 1;
	else if(x > DISPLAY_WIDTH/2.0 && y < DISPLAY_HEIGHT/2.0)
		return 2;
	else if(x < DISPLAY_WIDTH/2.0 && y > DISPLAY_HEIGHT/2.0)
		return 3;
	else 
		return 4;	 
}