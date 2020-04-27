#include <vector>
#include <iostream>
#include "Card.h"
#include "UnoGame.h"

using namespace std;

class Deck;

UnoGame::UnoGame() { cout << "UnoGame constructed" << endl; }

void UnoGame::setDeck(Deck gamedeck)
{
	this->gamedeck = gamedeck;
}

Deck &UnoGame::getDeck()
{
	return this->gamedeck;
}

vector<Card> &UnoGame::getTable()
{
	return this->table;
}

void UnoGame::setTable(vector<Card> table)
{
	this->table = table;
}

vector<UnoPlayer> &UnoGame::getPlayers()
{
	return players;
}

void UnoGame::setPlayers(vector<UnoPlayer> players)
{
	this->players = players;
}

void UnoGame::addPlayer(UnoPlayer player)
{
	players.push_back(player);
}

void UnoGame::setCurrentState(int currentState)
{
	this->currentState = currentState;
}

int &UnoGame::getCurrentState()
{
	return this->currentState;
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

void UnoGame::setPlayerAction(int playerAction)
{
	this->playerAction = playerAction;
}

int UnoGame::getPlayerAction()
{
	return this->playerAction;
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
	cout << endl << endl << c1.getNumber() << "    " << c2.getNumber() << endl << endl;

	if(players[currentPlayer].getPlayerDamage() > 0 && c1.getNumber() != c2.getNumber())
	{
		return 0;
	}

	else if(players[currentPlayer].getPlayerDamage() > 0 && c1.getNumber() == c2.getNumber())
	{
		return 2;
	}

	else if(c1.getNumber() == c2.getNumber())
	{
		return 1;
	}

	else if(c1.getColor() == currentColor || c1.getColor() == Card::NEUTRO)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

void UnoGame::setRebound(int rebound)
{
	this->rebound = rebound;
}

int UnoGame::getRebound()
{
	return this->rebound;
}
