#pragma once
#include "Scene.h"
#include "Player.h"
#include "Dialogue.h"

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
	sf::Sprite background;


	Dialogue dialogue_tool;

	//MixTooll - надо сделать будет класс в котором будет минисекция 
	//делания коктелей и тому подобного, брать референс с va-11 hall-a игры
private:
	 void handleFreeModeEvent(sf::Event ev);

public:
	GameScene(AssetManager* assmgr, SceneManager* scenemgr);

	void handleEvent(sf::Event ev, sf::RenderWindow& window) override;
	void update(float dt) override;
	void render(sf::RenderTarget* target) override;

	bool blocksUpdateBelow() override { return true; }
	bool blocksRenderBelow() override { return true; }
	sf::View& getView() override { return world_view; }
};