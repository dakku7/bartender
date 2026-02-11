#include "GameScene.h"

GameScene::GameScene(AssetManager* assmgr, SceneManager* scenemgr)
	: Scene(assmgr, scenemgr), dialogue_tool(assmgr, scenemgr)
{
	ass_mgr->loadTexture(TextureID::Game_Background);
	background.setTexture(ass_mgr->getTexture(TextureID::Game_Background));
}

void GameScene::handleEvent(sf::Event ev, sf::RenderWindow& window)
{
	switch (mode)
	{
	case GameState::Free:
		handleFreeModeEvent(ev);
		break;
	case GameState::Dialogue:
		dialogue_tool.handleEvent(ev, window);
		break;
	case GameState::MixGame:
		//mix_tool.hanldeEvent(ev);
		break;
	default:
		break;
	}
}

void GameScene::update(float dt)
{
}

void GameScene::render(sf::RenderTarget* target)
{
	target->draw(background);
}

void GameScene::handleFreeModeEvent(sf::Event ev)
{
	switch (ev.type) 
	{
	default:
		break;
	}
}
