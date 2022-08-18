#ifndef _UNOGAME_
#define _UNOGAME_

#include <allegro5/events.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "UnoPlayer.h"
#include "bitmap.h"

class StartingUno;
class State;

using namespace std;

class UnoGame 
{
  private:
    State* state;
    ALLEGRO_BITMAP *fundo;
    ALLEGRO_FONT   *font;

    vector<UnoPlayer> players;
    Deck gamedeck;
    vector <Card> table;

    int currentPlayer;
    int currentColor;
    int currentDirection;
    int playerAction;

  public:
    UnoGame();
    ~UnoGame();
    virtual void handleInput(ALLEGRO_EVENT &event);
    virtual void update();

    void setCurrentState(State* state);
    State* &getCurrentState();

    void setFundo(ALLEGRO_BITMAP *fundo);
    ALLEGRO_BITMAP* getFundo();

    void setFont(ALLEGRO_FONT* font);
    ALLEGRO_FONT* getFont();

    Deck &getDeck();
    vector<Card> &getTable();

    vector<UnoPlayer> &getPlayers();
    void addPlayer(UnoPlayer player);

    int getCurrentPlayer();
    void setCurrentPlayer(int currentPlayer, int direction);
    
    void setCurrentColor(int currentColor);
    int getCurrentColor();

    void setDirection(int currentDirection);
    int getDirection();

    int compareCards(Card c1, Card c2);
    void draw();
};

#endif