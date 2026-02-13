#include "Game.h"
#include <iostream>

Game::Game()
	: window(sf::VideoMode(WIDTH, HEIGHT), "Bartender", sf::Style::Close),
	scene_manager(&asset_manager, &window)
{
	scene_manager.pushScene(std::make_unique<MenuScene>(&asset_manager, &scene_manager));
	std::cout << window.getView().getSize().x << " "
		<< window.getView().getSize().y << std::endl;
}

void Game::run()
{
	sf::Clock clock;
	while (window.isOpen())
	{
		float dt = clock.restart().asSeconds();
		processEvents();
		update(dt);
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
		scene_manager.handleEvents(ev, window);
	}
}

void Game::update(float dt)
{
	scene_manager.update(dt);
}

void Game::render()
{
	window.clear();
	scene_manager.render(&window);
	window.display();
}


