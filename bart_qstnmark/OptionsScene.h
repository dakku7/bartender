#pragma once
#include "Scene.h"

class OptionsScene : public Scene
{
private:
	sf::View options_view;

private:
	//func

public:
	OptionsScene(AssetManager* assmgr, SceneManager* scenemgr);

	void handleEvent(sf::Event& ev, sf::RenderWindow& window) override;
	void update(float dt) override;
	void render(sf::RenderTarget* target) override;

	bool blocksUpdateBelow() override { return true; }
	bool blocksRenderBelow() override { return true; }

	sf::View& getView() override { return options_view; }
};

