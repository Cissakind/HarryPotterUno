#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/bitmap.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/bitmap_io.h>
#include <allegro5/color.h>
#include <allegro5/display.h>

#include <allegro5/events.h>
#include <allegro5/timer.h>
#include <iostream>
#include "BuildUnoGame.h"
#include "UnoState.h"
#include "UnoGame.h"
#include "UnoPlayer.h"
#include <math.h>
#include <ostream>
#include <time.h>

#define NUM_PLAYERS 3
#define DISPLAY_WIDTH 2400
#define DISPLAY_HEIGHT 1799
#define CARD_WIDTH 291
#define CARD_HEIGHT 400
#define FPS 80.0

using namespace std;

bool inicializar(UnoGame &game);
void draw(UnoGame &game);

int insideCard(int x, int y, UnoGame &game);
int insideTable(int x, int y);
int insideDeck(int x, int y, UnoGame game);
int insideNext(int x, int y, UnoGame game);
int insideColor(int x, int y);


ALLEGRO_DISPLAY     *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_BITMAP *fundo = NULL;
ALLEGRO_BITMAP *color = NULL;
ALLEGRO_FONT   *font = NULL;

ALLEGRO_BITMAP *cardsverm[14];
ALLEGRO_BITMAP *cardsverd[14];
ALLEGRO_BITMAP *cardsamar[14];
ALLEGRO_BITMAP *cardsazul[14];
ALLEGRO_BITMAP *cardsneu[2];
ALLEGRO_BITMAP *cardsback = NULL;

ALLEGRO_SAMPLE      *gryffindor=NULL;
ALLEGRO_SAMPLE      *hufflepuff=NULL;
ALLEGRO_SAMPLE      *ravenclaw=NULL;
ALLEGRO_SAMPLE      *slytherin=NULL;

ALLEGRO_TIMER *timer = NULL;


