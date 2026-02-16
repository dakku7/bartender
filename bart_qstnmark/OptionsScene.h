#pragma once
#include "Scene.h"
#include "Button.h"

class OptionsScene : public Scene
{
private:
	std::vector<std::shared_ptr<Button>> buttons;
	std::vector<std::shared_ptr<sf::Text>> text;
	sf::Font font;

	sf::View options_view;
	sf::Sprite background;
	int res;
	std::shared_ptr<sf::Text> res_show_text = std::make_shared<sf::Text>();
	std::shared_ptr<sf::Text> vol_show_text = std::make_shared<sf::Text>();

private:
	//func
	void scaleResolution(int i);
	void scaleMasterVolume(float i);
	void enterCodes();
	void showVolume(std::shared_ptr<sf::Text> vol_show_text);
	void showResolution(int i, std::shared_ptr<sf::Text> vol_show_text);
public:
	OptionsScene(AssetManager* assmgr, SceneManager* scenemgr);
	void init();
	void initEntities();

	void handleEvent(sf::Event& ev, sf::RenderWindow& window) override;
	void update(float dt) override;
	void render(sf::RenderTarget* target) override;

	bool blocksUpdateBelow() override { return false; }
	bool blocksRenderBelow() override { return true; }

	sf::View& getView() override { return options_view; }
	int resolution_x[8] = { 800, 1024 ,1152 ,1280 ,1366 ,1600 ,1920 ,2560 };
	int resolution_y[8] = { 450 ,576 ,648 ,720 ,768 ,900 ,1080 ,1080 , };
};