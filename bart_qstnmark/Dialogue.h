#pragma once
#include "Scene.h"

class Dialogue : public Scene
{
private:
	//varibles
	sf::View view;
	sf::Text text;
private:
	//func

public:
	Dialogue(AssetManager* assmgr, SceneManager* scenemgr);

	void handleEvent(sf::Event& ev, sf::RenderWindow& window) override;
	void update(float dt) override;
	void render(sf::RenderTarget* target) override;
	
	void nextLine();

	//чтоб менять сцены и их статусы отрисовки, обязательно для override'a функции, так как каждая сцена отличается
	bool blocksUpdateBelow() { return false; };
	bool blocksRenderBelow() { return false; };

	//не инициализирую потому что оно будет брать все равно view от windowGetDefaultView()
	sf::View& getView() override { return view; };
};

