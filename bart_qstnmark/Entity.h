#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
protected:
	sf::Sprite sprite;

public:	virtual ~Entity() = default;
	virtual void update(float dt) = 0;
	virtual void render(sf::RenderTarget* window) = 0;

	void setPosition(const sf::Vector2f& pos) {
		sprite.setPosition(pos);
	}
	void setTexture(const sf::Texture& tex) { this->sprite.setTexture(tex); }

	virtual sf::Vector2f getPosition() const = 0;
	sf::Sprite& getSprite() { return sprite; }
};

