#pragma once
#include "Drinks.h"
class Whisky :public Drinks
{
public:
	Whisky();
	int getID() const override;
};