int main()
{

    BuildUnoGame builder;
    UnoGame game = builder.buildUno();
    UnoState state;
    inicializar(game);

    //flags
    Card auxCard;
    int movement = 0;
    int changecolor = 0;
    al_start_timer(timer);

    while (game.getCurrentState() != UnoState::FINISHGAME)
    {
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
        {
            game.setCurrentState(UnoState::FINISHGAME);
            break;
        }

        switch (game.getCurrentState())
        {
            case UnoState::STARTGAME:

                 if (event.type == ALLEGRO_EVENT_TIMER) 
                {
                    game.setCurrentState(state.UnoState::startGame(game));
                    draw(game);
                    al_flip_display();
                    break;
                }

            case UnoState::STARTPLAY:
                if(game.getCurrentPlayer() == 0)
                {
                    if(event.type == ALLEGRO_EVENT_MOUSE_AXES)
                    {
                        if(movement == 1 || movement == 2)
                        {
                            if(movement == 1)
                            {
                                auxCard = game.getPlayers()[0].getHand()[game.getPlayers()[0].getChosenCard()];
                                movement = 2;
                            }    

                            draw(game);
                            al_draw_bitmap(auxCard.getImage(), event.mouse.x, event.mouse.y, 0);
                            al_flip_display();
                        }        
                    }

                    else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
                    {
                        if(insideDeck(event.mouse.x, event.mouse.y, game))
                        {
                            if(game.getPlayers()[game.getCurrentPlayer()].getDrawCard() == -1)
                            {
                                if (game.getPlayers()[game.getCurrentPlayer()].getPlayerDamage() > 0)
                                {
                                    game.getPlayers()[game.getCurrentPlayer()].drawFromDeck(game.getDeck(), game.getPlayers()[game.getCurrentPlayer()].getPlayerDamage());
                                    game.getPlayers()[game.getCurrentPlayer()].setPlayerDamage(0);
                                    draw(game);
                                    al_flip_display();
                                }
                                
                                else
                                {
                                    game.getPlayers()[game.getCurrentPlayer()].setDrawCard(1);
                                    game.getPlayers()[game.getCurrentPlayer()].drawFromDeck(game.getDeck(), 1);
                                    draw(game);
                                    al_flip_display();
                                } 
                            }

                        }
                        
                        else if(insideNext(event.mouse.x, event.mouse.y, game))
                        {
                            if(game.getPlayers()[game.getCurrentPlayer()].getDrawCard() == 1)
                            {
                                game.setCurrentState(UnoState::ENDPLAY);
                                al_rest(1);
                            }
                        }

                        else
                        {
                            game.getPlayers()[0].setChosenCard(insideCard(event.mouse.x, event.mouse.y, game));
                            cout << game.getPlayers()[0].getChosenCard() << endl;
                            if (game.getPlayers()[0].getChosenCard() != -1)
                                movement = 1;
                            break;
                        }    
                    }

                    else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
                    {           
                        if (movement == 2)
                        {
                            if(insideTable(event.mouse.x, event.mouse.y))
                            {
                                game.setCurrentState(state.UnoState::startPlay(game));
                            }
                        }
                        game.getPlayers()[0].setChosenCard(-1); //end
                        movement = 0;
                        draw(game);
                        al_flip_display();
                        al_rest(1);
                    }
            }

            else
            {
                auxCard = game.getTable().back();
                game.getPlayers()[game.getCurrentPlayer()].setChosenCard(game.getPlayers()[game.getCurrentPlayer()].bot_action(auxCard, game.getCurrentColor()));

                if (game.getPlayers()[game.getCurrentPlayer()].getChosenCard() != -1)
                {
                    draw(game);
                    al_flip_display();
                    al_rest(2);

                    game.setCurrentState(state.UnoState::startPlay(game));

                    game.getPlayers()[game.getCurrentPlayer()].setChosenCard(-1);

                    draw(game);
                    al_flip_display();
                    al_rest(2);
                }
                else
                {
                    if(game.getPlayers()[game.getCurrentPlayer()].getDrawCard() == -1)
                    {
                        if(game.getPlayers()[game.getCurrentPlayer()].getPlayerDamage() > 0)
                        {
                            game.getPlayers()[game.getCurrentPlayer()].drawFromDeck(game.getDeck(), game.getPlayers()[game.getCurrentPlayer()].getPlayerDamage());
                            game.getPlayers()[game.getCurrentPlayer()].setPlayerDamage(0);
                            draw(game);
                            al_flip_display();
                            al_rest(2);
                        }
                        else
                        {    
                            game.getPlayers()[game.getCurrentPlayer()].setDrawCard(1);
                            game.getPlayers()[game.getCurrentPlayer()].drawFromDeck(game.getDeck(), 1);
                            draw(game);
                            al_flip_display();
                            al_rest(2);
                        }    
                    }
                    else
                    {
                        game.setCurrentState(UnoState::ENDPLAY);
                        draw(game);
                        al_flip_display();
                        al_rest(2);
                    }
                }    
            }
            break;

            case UnoState::ENDPLAY:

            if(game.getCurrentPlayer() == 0)
            {
                 if (event.type == ALLEGRO_EVENT_TIMER) 
                {    
                     if(game.getPlayers()[game.getCurrentPlayer()].getDrawCard() == -1 && game.getTable().back().getAction() == Card::CHANGE_COLOR)
                     {
                            changecolor = 1;
                            draw(game);
                            al_draw_bitmap(color, 850, 700, 0);
                            al_flip_display();
                     }  
                    else
                    {
                        game.setCurrentState(state.UnoState::endPlay(game));
                        draw(game);
                        al_flip_display();
                        break;
                    }
                }
                else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
                {
                    if(changecolor == 1)
                    {
                        game.setCurrentColor(insideColor(event.mouse.x, event.mouse.y));
                        al_rest(2);
                        game.setCurrentState(state.UnoState::endPlay(game));
                        draw(game);
                        al_flip_display();
                        changecolor = 0;
                    }
                }
            }

            else
            {
                if (event.type == ALLEGRO_EVENT_TIMER) 
                {         
                    if(game.getPlayers()[game.getCurrentPlayer()].getDrawCard() == -1 && game.getTable().back().getAction() == Card::CHANGE_COLOR)
                    {
                        draw(game);
                        al_draw_bitmap(color, 850, 700, 0);
                        al_flip_display();
                        al_rest(2);
                        

                        game.setCurrentColor(insideColor(850 + (rand() % (1550 - 850 + 1) ), 700 + (rand() % (1100 - 700 + 1) ) ) );
                        al_rest(2);

                        game.setCurrentState(state.UnoState::endPlay(game));
                        draw(game);
                        al_flip_display();
                    }
                    
                    else
                    {
                        game.setCurrentState(state.UnoState::endPlay(game));
                        draw(game);
                        al_flip_display();
                        break;
                    }
                }
            }

            default:
                break;
        }
    }

    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);    

    return 0;
}

