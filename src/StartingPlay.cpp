#include <allegro5/allegro.h>
#include "StartingPlay.h"


StartingPlay::StartingPlay()
{
    movement = 0;
}

State* StartingPlay::handleInput(UnoGame &game, ALLEGRO_EVENT &event)
{
    
    if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
    {
        return new EndingGame();
    }

    else if((event.type == ALLEGRO_EVENT_MOUSE_AXES) && (movement == 1 || movement == 2))
    {
        if(movement == 1)
        {
            auxCard = game.getPlayers()[0].getHand()[game.getPlayers()[0].getChosenCard()];
            movement = 2;
        }
        game.draw();    
        al_draw_bitmap(auxCard.getImage(), event.mouse.x, event.mouse.y, 0);
        al_flip_display();
        return NULL;
    }

    else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
    {

        if((insideDeck(event.mouse.x, event.mouse.y))
            && (game.getPlayers()[game.getCurrentPlayer()].getDrawCard() == -1))
        {
            game.update();
            return NULL;
        }
        else if(insideNext(event.mouse.x, event.mouse.y))
        {
            if(game.getPlayers()[game.getCurrentPlayer()].getDrawCard() == 1)
            {
                game.getPlayers()[game.getCurrentPlayer()].setDrawCard(-1);
                return new EndingPlay();
            }
        }

        else 
        {    
            game.getPlayers()[0].setChosenCard(insideCard(event.mouse.x, event.mouse.y, game));
            cout << game.getPlayers()[0].getChosenCard() << endl;
            if (game.getPlayers()[0].getChosenCard() != -1)
                movement = 1;
            return NULL;
        }
    }

    else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
    {           
        if ((movement == 2)
            && (insideTable(event.mouse.x, event.mouse.y)
            && game.compareCards(auxCard, game.getTable().back()))) 
        {
            game.update();
            game.getPlayers()[game.getCurrentPlayer()].setDrawCard(-1);
            return new EndingPlay();
        }

        game.getPlayers()[0].setChosenCard(-1); 
        movement = 0;

        game.draw();
        al_flip_display();
        return NULL;
    }
    return NULL;
}

void StartingPlay::update(UnoGame &game)
{
    if(game.getPlayers()[game.getCurrentPlayer()].getChosenCard() != -1)
    {
        game.getPlayers()[game.getCurrentPlayer()].playCard(game.getTable());
        game.getPlayers()[game.getCurrentPlayer()].setChosenCard(-1); 
        game.getPlayers()[game.getCurrentPlayer()].setPlayerAction(1);
        movement = 0;
    }
    else 
    {
        game.getPlayers()[game.getCurrentPlayer()].setDrawCard(1);
        game.getPlayers()[game.getCurrentPlayer()].drawFromDeck(game.getDeck(), 1);
    }

    game.draw();
    al_flip_display();
}

int StartingPlay::insideDeck(int x, int y)
{
    if(x >= 1250 && x < 1541 && y > 700 && y < 1100)
        return 1;
    return 0;
}

int StartingPlay::insideTable(int x, int y)
{
    if(x >= 853 && x < 1144 && y > 700 && y < 1100)
        return 1;
    return 0;
}

int StartingPlay::insideNext(int x, int y)
{
    if(x >= 1100 && x < 1300 && y > 1120 && y < 1275)
        return 1;
    return 0;
}

int StartingPlay::insideCard(int x, int y, UnoGame &game)
{
     if(x > 550 && x < 1850 && y > 1300 && y < 1700)
     {
        int card = ( ( x + 291/2 - 550 - (1300.0/ (1 + game.getPlayers()[0].getHand().size() ) ) ) / (1300.0 / ( 1 + game.getPlayers()[0].getHand().size() ) ) );
            if(card == game.getPlayers()[0].getHand().size())
                return card -1;
        return card;
     }
     else 
        cout << "out" << endl;
     return -1;
}
