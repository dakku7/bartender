#pragma once
#include "Entity.h"
#include "SFML/Graphics.hpp"

class Object : public Entity
{
private:

	//anim object
public:
	Object();

	 void update(float dt) override;
	 void render(sf::RenderTarget* window) override;


	virtual sf::Vector2f getPosition() const override;

};

