#include "Character.h"

Character::Character(std::string name_)
	: name(name_)
{
}

Character::Character(std::string name_, Mood mood_)
	: name(name_), mood(mood_)
{
}
