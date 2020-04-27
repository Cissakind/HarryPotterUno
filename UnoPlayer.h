#ifndef _UNOPLAYER_
#define _UNOPLAYER_

#include "Deck.h"
//#include "UnoGame.h"
#include <vector>
#include <iostream>

using namespace std;

class UnoPlayer{
	int id;
  int chosenCard = -1;
  int drawCard = -1;
  int playerDamage = 0;

	vector<Card> hand;

  public:

    UnoPlayer() = default;
  	UnoPlayer(int id);

  	int getId();
  	void setId(int id);

  	vector<Card> &getHand();
  	void setHand(vector<Card> hand);

  	void drawFromDeck(Deck &deck,int n);
    void playCard(vector<Card> &table, int chosenCardIndex);

    int bot_action(Card tableCard, int currentColor);

    void setChosenCard(int chosenCard);
    int getChosenCard();

    void setDrawCard(int drawCard);
    int getDrawCard();

    void setPlayerDamage(int playerDamage);
    int getPlayerDamage();
};

#endif