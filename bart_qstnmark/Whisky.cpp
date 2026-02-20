#include "Whisky.h"

Whisky::Whisky() { // конструктор класу Whisky, який встановлює ID напітку
	id = 5;
}
int Whisky::getID() const
{
	return id;
}