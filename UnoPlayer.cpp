
#include "UnoPlayer.h"
#include <cstdlib>

using namespace std;

UnoPlayer::UnoPlayer(int id)
{
	this->id = id;
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
void UnoPlayer::setHand(vector<Card> hand)
{
	this->hand = hand;
}

void UnoPlayer::playCard(vector<Card> &table, int chosenCardIndex)
{
	Card auxCard = hand[chosenCardIndex];
	hand.erase(hand.begin()+chosenCardIndex);
	table.push_back(auxCard);
}

int UnoPlayer::bot_action(Card tableCard, int currentColor)
{

	if (playerDamage > 0)
	{
		for(int i = 0; i < hand.size(); i++)
		{
			if(hand[i].getNumber() == tableCard.getNumber())
				return i;
		}
		
		return -1;
	}	

	else
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
}

void UnoPlayer::drawFromDeck(Deck &deck,int n)
{
	for(int i = 0; i < n; i++)
	{
		Card auxCard = deck.getCardDeck().back();
		deck.getCardDeck().pop_back();
		hand.push_back(auxCard);
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


void UnoPlayer::setPlayerDamage(int playerDamage)
{
	this->playerDamage = playerDamage;
}
int UnoPlayer::getPlayerDamage()
{
	return this-> playerDamage;
}   