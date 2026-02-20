#include "MiniGame.h"
#include "Wodka.h"
#include "Drinks.h"

void MiniGame::addIce() // функція по додаванню льда
{
	if (ice < 4) ice++;
}

int MiniGame::makeDrink(Drinks& first, Drinks& second) // логіка приготування напітків
{
	return first.getID() + second.getID() + this->ice;
}
