#include <vector>
#include <iostream>

//#include "State.h"
#include "Card.h"
#include "UnoGame.h"


using namespace std;


UnoState::UnoState()
{
	cout << "UnoState created" << endl;
}


int UnoState::startGame(UnoGame &game)
{

	game.getDeck().shuffle();


	int nCards = 0;
	while(nCards < 7)
	{
		game.getPlayers()[0].drawFromDeck(game.getDeck(), 1);
		game.getPlayers()[1].drawFromDeck(game.getDeck(), 1);
		game.getPlayers()[2].drawFromDeck(game.getDeck(), 1);
		game.getPlayers()[3].drawFromDeck(game.getDeck(), 1);
		nCards++;
	}

	do{
	Card cardaux = game.getDeck().getCardDeck().back();
	game.getDeck().getCardDeck().pop_back();
	game.getTable().push_back(cardaux);
	game.setCurrentColor(game.getTable().back().getColor());
	game.setDirection(1);
	}while(game.getCurrentColor() == Card::NEUTRO);

	return STARTPLAY;
}

int UnoState::startPlay(UnoGame &game)
{
	int compare = 0;
	compare = game.compareCards(game.getPlayers()[game.getCurrentPlayer()].getHand()[game.getPlayers()[game.getCurrentPlayer()].getChosenCard()], game.getTable().back());

	switch (compare)
	{
		case 0:
			cout << "choose a different card - 1 or getfromDeck - 2" << endl;

			return STARTPLAY;

		case 1:

			cout << "yes!!!" << endl;
            game.getPlayers()[game.getCurrentPlayer()].playCard(game.getTable(), game.getPlayers()[game.getCurrentPlayer()].getChosenCard());
            game.getPlayers()[game.getCurrentPlayer()].setDrawCard(-1);

			break;

		case 2:

			game.setRebound(1);
			game.getPlayers()[game.getCurrentPlayer()].playCard(game.getTable(), game.getPlayers()[game.getCurrentPlayer()].getChosenCard());
            game.getPlayers()[game.getCurrentPlayer()].setDrawCard(-1);

	}
	return ENDPLAY;
}


int UnoState::endPlay(UnoGame &game)
{
	if(game.getPlayers()[game.getCurrentPlayer()].getHand().size() == 0)
	{
		cout << "the winner is player " << game.getCurrentPlayer();
		return ENDGAME;
	}

	if(game.getDeck().getCardDeck().size() == 0)
	{
		game.getDeck().setCardDeck(game.getTable());
		game.getDeck().getCardDeck().pop_back();
		game.getDeck().shuffle();
		Card auxCard = game.getTable().back();
		game.getTable().clear();
		game.getTable().push_back(auxCard);
	}

	if(game.getPlayers()[game.getCurrentPlayer()].getDrawCard() == -1)
	{
		if(game.getTable().back().getAction() == Card::CHANGE_COLOR)
		{
			
		}

		else if (game.getTable().back().getAction() == Card::SKIP)
		{
			game.setCurrentColor(game.getTable().back().getColor());
			game.setCurrentPlayer(game.getCurrentPlayer(), game.getDirection());
		}

		else if (game.getTable().back().getAction() == Card::CHANGE_ORDER)
		{
			game.setCurrentColor(game.getTable().back().getColor());
			game.setDirection(-game.getDirection());
		}

		else
		{
			game.setCurrentColor(game.getTable().back().getColor());
		}

	 
		if(game.getRebound() == 1)
		{
			int rebound = game.getPlayers()[game.getCurrentPlayer()].getPlayerDamage() + game.getTable().back().getDamage();
			game.getPlayers()[game.getCurrentPlayer()].setPlayerDamage(0);
			game.setCurrentPlayer(game.getCurrentPlayer(), game.getDirection());
			game.getPlayers()[game.getCurrentPlayer()].setPlayerDamage(rebound);
			game.setRebound(0);
		}

		else
		{
			int damage = game.getTable().back().getDamage();
			cout << endl << game.getCurrentPlayer() << endl;
			game.setCurrentPlayer(game.getCurrentPlayer(), game.getDirection());
			cout << endl << game.getCurrentPlayer() << endl;
			game.getPlayers()[game.getCurrentPlayer()].setPlayerDamage(damage);
		}

		return STARTPLAY;		
	}

	else
	{
		game.getPlayers()[game.getCurrentPlayer()].setDrawCard(-1);
		game.setCurrentPlayer(game.getCurrentPlayer(), game.getDirection());
	}
	cout << "endplay!!!" << endl;
	return STARTPLAY;
}

//rebou