#include "Card.h"

Card::Card(){return;}

Card::Card(int id, int color, int number, int damage, int action)
{
    this->id = id;
    this->color = color;
    this->damage = damage;
    this->number = number;
    this->action = action;
}

int Card::getColor()
{
return color;
}

int Card::getId()
{
return id;
}

int Card::getNumber()
{
return number;
}

int Card::getDamage()
{
return damage;
}

int Card::getAction()
{
return action;
}

ALLEGRO_BITMAP* Card::getImage()
{
	return this->cardfront;
}

void Card::setImage(ALLEGRO_BITMAP* &image)
{
	this->cardfront = image;
}

ALLEGRO_BITMAP* Card::getBackImage()
{
	return this->cardback;
}

void Card::setBackImage(ALLEGRO_BITMAP* &image)
{
	this->cardback = image;
}