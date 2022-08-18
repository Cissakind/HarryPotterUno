#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <math.h>
#include <iostream>
#include "UnoGame.h"
#include "State.h"

using namespace std;

#define CARD_WIDTH 291.0
#define CARD_HEIGHT 400

class Deck;

UnoGame::UnoGame() { cout << "UnoGame constructed" << endl; }

UnoGame::~UnoGame()
{
    delete state;
    cout << "free state" << endl;
	cout << "deleted unogame " << endl;
}

void UnoGame::handleInput(ALLEGRO_EVENT &event)
{
	State *newstate = state->handleInput(*this, event);
	if(newstate != NULL)
	{
		delete state;
		state = newstate;
	}
}

void UnoGame::setCurrentState(State* state)
{
	this->state = state;
}

State* &UnoGame::getCurrentState()
{
	return this->state;
}

void UnoGame::update()
{
	state->update(*this);
}

void UnoGame::setFundo(ALLEGRO_BITMAP *fundo)
{
    this->fundo = fundo;
}

ALLEGRO_BITMAP* UnoGame::getFundo()
{
    return this->fundo;
}

void UnoGame::setFont(ALLEGRO_FONT* font)
{
    this->font = font;
}

ALLEGRO_FONT* UnoGame::getFont()
{
    return this->font;
}

Deck &UnoGame::getDeck()
{
	return this->gamedeck;
}

vector<Card> &UnoGame::getTable()
{
	return this->table;
}

vector<UnoPlayer> &UnoGame::getPlayers()
{
	return players;
}

void UnoGame::addPlayer(UnoPlayer player)
{
	players.push_back(player);
}

void UnoGame::setCurrentPlayer(int current, int direction)
{
	current = current + (direction)*1;
	if (current == 4)
		current = 0;
	else if(current == -1)
		current = 3;

	this->currentPlayer = current;
}

int UnoGame::getCurrentPlayer()
{
	return this-> currentPlayer;
}

void UnoGame::setCurrentColor(int currentColor)
{
	this->currentColor = currentColor;
}
int UnoGame::getCurrentColor()
{
	return this -> currentColor;
}

void UnoGame::setDirection(int currentDirection)
{
	this->currentDirection = currentDirection;
}

int UnoGame::getDirection()
{
	return this->currentDirection;
}

int UnoGame::compareCards(Card c1, Card c2)
{
    if(c1.getNumber() == c2.getNumber())
    {
        cout << "valid" << endl;
        return 1;
    }

    else if(c1.getColor() == currentColor || c1.getColor() == Card::NEUTRO)
    {
        cout << "valid" << endl;
        return 1;
    }
    else 
    {
        cout << "not valid" << endl;
        return 0;
    }
}

void UnoGame::draw()
{
    al_draw_bitmap(fundo, 0, 0, 0);
    al_draw_bitmap(table.back().getImage(), 853, 700, 0);
    al_draw_bitmap(gamedeck.getCardDeck().back().getBackImage(), 1250, 700, 0);

    if(players[0].getDrawCard() == 1)
    {
        al_draw_filled_rectangle(1100, 1200, 1300, 1275, al_map_rgb(228, 207, 156));
        al_draw_rectangle(1100, 1200, 1300, 1275, al_map_rgb(165, 121, 78), 6);
        al_draw_text(font, al_map_rgb(0, 0, 100), 1107, 1203, ALLEGRO_ALIGN_LEFT, "Next Play");
    }

    for(int k = 0; k < players[0].getHand().size(); k++)
    {
        if(k != players[0].getChosenCard())
            al_draw_bitmap(players[0].getHand()[k].getImage(), 550 + (k+1) * 1300.0 / ( 1 + players[0].getHand().size() ) - CARD_WIDTH/2 , 1300, 0);
    }

    for(int k = 0; k < players[1].getHand().size(); k++)
    {
        if(k == players[1].getChosenCard())
        {
            al_draw_rotated_bitmap(players[1].getHand()[k].getImage(), CARD_WIDTH/2, 200, 2100 , 600 + ( k + 1 ) * ( 600.0 / ( 1 + players[1].getHand().size())), 3*M_PI/2.0, 0);
        }
        else
            al_draw_rotated_bitmap(players[1].getHand()[k].getBackImage(), CARD_WIDTH/2, 200, 2100 , 600 + ( k + 1 ) * ( 600.0 / ( 1 + players[1].getHand().size())), 3*M_PI/2.0, 0);
    }

    for(int k = 0; k < players[2].getHand().size(); k++)
    {
        if(k == players[2].getChosenCard())
        {
            al_draw_bitmap(players[2].getHand()[k].getImage(),  550 + (k+1) * 1300.0 / ( 1 + players[2].getHand().size() ) - CARD_WIDTH/2, 90, 90);
        }
        else
            al_draw_bitmap(players[2].getHand()[k].getBackImage(),  550 + (k+1) * 1300.0 / ( 1 + players[2].getHand().size() ) - CARD_WIDTH/2, 90, 90);
    }

    for(int k = 0; k < players[3].getHand().size(); k++)
    {
        if(k == players[3].getChosenCard())
        {
             al_draw_rotated_bitmap(players[3].getHand()[k].getImage(), CARD_WIDTH/2, 200, 300 , 600 + ( k + 1 ) * ( 600.0 / ( 1 + players[3].getHand().size())), M_PI/2.0, 0);
        }
        else
            al_draw_rotated_bitmap(players[3].getHand()[k].getBackImage(), CARD_WIDTH/2, 200, 300 , 600 + ( k + 1 ) * ( 600.0 / ( 1 + players[3].getHand().size())), M_PI/2.0, 0);
    }
}