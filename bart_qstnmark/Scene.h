#pragma once
#include "SFML/Graphics.hpp"
#include "Clickable.h"
#include "AssetManager.h"

class SceneManager;

class Scene
{
protected:
	AssetManager* ass_mgr;
	SceneManager* scene_mgr;
public:
	Scene(AssetManager* assets, SceneManager* mgr)
		: ass_mgr(assets), scene_mgr(mgr)
	{
	}

	virtual ~Scene() = default;
	
	virtual void handleEvent(sf::Event& ev, sf::RenderWindow& window) = 0;
	virtual void update(float dt) = 0;
	virtual void render(sf::RenderTarget* target) = 0;
	virtual sf::View& getView() = 0;

	//чтоб менять сцены и их статусы отрисовки, обязательно для override'a функции, так как каждая сцена отличается
	virtual bool blocksUpdateBelow() = 0;
	virtual bool blocksRenderBelow() = 0;
};

