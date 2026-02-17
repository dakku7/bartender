#pragma once
#include "Scene.h"
#include "Customer.h"
#include "Config.h"
#include "SceneManager.h"

class Dialogue : public Scene
{
private:
	//varibles
	sf::View view;

	//can use rectangle shape for future window scaling scaling
	sf::Sprite panel;
	sf::Text text;
	sf::Text nameText;
	sf::Font font;

	std::vector<std::string> lines;
	int currentLine = 0;
	std::shared_ptr<Customer> current_customer;

private:
	//func

public:
	Dialogue(AssetManager* assmgr, SceneManager* scenemgr, std::shared_ptr<Customer> customer);
	void init();

	void handleEvent(sf::Event& ev, sf::RenderWindow& window) override;
	void update(float dt) override;
	void render(sf::RenderTarget* target) override;
	
	void nextLine();
	void takeTextLines();

	//чтоб менять сцены и их статусы отрисовки, обязательно для override'a функции, так как каждая сцена отличается
	bool blocksUpdateBelow() { return false; };
	bool blocksRenderBelow() { return false; };

	//не инициализирую потому что оно будет брать все равно view от windowGetDefaultView()
	sf::View& getView() override { return view; };
};

