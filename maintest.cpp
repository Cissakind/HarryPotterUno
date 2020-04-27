#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
 
#include "BuildUnoGame.h"
#include "UnoState.h"
#include "UnoGame.h"
#include "UnoPlayer.h"

int main()
{

    BuildUnoGame builder;
    UnoGame game = builder.buildUno();
    UnoState state;

    while (game.getCurrentState() != UnoState::FINISHGAME)
    {

        switch (game.getCurrentState())
        {
            case UnoState::STARTGAME:
                game.setCurrentState(state.UnoState::startGame(game));
                break;
            case UnoState::STARTPLAY:

                game.setCurrentState(state.UnoState::startPlay(game));
                break;
            case UnoState::ENDPLAY:
                game.setCurrentState(state.UnoState::endPlay(game));
            default:
                break;
        }
    }

    cout << endl;


    while (1)
	{
		ALLEGRO_EVENT event;
		al_wait_for_event(event_queue, &event);

		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
		{
			break;
		}

		else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		{
			switch (game.getCurrentState())
	        {
	            case UnoState::STARTGAME:
	                game.setCurrentState(state.UnoState::startGame(game));
	                break;
	            case UnoState::STARTPLAY:

	                game.setCurrentState(state.UnoState::startPlay(game));
	                break;
	            case UnoState::ENDPLAY:
	                game.setCurrentState(state.UnoState::endPlay(game));
	            default:
	                break;
	        }
		}
	}
		
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);	

	return 0;
}

}