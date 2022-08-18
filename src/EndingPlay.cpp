#include "EndingPlay.h"
#include "StartingPlay.h"
#include "StartingBotPlay.h"


EndingPlay::EndingPlay()
{
    changeColor = -1;

    al_reserve_samples(4);
    gryffindor = al_load_sample("assets/gryffindor.wav");
    hufflepuff = al_load_sample("assets/hufflepuff.wav");
    ravenclaw = al_load_sample("assets/ravenclaw.wav");
    slytherin = al_load_sample("assets/slytherin.wav");
    color = al_load_bitmap("assets/cards/color.png");
}

EndingPlay::~EndingPlay()
{
    al_destroy_sample(gryffindor);
    al_destroy_sample(slytherin);
    al_destroy_sample(hufflepuff);
    al_destroy_sample(ravenclaw);
    al_destroy_bitmap(color);
}

State* EndingPlay::handleInput(UnoGame &game, ALLEGRO_EVENT &event)
{
    if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
    {
        return new EndingPlay();
    }

    if(game.getPlayers()[game.getCurrentPlayer()].getHand().empty())
    {
        return new GameOver();
    }

    if(changeColor == 1)
    {
        int newColor = -1;
        if(game.getCurrentPlayer() == 0 && event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            newColor = insideColor(event.mouse.x, event.mouse.y);
        }
        else if(game.getCurrentPlayer() != 0)
        {
            newColor = insideColor(850 + (rand() % (1550 - 850 + 1) ), 700 + (rand() % (1100 - 700 + 1) ) );
            al_rest(2);
        }

        if(newColor != -1 || game.getCurrentPlayer() != 0)
        {
            game.setCurrentColor(newColor);
            game.setCurrentPlayer(game.getCurrentPlayer(), game.getDirection());

            if(game.getTable().back().getDamage() > 0)
            {
                game.getPlayers()[game.getCurrentPlayer()].drawFromDeck(game.getDeck(),game.getTable().back().getDamage());
                game.draw();
                al_flip_display();
                game.setCurrentPlayer(game.getCurrentPlayer(), game.getDirection());
            }

            changeColor = -1;
            if(game.getCurrentPlayer() == 0)
            {
                game.draw();
                al_flip_display();
                return new StartingPlay();
            }
            else
                return new StartingBotPlay();
        }
    }

    else if(changeColor != 1)
    {
        game.update();

        if (changeColor == 1)
        {
            game.draw();
            al_draw_bitmap(color, 850, 700, 0);
            al_flip_display();
            al_rest(1);
            return NULL;
        }
        else
        {
            game.draw();
            al_flip_display();
            game.setCurrentPlayer(game.getCurrentPlayer(), game.getDirection());
            if(game.getCurrentPlayer() == 0)
                return new StartingPlay();
            else
                return new StartingBotPlay();
        }
    }
    return NULL;
}

void EndingPlay::update(UnoGame &game)
{
    if(game.getDeck().getCardDeck().size() == 0)
    {
        game.getDeck().setCardDeck(game.getTable());
        game.getDeck().getCardDeck().pop_back();
        game.getDeck().shuffle();
        Card *auxCard = &game.getTable().back();
        game.getTable().clear();
        game.getTable().push_back(*auxCard);
    }

    if(game.getPlayers()[game.getCurrentPlayer()].getPlayerAction() == 1)
    {
        if(game.getTable().back().getAction() == Card::CHANGE_COLOR)
        {   
            changeColor = 1;
        }

        else if (game.getTable().back().getAction() == Card::SKIP)
        {
            game.setCurrentColor(game.getTable().back().getColor());
            game.setCurrentPlayer(game.getCurrentPlayer(), game.getDirection());
        }

        else if (game.getTable().back().getAction() == Card::CHANGE_ORDER)
        {
            game.setCurrentColor(game.getTable().back().getColor());
            game.setDirection(-game.getDirection());
        }

        else if(game.getTable().back().getDamage() > 0)
        {
            game.setCurrentPlayer(game.getCurrentPlayer(), game.getDirection());
            game.getPlayers()[game.getCurrentPlayer()].drawFromDeck(game.getDeck(),game.getTable().back().getDamage());
            game.setCurrentColor(game.getTable().back().getColor());
            game.draw();
            al_flip_display();
        }

        else
        {
            game.setCurrentColor(game.getTable().back().getColor());
        }
        game.getPlayers()[game.getCurrentPlayer()].setPlayerAction(-1);
    }

    else
    {
        game.getPlayers()[game.getCurrentPlayer()].setDrawCard(-1);
    }
}

int EndingPlay::insideColor(int x, int y)
{

    if(x > 850 && x < 1200  && y > 700 && y < 900)
    {
        al_play_sample(gryffindor, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
        return Card::VERMELHO;
    }
    else if(x > 1200 && x < 1550   && y > 700 && y < 900)
    {
        al_play_sample(slytherin, 1.3, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
        return Card::VERDE;
    }
    else if (x > 850 && x < 1200 && y > 900 && y < 1100)
    {
        al_play_sample(hufflepuff, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
        return Card::AMARELO;
    }
    else if(x > 1200 && x <  1550  && y > 900 && y < 1100)
    {
        al_play_sample(ravenclaw, 1.3, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
        return Card::AZUL;
    }

    return -1;
}

 