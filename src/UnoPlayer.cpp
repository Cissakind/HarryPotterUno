#include "UnoPlayer.h"

UnoPlayer::UnoPlayer(int id)
{
	this->id = id;
	chosenCard = -1;
  	drawCard = -1;
  	playerAction = -1;
}
int UnoPlayer::getId()
{
	return id;
}
void UnoPlayer::setId(int id)
{
	this->id = id;
}
vector<Card> &UnoPlayer::getHand()
{
	return hand;
}

void UnoPlayer::playCard(vector<Card> &table)
{
	Card auxCard = hand[chosenCard];
	hand.erase(hand.begin()+chosenCard);
	table.push_back(auxCard);
}

int UnoPlayer::bot_action(Card tableCard, int currentColor)
{

	for(int i = 0; i < hand.size(); i++)
	{
		if(hand[i].getDamage() > 0 && (hand[i].getColor() == currentColor || hand[i].getNumber() == tableCard.getNumber() || hand[i].getColor() == Card::NEUTRO)) 
			return i;
	}

	for(int i = 0; i < hand.size(); i++)
	{
		if(hand[i].getColor() == currentColor) 
			return i;
	}

	for(int i = 0; i < hand.size(); i++)
	{
		if(hand[i].getNumber() == tableCard.getNumber())
			return i;
	}

	for(int i = 0; i < hand.size(); i++)
	{
		if (hand[i].getColor() == Card::NEUTRO)
			return i;
	}

	return -1;
	
}

void UnoPlayer::drawFromDeck(Deck &deck,int n)
{
	for(int i = 0; i < n; i++)
	{
		Card* auxCard = &deck.getCardDeck().back();
		deck.getCardDeck().pop_back();
		hand.push_back(*auxCard);
	}
	return;
}

void UnoPlayer::setChosenCard(int chosenCard)
{
	this->chosenCard = chosenCard;
}
int UnoPlayer::getChosenCard()
{
	return this-> chosenCard;
}

 
void UnoPlayer::setDrawCard(int drawCard)
{
	this->drawCard = drawCard;
}

int UnoPlayer::getDrawCard()
{
	return this-> drawCard;
}   

void UnoPlayer::setPlayerAction(int playerAction)
{
	this->playerAction = playerAction;
}
int UnoPlayer::getPlayerAction()
{
	return this-> playerAction;
}

void UnoPlayer::setPlayerHouse(int house)
{
	this->house = house;
}
int UnoPlayer::getPlayerHouse()
{
	return this->house;
}