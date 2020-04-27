#include <allegro5/bitmap.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <vector>
#include <cstdlib> 

#include "Deck.h"
using namespace std;

Deck::Deck()
{
	vector<Card> deck;
}

vector<Card> &Deck::getCardDeck()
{
	return this->deck;
}

void Deck::setCardDeck(vector<Card> deck)
{
	this->deck = deck;
}

int Deck::isDeckEmpty(vector<Card> deck)
{
    if(deck.empty())
        return 1;
    return 0;
}

void Deck::addInitialCard(int id, int color, int number, int damage, int action)
{
	deck.push_back( Card(id, color, number, damage, action) );

	return;
}

void Deck::addCard(Card card)
{
	deck.push_back(card);
}

Card Deck::drawCard()
{
	Card auxcard = deck.back();
	deck.pop_back();
	return auxcard;
}

int myrandom (int i)
{
	return rand()%i;
}

void Deck::shuffle()
{
	srand(unsigned (time(0)));
	std::random_shuffle(deck.begin(), deck.end(), myrandom);
	return;
}

