#pragma once
#include "Character.h"
#include "SFML/Graphics.hpp"
#include "AssetManager.h"
#include "Config.h"

enum class CustomerState
{
	Walking,
	Waiting,
	InDialogue,
	WaitingDrink,
	Drinking,
	Leaving
};

class Customer : public Character
{
private:
	AssetManager* ass_mgr;
	CustomerState state = CustomerState::Walking;

	float timer = 0.f;
	float move_speed = 113*3;

	bool interact = false;
	sf::Sprite interactIcon;
public:
	Customer(AssetManager* assmgr, std::string name, Mood mood);
	void init();

	void reactionToInteraction() override;
	void update(float dt) override;
	void render(sf::RenderTarget* window) override;

	//logic
	void moveTowards(float dt);
	void waitForInteraction();
	void drinkOrder();
	void leaving();
	std::vector<std::string> getDialogue();
	void setCustomerStatus(CustomerState status);

	sf::Vector2f getPosition() const override;
	sf::Sprite& getSprite() { return sprite; }
};

