#include "OptionsScene.h"

OptionsScene::OptionsScene(AssetManager* assmgr, SceneManager* scenemgr)
	: Scene(assmgr, scenemgr)
{
}

void OptionsScene::handleEvent(sf::Event ev, sf::RenderWindow& window)
{
	switch (ev.type)
	{
	default:
		break;
	}
}

void OptionsScene::update(float dt)
{
}

void OptionsScene::render(sf::RenderTarget* target)
{
}
