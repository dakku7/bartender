#pragma once
#include "Scene.h"
#include "Button.h"

class MenuScene : public Scene
{
private:
	//std::vector<std::shared_ptr<Entity>> entities;
	std::vector<std::shared_ptr<Button>> buttons;
	std::vector<std::shared_ptr<sf::Text>> text;
	sf::Text texttemp;
	sf::Font font;

	sf::View menu_view;
	sf::Sprite background;


public:
	MenuScene(AssetManager* assmgr, SceneManager* scenemgr);
	void init();
	void initEntities();

	void handleEvent(sf::Event ev, sf::RenderWindow& window) override;
	void update(float dt) override;
	void render(sf::RenderTarget* target) override;

	bool blocksUpdateBelow() override { return true; }
	bool blocksRenderBelow() override { return true; }

	sf::View& getView() override { return menu_view; }
};

