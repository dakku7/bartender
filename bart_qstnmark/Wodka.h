#pragma once
#include "Drinks.h"
class Wodka : public Drinks
{
public:
	Wodka();
	int getID() const override;
};

