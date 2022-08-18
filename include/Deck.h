#ifndef _DECK_
#define _DECK_

#include "Card.h"
#include <vector>

using namespace std;

class Deck
{
    vector<Card> deck;

  public:

  	Deck();
  	vector<Card> &getCardDeck();
  	void setCardDeck(vector<Card> deck);
    int isDeckEmpty(vector<Card> deck);
    void addInitialCard(int id, int color, int number, int damage, int action); 
    Card& drawCard();
    void shuffle();
};

#endif