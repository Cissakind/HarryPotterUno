#ifndef _UNOPLAYER_
#define _UNOPLAYER_

#include "Deck.h"

class UnoPlayer{
	int id;
  int chosenCard;
  int drawCard;
  int playerAction;
  int house;

	vector<Card> hand;

  public:

    UnoPlayer() = default;
  	UnoPlayer(int id);

  	int getId();
  	void setId(int id);

  	vector<Card> &getHand();

  	void drawFromDeck(Deck &deck,int n);
    void playCard(vector<Card> &table);

    int bot_action(Card tableCard, int currentColor);

    void setChosenCard(int chosenCard);
    int getChosenCard();

    void setDrawCard(int drawCard);
    int getDrawCard();

    void setPlayerAction(int playerAction);
    int getPlayerAction();

    void setPlayerHouse(int house);
    int getPlayerHouse();
};

#endif