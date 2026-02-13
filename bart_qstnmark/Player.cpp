#include "Player.h"
#include "Customer.h"
#include <iostream>

Player::Player(AssetManager* assmgr)
	: Character("MainCC", Mood::Calm), ass_mgr(assmgr)
{
}

void Player::initSprite() 
{
	ass_mgr->loadTexture(TextureID::Main_Char_Default);
	this->sprite.setTexture(ass_mgr->getTexture(TextureID::Main_Char_Default));	
	this->sprite.setOrigin(sprite.getOrigin().x / 2, sprite.getOrigin().y / 2);
	this->sprite.setPosition(0, 0);
}




void Player::reactionToInteraction()
{
}

bool Player::interact(sf::Event ev)
{
	std::cout << "interact func\n";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
		this->player_statement = PlayerStatement::Dialogue;
		return true;
	}
	return false;
}

void Player::update(float dt)
{
	//animation
}

void Player::render(sf::RenderTarget* window)
{
	window->draw(sprite);
}

sf::Vector2f Player::getPosition() const
{
	return sprite.getPosition();
}