int insideCard(int x, int y, UnoGame &game)
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

int insideColor(int x, int y)
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

int insideTable(int x, int y)
{
    if(x >= 853 && x < 1144 && y > 700 && y < 1100)
        return 1;
    return 0;
}

int insideDeck(int x, int y, UnoGame game)
{
    if(x >= 1250 && x < 1541 && y > 700 && y < 1100)
        return 1;
    return 0;
}

int insideNext(int x, int y, UnoGame game)
{
    if(x >= 1100 && x < 1300 && y > 1120 && y < 1275)
        return 1;
    return 0;
}

void draw(UnoGame &game)
{
    al_draw_bitmap(fundo, 0, 0, 0);
    al_draw_bitmap(game.getTable().back().getImage(), 853, 700, 0);
    al_draw_bitmap(game.getDeck().getCardDeck().back().getBackImage(), 1250, 700, 0);

    if(game.getPlayers()[0].getDrawCard() == 1)
    {
        al_draw_filled_rectangle(1100, 1200, 1300, 1275, al_map_rgb(228, 207, 156));
        al_draw_rectangle(1100, 1200, 1300, 1275, al_map_rgb(165, 121, 78), 6);
        al_draw_text(font, al_map_rgb(0, 0, 0), 1107, 1203, ALLEGRO_ALIGN_LEFT, "Next Play");
    }

    for(int k = 0; k < game.getPlayers()[0].getHand().size(); k++)
    {
        if(k != game.getPlayers()[0].getChosenCard())
            al_draw_bitmap(game.getPlayers()[0].getHand()[k].getImage(), 550 + (k+1) * 1300.0 / ( 1 + game.getPlayers()[0].getHand().size() ) - 291.0/2 , 1300, 0);
    }

    for(int k = 0; k < game.getPlayers()[1].getHand().size(); k++)
    {
        if(k == game.getPlayers()[1].getChosenCard())
        {
            al_draw_rotated_bitmap(game.getPlayers()[1].getHand()[k].getImage(), 291.0/2, 200, 2100 , 600 + ( k + 1 ) * ( 600.0 / ( 1 + game.getPlayers()[1].getHand().size())), 3*M_PI/2.0, 0);
        }
        else
            al_draw_rotated_bitmap(game.getPlayers()[1].getHand()[k].getBackImage(), 291.0/2, 200, 2100 , 600 + ( k + 1 ) * ( 600.0 / ( 1 + game.getPlayers()[1].getHand().size())), 3*M_PI/2.0, 0);
    }

    for(int k = 0; k < game.getPlayers()[2].getHand().size(); k++)
    {
        if(k == game.getPlayers()[2].getChosenCard())
        {
            al_draw_bitmap(game.getPlayers()[2].getHand()[k].getImage(),  550 + (k+1) * 1300.0 / ( 1 + game.getPlayers()[2].getHand().size() ) - 291.0/2, 90, 90);
        }
        else
            al_draw_bitmap(game.getPlayers()[2].getHand()[k].getBackImage(),  550 + (k+1) * 1300.0 / ( 1 + game.getPlayers()[2].getHand().size() ) - 291.0/2, 90, 90);
    }

    for(int k = 0; k < game.getPlayers()[3].getHand().size(); k++)
    {
        if(k == game.getPlayers()[3].getChosenCard())
        {
             al_draw_rotated_bitmap(game.getPlayers()[3].getHand()[k].getImage(), 291.0/2, 200, 300 , 600 + ( k + 1 ) * ( 600.0 / ( 1 + game.getPlayers()[3].getHand().size())), M_PI/2.0, 0);
        }
        else
            al_draw_rotated_bitmap(game.getPlayers()[3].getHand()[k].getBackImage(), 291.0/2, 200, 300 , 600 + ( k + 1 ) * ( 600.0 / ( 1 + game.getPlayers()[3].getHand().size())), M_PI/2.0, 0);
    }
}

