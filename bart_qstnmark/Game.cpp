#include "Game.h"

Game::Game()
	: window(sf::VideoMode(WIDTH, HEIGHT), "Bartender", sf::Style::Default),
	scene_manager(&asset_manager, &window)
{
	scene_manager.pushScene(std::make_unique<MenuScene>(&asset_manager, &scene_manager));
}

void Game::run()
{
	while (window.isOpen())
	{
		processEvents();
		update();
		render();
	}
}

void Game::processEvents()
{
	sf::Event ev;
	while (window.pollEvent(ev))
	{
		switch (ev.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		default:
			break;
		}
	}
	scene_manager.handleEvents(ev, window);
}

void Game::update()
{
	scene_manager.update(2);
}

void Game::render()
{
	window.clear();
	scene_manager.render(&window);
	window.display();
}


