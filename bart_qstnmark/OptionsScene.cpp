#include "OptionsScene.h"
#include "Config.h"
#include "MenuScene.h"
#include "SceneManager.h"

OptionsScene::OptionsScene(AssetManager* assmgr, SceneManager* scenemgr)
	: Scene(assmgr, scenemgr), options_view(sf::FloatRect(sf::Vector2f(0, 0), sf::Vector2f(WIDTH, HEIGHT)))
{
	res = 4;
	init();
	initEntities();
}

void OptionsScene::init()
{
	ass_mgr->loadTexture(TextureID::Menu_Backgorund);
	background.setTexture(ass_mgr->getTexture(TextureID::Menu_Backgorund));
	background.setPosition(0, 0);
}

void OptionsScene::initEntities() {
	ass_mgr->loadTexture(TextureID::Menu_Button);
	font.loadFromFile("font\\menu.otf");

	//buttons & text
	for (int i = 0, j = 100, k = 75; i < 5; i++,k += 350) {
		if (i == 2) {
			j += 200;
			k = 75;
		}
		else if (i == 4) {
			j += 200;
			k = 75;

		}
			std::shared_ptr<Button> button = std::make_shared<Button>(TextureID::Menu_Button, TextureID::Menu_Button_Lightened, ass_mgr);
			button->setPosition(sf::Vector2f(k, j));
			buttons.push_back(button);

			button->getSprite().setScale(0.5,0.5);
			if (i == 4) {
				std::shared_ptr<sf::Text> text_ = std::make_shared<sf::Text>();
				text_->setFont(font);
				text_->setCharacterSize(40);
				text_->setString("QUIT");

				sf::FloatRect textRect = text_->getLocalBounds();
				text_->setOrigin(textRect.width / 2, textRect.height / 4);
				text_->setPosition(sf::Vector2f(button->getPosition().x + button->getSprite().getGlobalBounds().getSize().x / 2, (button->getPosition().y + button->getSprite().getGlobalBounds().getSize().y / 1.8) - text_->getGlobalBounds().height));
				text.push_back(std::move(text_));
			}
	}
	//resolution
	buttons[0]->setCallback([this]() {
		scaleResolution(-1);
		});
	buttons[1]->setCallback([this]() {
		scaleResolution(1);
		});
	//volume
	buttons[2]->setCallback([this]() {
		});
	buttons[3]->setCallback([this]() {
		});
	//quit
	buttons[4]->setCallback([this]() {
		scene_mgr->replaceScene(std::make_unique<MenuScene>(ass_mgr, scene_mgr));
		});
};

void OptionsScene::handleEvent(sf::Event ev, sf::RenderWindow& window)
{
	sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

	switch (ev.type)
	{
	case sf::Event::MouseButtonPressed:
		if (ev.mouseButton.button == sf::Mouse::Left) {
			for (auto& it : buttons)
			{
				if (it->contains(mousePos))
				{
					it->clicked();
				}
			}
		}
		break;
	default:
		break;
	}

	for (auto& it : buttons)
	{
		if (it->contains(mousePos)) {
			it->setHovered(true);
		}
		else {
			it->setHovered(false);
		}
	}
}

void OptionsScene::update(float dt)
{
}

void OptionsScene::render(sf::RenderTarget* target)
{
	target->draw(background);
		for (auto& it : buttons)
	{
		it->render(target);
	}
	
	for (auto& it : text)
	{
		target->draw(*it.get());
	}
}

void OptionsScene::scaleResolution(int i) {
	int resolution_x[8] = { 800, 1024 ,1152 ,1280 ,1366 ,1600 ,1920 ,2560 };
	int resolution_y[8] = { 450 ,576 ,648 ,720 ,768 ,900 ,1080 ,1080 ,};
	res += i;
	if (res > 7) res = 0;
	else if (res < 0) res = 7;
	scene_mgr->setWindowSize(resolution_x[res], resolution_y[res]);
};
void OptionsScene::scaleVolume(int i) {};
void OptionsScene::enterCodes() {};