#ifndef _CARD_
#define _CARD_

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/bitmap.h>
#include <allegro5/display.h>

class Card 
{
    int id;
    int color;  
    int damage;
    int number;
    int action;
    ALLEGRO_BITMAP *cardfront;
    ALLEGRO_BITMAP *cardback;

  public:
    Card();
    Card(int id, int color, int number, int damage, int action); 
    int getColor();
    int getId();
    int getNumber();
    int getDamage();
    int getAction();
    ALLEGRO_BITMAP* getImage();
    void setImage( ALLEGRO_BITMAP* &image);
    ALLEGRO_BITMAP* getBackImage();
    void setBackImage( ALLEGRO_BITMAP* &image);


    void setId(int id);

    enum {
        VERMELHO,
        VERDE,
        AMARELO,
        AZUL,
        NEUTRO
    };

    enum {
        NOTHING,
        SKIP,
        CHANGE_COLOR,
        CHANGE_ORDER
    };
};


#endif