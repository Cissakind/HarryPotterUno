#include "StartingBotPlay.h"
#include "altime.h"
#include "events.h"
#include <cstddef>

State* StartingBotPlay::handleInput(UnoGame &game, ALLEGRO_EVENT &event)
{
	if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
    {
        return new EndingGame();
    }

	else if(event.type == ALLEGRO_EVENT_TIMER)
	{

		Card auxCard = game.getTable().back();
	    game.getPlayers()[game.getCurrentPlayer()].setChosenCard(game.getPlayers()[game.getCurrentPlayer()].bot_action(auxCard, game.getCurrentColor()));
	    cout << game.getCurrentPlayer() << "  Played " << game.getPlayers()[game.getCurrentPlayer()].getChosenCard() << endl; 
	    if (game.getPlayers()[game.getCurrentPlayer()].getChosenCard() == -1)
	    {
	    	if(game.getPlayers()[game.getCurrentPlayer()].getDrawCard() == -1)
	        {
	        	cout << "pegou do deck" << endl;
	        	al_rest(2);
	            game.update();
	            return NULL;
	        }
	        else
	        {
	        	cout << "passou a vez" << endl;
	        	game.getPlayers()[game.getCurrentPlayer()].setChosenCard(-1);
	        	game.getPlayers()[game.getCurrentPlayer()].setDrawCard(-1);
	        	game.getPlayers()[game.getCurrentPlayer()].setPlayerAction(-1);
	        	return new EndingPlay();
	        }
	    }
	    else
	    {
	    	al_rest(2);
	    	game.update();
		    return new EndingPlay();
	    }
	}
	return NULL;
}

void StartingBotPlay::update(UnoGame &game)
{
	if(game.getPlayers()[game.getCurrentPlayer()].getChosenCard() != -1)
    {
    	game.draw();
    	al_flip_display();
    	al_rest(2);
        game.getPlayers()[game.getCurrentPlayer()].playCard(game.getTable());
        game.getPlayers()[game.getCurrentPlayer()].setChosenCard(-1);
        game.getPlayers()[game.getCurrentPlayer()].setDrawCard(-1); 
        game.getPlayers()[game.getCurrentPlayer()].setPlayerAction(1);
    }
    else 
    {
        game.getPlayers()[game.getCurrentPlayer()].setDrawCard(1);
        game.getPlayers()[game.getCurrentPlayer()].drawFromDeck(game.getDeck(), 1);
    }

    game.draw();
    al_flip_display();
}