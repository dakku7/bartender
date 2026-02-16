#include "OptionsScene.h"
#include "Config.h"
#include "MenuScene.h"
#include "SceneManager.h"
#include "VolumeManager.h"
#include <string>





OptionsScene::OptionsScene(AssetManager* assmgr, SceneManager* scenemgr)
	: Scene(assmgr, scenemgr), options_view(sf::FloatRect(sf::Vector2f(0, 0), sf::Vector2f(WIDTH, HEIGHT)))
{
	res = 4;
	init();
	initEntities();
	showVolume(this->vol_show_text);
	showResolution(res, this->res_show_text);
}

void OptionsScene::init()
{
	ass_mgr->loadTexture(TextureID::Menu_Backgorund);
	background.setTexture(ass_mgr->getTexture(TextureID::Menu_Backgorund));
	background.setPosition(0, 0);
}

void OptionsScene::initEntities() {
	ass_mgr->loadTexture(TextureID::Menu_Button);
	if (!font.loadFromFile("font\\menu.otf")) {
		throw std::runtime_error("Font not found!");
	}
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
	std::shared_ptr<sf::Text> res_text = std::make_shared<sf::Text>();
	res_text->setFont(font);
	res_text->setCharacterSize(40);
	res_text->setString("Resolution");
	sf::FloatRect res_textRect = res_text->getLocalBounds();
	res_text->setOrigin(res_textRect.width / 2, res_textRect.height / 2);
	res_text->setPosition(sf::Vector2f(330, 120));
	text.push_back(std::move(res_text));


	std::shared_ptr<sf::Text> vol_text = std::make_shared<sf::Text>();
	vol_text->setFont(font);
	vol_text->setCharacterSize(40);
	vol_text->setString("Volume");
	sf::FloatRect vol_textRect = vol_text->getLocalBounds();
	vol_text->setOrigin(vol_textRect.width / 2, vol_textRect.height / 2);
	vol_text->setPosition(sf::Vector2f(330, 320));
	text.push_back(std::move(vol_text));


	res_show_text = std::make_shared<sf::Text>();
	res_show_text->setFont(font);
	res_show_text->setCharacterSize(40);
	res_show_text->setFillColor(sf::Color::Red);
	res_show_text->setPosition(900, 120);
	text.push_back(res_show_text);

	vol_show_text = std::make_shared<sf::Text>();
	vol_show_text->setFont(font);
	vol_show_text->setCharacterSize(40);
	vol_show_text->setFillColor(sf::Color::Red);
	vol_show_text->setPosition(900, 320 );
	text.push_back(vol_show_text);
	//resolution
	buttons[0]->setCallback([this]() {
		scaleResolution(-1);
		showResolution(res, this->res_show_text);

		});
	buttons[1]->setCallback([this]() {
		scaleResolution(1);
		showResolution(res, this->res_show_text);

		});
	//volume
	buttons[2]->setCallback([this]() {
		scaleMasterVolume(-5);
		showVolume(this->vol_show_text);
		});
	buttons[3]->setCallback([this]() {
		scaleMasterVolume(5);
		showVolume(this->vol_show_text);
		});
	//quit
	buttons[4]->setCallback([this]() {
		scene_mgr->replaceScene(std::make_unique<MenuScene>(ass_mgr, scene_mgr));
		});
};

void OptionsScene::handleEvent(sf::Event& ev, sf::RenderWindow& window)
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

	res += i;
	if (res > 7) res = 0;
	else if (res < 0) res = 7;
	scene_mgr->setWindowSize(resolution_x[res], resolution_y[res]);
};
void OptionsScene::scaleMasterVolume(float i) {
	if (VolumeManager::getMasterVolume() + i > 100 || VolumeManager::getMasterVolume() + i < 0) {};
	VolumeManager::setMasterVolume(VolumeManager::getMasterVolume() + i);
};
void OptionsScene::enterCodes() {}
void OptionsScene::showVolume(std::shared_ptr<sf::Text> vol_show_text)
{
	vol_show_text->setString(std::to_string(VolumeManager::getMasterVolume()));
}
void OptionsScene::showResolution(int i, std::shared_ptr<sf::Text> res_show_text)
{
	res_show_text->setString(std::to_string(resolution_x[i]) + "x" + std::to_string(resolution_y[i]));
}
;