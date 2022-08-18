#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <iostream>
#include "BuildUnoGame.h"

using namespace std;

#define DISPLAY_WIDTH 2400
#define DISPLAY_HEIGHT 1799
#define FPS 40.0

ALLEGRO_DISPLAY     *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;

bool inicializar();
void free();

int main()
{
    inicializar();
    BuildUnoGame builder;
    UnoGame &game = builder.buildUno();
    al_start_timer(timer);

    EndingGame *s;
    
    while(!(s = dynamic_cast< EndingGame*>(game.getCurrentState()))) 
    {
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);
        game.handleInput(event);
    }
    
    free();
    return 0;
}

void free()
{
    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
}

bool inicializar()
{
    al_init();
    al_init_primitives_addon();
    al_install_mouse();
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_install_audio();
    al_init_acodec_addon();

    display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);
    event_queue = al_create_event_queue();
    timer = al_create_timer(1.0 / FPS);

    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_mouse_event_source());

    return true;
}
