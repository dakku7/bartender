#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Character.h"
#include "AssetManager.h"

enum class PlayerStatement {
	Idle,
	Dialogue,
	Mixing
};

class Player : public Character
{
private:
	PlayerStatement player_statement = PlayerStatement::Idle;
	//Animation animtnaio


	AssetManager* ass_mgr;
private:


public:
	Player(AssetManager* assmgr);
	void initSprite();

	void reactionToInteraction() override;
	bool interact(sf::Event ev);
	void update(float dt) override;
	void render(sf::RenderTarget* window)override;
	sf::Vector2f getPosition() const override;

	

};