bool inicializar(UnoGame &game)
{
    if (!al_init())
    {
        fprintf(stderr, "Faliled to initialize the Allegro library.\n");
        return false;
    }

    if (!al_init_primitives_addon())
    {
        fprintf(stderr, "Failed to initialize the primitives add-on.\n");
        return false;
    }

    display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);
    if (!display)
    {
        fprintf(stderr, "Failed to create the display.\n");
        return false;
    }

    event_queue = al_create_event_queue();
    if (!event_queue)
    {
        fprintf(stderr, "Failed to create the event queue");
        return false;
    }

    if (!al_install_mouse())
    {
        fprintf(stderr, "Failed to install mouse");
        return false;
    }

    if (!al_init_image_addon())
    {
        fprintf(stderr,"Failed to initialize the image add-on");
        return false;
    }

    if (!al_init_font_addon())
    {
        fprintf(stderr,"Failed to initialize the font add-on");
        return false;
    }

    if (!al_init_ttf_addon())
    {
        fprintf(stderr, "Failed to initialize the tff font add-on");
        return false;
    }

    font = al_load_font("assets/papyrus.ttf", 43, 0);
    if (!font)
    {
        fprintf(stderr, "Falha ao criar fonte");
        return false;
    }


    if (!al_install_audio())
    {
        fprintf(stderr, "Failed to install the audio");
        return false;
    }

    if (!al_init_acodec_addon())
    {
        fprintf(stderr, "Failed to itinialize the acodec add-on");
    }

    timer = al_create_timer(1.0 / FPS);
    if( !timer )
    {
        fprintf(stderr,"Falha ao criar temporizador");
        exit(1);
    }

    al_reserve_samples(4);
    gryffindor = al_load_sample("assets/gryffindor.wav");
    hufflepuff = al_load_sample("assets/hufflepuff.wav");
    ravenclaw = al_load_sample("assets/ravenclaw.wav");
    slytherin = al_load_sample("assets/slytherin.wav");

    fundo = al_load_bitmap("assets/cards/background.png");
    color = al_load_bitmap("assets/cards/color.png");

    cardsverm[0] = al_load_bitmap("assets/cards/vermelho0.png");
    cardsverm[1] = al_load_bitmap("assets/cards/vermelho1.png");
    cardsverm[2] = al_load_bitmap("assets/cards/vermelho2.png");
    cardsverm[3] = al_load_bitmap("assets/cards/vermelho3.png");
    cardsverm[4] = al_load_bitmap("assets/cards/vermelho4.png");
    cardsverm[5] = al_load_bitmap("assets/cards/vermelho5.png"); 
    cardsverm[6] = al_load_bitmap("assets/cards/vermelho6.png");
    cardsverm[7] = al_load_bitmap("assets/cards/vermelho7.png");
    cardsverm[8] = al_load_bitmap("assets/cards/vermelho8.png");
    cardsverm[9] = al_load_bitmap("assets/cards/vermelho9.png");
    cardsverm[10] = al_load_bitmap("assets/cards/vermelhoskip.png");
    cardsverm[11] = al_load_bitmap("assets/cards/vermelhoreverse.png");
    cardsverm[12] = al_load_bitmap("assets/cards/vermelhomais1.png");
    cardsverm[13] = al_load_bitmap("assets/cards/vermelhomais2.png");

    cardsverd[0] = al_load_bitmap("assets/cards/verde0.png");
    cardsverd[1] = al_load_bitmap("assets/cards/verde1.png");
    cardsverd[2] = al_load_bitmap("assets/cards/verde2.png");
    cardsverd[3] = al_load_bitmap("assets/cards/verde3.png");
    cardsverd[4] = al_load_bitmap("assets/cards/verde4.png");
    cardsverd[5] = al_load_bitmap("assets/cards/verde5.png");
    cardsverd[6] = al_load_bitmap("assets/cards/verde6.png");
    cardsverd[7] = al_load_bitmap("assets/cards/verde7.png");
    cardsverd[8] = al_load_bitmap("assets/cards/verde8.png");
    cardsverd[9] = al_load_bitmap("assets/cards/verde9.png");
    cardsverd[10] = al_load_bitmap("assets/cards/verdeskip.png");
    cardsverd[11] = al_load_bitmap("assets/cards/verdereverse.png");
    cardsverd[12] = al_load_bitmap("assets/cards/verdemais1.png");
    cardsverd[13] = al_load_bitmap("assets/cards/verdemais2.png");

    cardsamar[0] = al_load_bitmap("assets/cards/amarelo0.png");
    cardsamar[1] = al_load_bitmap("assets/cards/amarelo1.png");
    cardsamar[2] = al_load_bitmap("assets/cards/amarelo2.png");
    cardsamar[3] = al_load_bitmap("assets/cards/amarelo3.png");
    cardsamar[4] = al_load_bitmap("assets/cards/amarelo4.png");
    cardsamar[5] = al_load_bitmap("assets/cards/amarelo5.png");
    cardsamar[6] = al_load_bitmap("assets/cards/amarelo6.png");
    cardsamar[7] = al_load_bitmap("assets/cards/amarelo7.png");
    cardsamar[8] = al_load_bitmap("assets/cards/amarelo8.png");
    cardsamar[9] = al_load_bitmap("assets/cards/amarelo9.png");
    cardsamar[10] = al_load_bitmap("assets/cards/amareloskip.png");
    cardsamar[11] = al_load_bitmap("assets/cards/amareloreverse.png");
    cardsamar[12] = al_load_bitmap("assets/cards/amarelomais1.png");
    cardsamar[13] = al_load_bitmap("assets/cards/amarelomais2.png");

    cardsazul[0] = al_load_bitmap("assets/cards/azul0.png");
    cardsazul[1] = al_load_bitmap("assets/cards/azul1.png");
    cardsazul[2] = al_load_bitmap("assets/cards/azul2.png");
    cardsazul[3] = al_load_bitmap("assets/cards/azul3.png");
    cardsazul[4] = al_load_bitmap("assets/cards/azul4.png");
    cardsazul[5] = al_load_bitmap("assets/cards/azul5.png");
    cardsazul[6] = al_load_bitmap("assets/cards/azul6.png");
    cardsazul[7] = al_load_bitmap("assets/cards/azul7.png");
    cardsazul[8] = al_load_bitmap("assets/cards/azul8.png");
    cardsazul[9] = al_load_bitmap("assets/cards/azul9.png");
    cardsazul[10] = al_load_bitmap("assets/cards/azulskip.png");
    cardsazul[11] = al_load_bitmap("assets/cards/azulreverse.png");
    cardsazul[12] = al_load_bitmap("assets/cards/azulmais1.png");
    cardsazul[13] = al_load_bitmap("assets/cards/azulmais2.png");

    cardsneu[0] = al_load_bitmap("assets/cards/neutro0.png");
    cardsneu[1] = al_load_bitmap("assets/cards/neutro4.png");

    cardsback = al_load_bitmap("assets/cards/back.png");


    for(int i=0; i<14; i++)
    {
        game.getDeck().getCardDeck()[i].setImage(cardsverm[i]);
        game.getDeck().getCardDeck()[i+14].setImage(cardsverm[i]);
    }

    for(int i=28; i<42; i++)
    {
        game.getDeck().getCardDeck()[i].setImage(cardsverd[i-28]);
        game.getDeck().getCardDeck()[i+14].setImage(cardsverd[i-28]);  
    }

    for(int i=56; i<70; i++)
    {
        game.getDeck().getCardDeck()[i].setImage(cardsamar[i-56]); 
        game.getDeck().getCardDeck()[i+14].setImage(cardsamar[i-56]); 
    }

    for(int i=84; i<98; i++)
    {
        game.getDeck().getCardDeck()[i].setImage(cardsazul[i-84]); 
        game.getDeck().getCardDeck()[i+14].setImage(cardsazul[i-84]); 
    }

    for(int i=112; i<116; i++)
    {
        game.getDeck().getCardDeck()[i].setImage(cardsneu[0]); 
        game.getDeck().getCardDeck()[i+4].setImage(cardsneu[1]); 
    }

    for(int i=0; i<120; i++)
    {
        game.getDeck().getCardDeck()[i].setBackImage(cardsback); 
    }

    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_mouse_event_source());

    return true;
}

    //cout << endl;

    /*for(auto &j : game.getDeck().getCardDeck())
    {
       cout << "DECK:" << endl << j.getId() << endl;
    }

    cout << endl;

    for(auto &j : game.getTable())
    {
       cout << "TABLE:" << endl << j.getColor() << "   " << j.getNumber() << "   " << j.getId() << endl;
    }

    cout << endl;
    cout << "HAND 1";

    for(auto &k : game.getPlayers()[0].getHand())
    {
        cout << endl << k.getId() << endl;
    }

    cout << endl;
    cout << "HAND 2" ;

    for(auto &k : game.getPlayers()[1].getHand())
    {
        cout << endl << k.getId() << endl;
    }

    cout << endl;
    cout << "HAND 3"; 

    for(auto &k : game.getPlayers()[2].getHand())
    {
        cout << endl << k.getId() << endl;
    }

    

    return 0;
}*/

