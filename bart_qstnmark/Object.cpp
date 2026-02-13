#include "Object.h"

Object::Object()
{
}

void Object::update(float dt)
{
}

void Object::render(sf::RenderTarget* window)
{
	window->draw(sprite);
}

sf::Vector2f Object::getPosition() const
{
	return sprite.getPosition();
}
