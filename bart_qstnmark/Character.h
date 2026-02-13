#pragma once
#include "Entity.h"
#include "Animation.h"

//условный энум для состояний, от который будет зависить исход диалога или требуемыей напиток
enum class Mood {
	Calm,
	Happy,
	Angry,
	Sad
};

class Character : public Entity
{
private:
	std::string name;
	//Animation animation;
	Mood mood = Mood::Calm;
public:
	Character(std::string = "NoName");
	Character(std::string = "NoName", Mood mood_ = Mood::Calm);

	virtual void reactionToInteraction() = 0;
	virtual void update(float dt) = 0;
	virtual void render(sf::RenderTarget* window) = 0;
};

