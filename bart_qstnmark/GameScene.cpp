#include "GameScene.h"
#include "Config.h"

#include <iostream>

GameScene::GameScene(AssetManager* assmgr, SceneManager* scenemgr)
	: Scene(assmgr, scenemgr),  world_view(sf::Vector2f(WIDTH / 2, HEIGHT / 2), sf::Vector2f(WIDTH, HEIGHT))
{
	init();
}

void GameScene::init() 
{
	//background
	ass_mgr->loadTexture(TextureID::Game_Background);
	std::shared_ptr<Object> background = std::make_shared<Object>();
	background->setTexture(ass_mgr->getTexture(TextureID::Game_Background));
	objects.push_back(std::move(background));


	//test - temporary
	ass_mgr->loadTexture(TextureID::Game_Grid);
	grid.setTexture(ass_mgr->getTexture(TextureID::Game_Grid));
	kubik_tex.loadFromFile("img\\game\\mainchar\\test.png");
	kubik.setTexture(kubik_tex);
	kubik.setPosition(0, 0);

	//player init
	player = std::make_unique<Player>(ass_mgr);
	player->initSprite();
	player->setPosition( sf::Vector2f(57, INTERACT_ZONE_Y));
	

	//customer
	spawnCustomer();

	//bar init
	ass_mgr->loadTexture(TextureID::Bar);
	std::shared_ptr<Object> bar = std::make_shared<Object>();
	bar->setTexture(ass_mgr->getTexture(TextureID::Bar));
	bar->setPosition(sf::Vector2f(113, player->getPosition().y + player->getSprite().getGlobalBounds().height / 2));
	objects.push_back(std::move(bar));
}

void GameScene::spawnCustomer()
{
	std::shared_ptr<Customer> customer = std::make_shared<Customer>(ass_mgr, "Test", Mood::Calm);
	customer->init();
	customers.push_back(std::move(customer));
}


void GameScene::handleEvent(sf::Event& ev, sf::RenderWindow& window)
{
	switch (mode)
	{
	case GameState::Free:
		handleFreeModeEvent(ev);
		break;
	case GameState::MixGame:
		//mix_tool.hanldeEvent(ev);
		break;
	default:
		break;
	}
	handleCustomers();
}

void GameScene::handleCustomers()
{
	for (auto& it : customers)
	{
		it->reactionToInteraction();
	}
}

void GameScene::update(float dt)
{
	for (auto& it : objects)
	{
		it->update(dt);
	}

	for (auto& it : customers)
	{
		it->update(dt);
	}
	
	player->update(dt);
}

void GameScene::render(sf::RenderTarget* target)
{

	for (auto& it : objects)
	{
		it->render(target);
	}

	player->render(target);

	for (auto& it : customers)
	{
		it->render(target);
	}

	
	target->draw(grid);
	//target->draw(kubik);
	//player empty exception
	
}

GameState GameScene::getGameStateMode()
{
	return mode;
}

void GameScene::handleFreeModeEvent(sf::Event& ev)
{
	if (ev.type == sf::Event::KeyPressed &&
		ev.key.code == sf::Keyboard::E) {
		startDialogue();
	}

}

void GameScene::startDialogue()
{
	auto getDistance = [this](sf::Vector2f a, sf::Vector2f b) {
		sf::Vector2f diff = b - a;
		return std::sqrt(diff.x * diff.x + diff.y * diff.y);
		};

	for (auto& customer : customers)
	{
		float distance = getDistance(
			player->getPosition(),
			customer->getPosition()
		);

		if (distance < 113.f * 3) // радиус взаимодействия
		{
			//mode = GameState::Dialogue;
			customer->setCustomerStatus(CustomerState::InDialogue);
			//std::cout << "\n DIALOUGE STARTED\n";
			this->scene_mgr->pushScene(std::make_unique<Dialogue>(ass_mgr, scene_mgr, customer));
			return;
		}
	}
}
