/*#include "StartingUno.h"
#include "UnoGame.h"
#include "UnoState.h"

StartingUno::StartingUno()
{

}

UnoState StartingUno::createState(UnoPlayer player)
{
	cout << "hello";
	setCurrentPlayer(player);
	return currentState;
}

int StartingUno::doAction(UnoGame game)
{
	//desenhar a tela
	int nCards = 0;
	while(nCards < 7)
	{
		game.getPlayers()[0].drawFromDeck(game.getDeck(), 1);
		game.getPlayers()[1].drawFromDeck(game.getDeck(), 1);
		game.getPlayers()[2].drawFromDeck(game.getDeck(), 1);
		nCards++;
	}

	Card cardaux = game.getDeck().getCardDeck().back();
	game.getDeck().getCardDeck().pop_back();
	game.getTable().push_back(cardaux);

	cout << "DoAction";

	//game.setCurrentState(StartingPlay.createState(currentPlayer));
	return 0;
}

void StartingUno::setCurrentPlayer(UnoPlayer currentPlayer)
{
	this->currentPlayer = currentPlayer;
}

UnoPlayer StartingUno::getCurrentPlayer()
{
	return this->currentPlayer;
}*/