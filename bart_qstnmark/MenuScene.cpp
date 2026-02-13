#include "MenuScene.h"
#include "Config.h"
#include "SceneManager.h"

MenuScene::MenuScene(AssetManager* assmgr, SceneManager* scenemgr)
	: Scene(assmgr, scenemgr), menu_view(sf::FloatRect(0, 0, 1280, 720))
{
	init();
	initEntities();
}

void MenuScene::init()
{
	ass_mgr->loadTexture(TextureID::Menu_Backgorund);
	background.setTexture(ass_mgr->getTexture(TextureID::Menu_Backgorund));
	background.setPosition(0, 0);

	kubik_tex.loadFromFile("img\\game\\mainchar\\test.png");
	kubik.setTexture(kubik_tex);
}

void MenuScene::initEntities()
{
	ass_mgr->loadTexture(TextureID::Menu_Button);
	font.loadFromFile("font\\menu.otf");

	std::string fill[3] = { "PLAY", "OPTIONS", "QUIT" };

	//buttons & text
	for (size_t i = 0, j =260; i < 3; i++, j += 150)
	{
		std::shared_ptr<Button> button = std::make_shared<Button>(TextureID::Menu_Button, TextureID::Menu_Button_Lightened, ass_mgr);
		button->setPosition(sf::Vector2f(480, j));
		buttons.push_back(button);

		std::shared_ptr<sf::Text> text_ = std::make_shared<sf::Text>();
			text_->setFont(font);
			text_->setCharacterSize(50);
			text_->setString(fill[i]);
		
		sf::FloatRect textRect = text_->getLocalBounds();
			text_->setOrigin(textRect.width / 2, textRect.height / 2);		
			text_->setPosition(sf::Vector2f(button->getPosition().x + button->getSprite().getGlobalBounds().getSize().x / 2, (button->getPosition().y + button->getSprite().getGlobalBounds().getSize().y / 2) - text_->getGlobalBounds().height));
			text.push_back(std::move(text_));
	}
	//play
	buttons[0]->setCallback([this]() {
		scene_mgr->replaceScene(std::make_unique<GameScene>(ass_mgr, scene_mgr));
		});
	//options
	buttons[1]->setCallback([this]() {
		scene_mgr->pushScene(
			std::make_unique<OptionsScene>(ass_mgr, scene_mgr));
		});
	//quit
	buttons[2]->setCallback([this]() {
		this->scene_mgr->getWindow()->close();
		});
	
}

void MenuScene::handleEvent(sf::Event& ev, sf::RenderWindow& window)
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

void MenuScene::update(float dt)
{
	
}

void MenuScene::render(sf::RenderTarget* target)
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
	target->draw(kubik);
}
