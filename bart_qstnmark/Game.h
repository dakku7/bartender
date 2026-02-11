#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Config.h"
#include "AssetManager.h"
#include "SceneManager.h"

class Game {
private:
	sf::RenderWindow window;
	AssetManager asset_manager;
	SceneManager scene_manager;

private:
	void processEvents();
	void update();
	void render();

public:
	Game();
	void run();
};