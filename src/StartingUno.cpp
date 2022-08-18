#include "StartingUno.h"
#include "allegro5//display.h"

State* StartingUno::handleInput(UnoGame &game, ALLEGRO_EVENT &event)
{
    if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
    {
        return new EndingGame();
    }
    
	game.update();
	return new StartingPlay();
}

void StartingUno::update(UnoGame &game)
{
	game.getDeck().shuffle();
	int nCards = 0;

	while(nCards < 7)
	{
		game.getPlayers()[0].drawFromDeck(game.getDeck(), 1);
		game.getPlayers()[1].drawFromDeck(game.getDeck(), 1);
		game.getPlayers()[2].drawFromDeck(game.getDeck(), 1);
		game.getPlayers()[3].drawFromDeck(game.getDeck(), 1);
		nCards++;
	}

	do{
	game.getTable().push_back(game.getDeck().drawCard());
	game.setCurrentColor(game.getTable().back().getColor());
	game.setDirection(1);
	}while(game.getCurrentColor() == Card::NEUTRO);

	game.draw();
	al_flip_display();
}
 