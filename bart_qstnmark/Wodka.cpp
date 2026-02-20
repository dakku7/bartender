#include "Wodka.h"

Wodka::Wodka() { // конструктор класу Wodka, який встановлює ID напітку
	id = 1;
}
int Wodka::getID() const
{
	return id;  
}