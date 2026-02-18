#pragma once
#include "Scene.h"
#include "Player.h"
#include "Dialogue.h"
#include "Customer.h"
#include "Object.h"
#include "SceneManager.h"

enum class GameState {
	Free,
	Dialogue,
	MixGame
};

class GameScene : public Scene
{
private:
	sf::View world_view;
	GameState mode = GameState::Free;

	std::unique_ptr<Player> player;
	// background -> bar -> other entities || decor etc.
	std::vector<std::shared_ptr<Object>> objects;

	//customers
	std::vector<std::shared_ptr<Customer>> customers;
	//+ ui in the end

	//test
	sf::Sprite kubik; //delete
	sf::Texture kubik_tex; //delete
	sf::Sprite grid; //delete

	//MixTooll - надо сделать будет класс в котором будет минисекция 
	//делания коктелей и тому подобного, брать референс с va-11 hall-a игры
private:
	 void handleFreeModeEvent(sf::Event& ev);
	 void startDialogue();

public:
	GameScene(AssetManager* assmgr, SceneManager* scenemgr);
	void init();

	void spawnCustomer();

	void handleEvent(sf::Event& ev, sf::RenderWindow& window) override;
	void handleCustomers();
	void update(float dt) override;
	void render(sf::RenderTarget* target) override;

	bool blocksUpdateBelow() override { return true; }
	bool blocksRenderBelow() override { return true; }
	sf::View& getView() override { return world_view; }
	GameState getGameStateMode();
};