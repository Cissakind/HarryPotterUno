#ifndef _UNOGAME_
#define _UNOGAME_

#include <vector>
#include <iostream>

#include "UnoPlayer.h"
#include "State.h"


class UnoPlayer;
class StartingUno;
//class UnoState;

using namespace std;

class UnoGame {

	vector<UnoPlayer> players;
	Deck gamedeck;
  vector <Card> table;
  int currentState;
  int currentPlayer;
  int currentColor;
  int playerAction;
  int currentDirection;
  int rebound;

	//graphic interface


  public:

  	UnoGame();
  	Deck &getDeck();
	  void setDeck(Deck deck);

    vector<Card> &getTable();
    void setTable(vector<Card> table);


  	vector<UnoPlayer> &getPlayers();
  	void setPlayers(vector<UnoPlayer> players);
  	void addPlayer(UnoPlayer player);

    int getCurrentPlayer();
    void setCurrentPlayer(int currentPlayer, int direction);
    
    void setCurrentState(int currentState);
    int &getCurrentState();

    void setCurrentColor(int currentColor);
    int getCurrentColor();

    void setPlayerAction(int playerAction);
    int getPlayerAction();

    void setDirection(int currentDirection);
    int getDirection();

    int compareCards(Card c1, Card c2);
    	//graphic interface*/

    void setRebound(int rebound);
    int getRebound();


};

#endif