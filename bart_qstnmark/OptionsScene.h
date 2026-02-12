#pragma once
#include "Scene.h"
#include "Button.h"

class OptionsScene : public Scene
{
private:
	std::vector<std::shared_ptr<Button>> buttons;
	std::vector<std::shared_ptr<sf::Text>> text;
	sf::Font font;

	sf::View options_view;
	sf::Sprite background;
	int res;

private:
	//func
	void scaleResolution(int i);
	void scaleVolume(int i);
	void enterCodes();
public:
	OptionsScene(AssetManager* assmgr, SceneManager* scenemgr);
	void init();
	void initEntities();

	void handleEvent(sf::Event ev, sf::RenderWindow& window) override;
	void update(float dt) override;
	void render(sf::RenderTarget* target) override;

	bool blocksUpdateBelow() override { return false; }
	bool blocksRenderBelow() override { return true; }

	sf::View& getView() override { return options_view; }
};

