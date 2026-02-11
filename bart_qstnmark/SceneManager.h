#pragma once
#include "Scene.h"
#include "OptionsScene.h"
#include "GameScene.h"
#include "MenuScene.h"

enum class ActionType {
	None,
	Push,
	Pop,
	Replace
};

//для смены слоев и сцен, и собсна каллбека от клика, пример, кликаю по кнопке и даю статус кадру, что надо менять сцену
//если например будет два действия клик в плей и там открывается сразу диалог, то вектор просто создаст и то, и то,  но нужно тестить 
struct PendingAction {
	ActionType type = ActionType::None;
	std::unique_ptr<Scene> scene;
};

class SceneManager
{
private:
	std::vector<std::unique_ptr<Scene>> scenes;
	AssetManager* ass_mgr;
	std::vector<PendingAction> pendingActions;

public:
	SceneManager(AssetManager* assets);

	void pushScene(std::unique_ptr<Scene> scene);
	void popScene();
	void replaceScene(std::unique_ptr<Scene> scene);
	void applyPendingChanges();

	void handleEvents(sf::Event& ev, sf::RenderWindow& window);
	void update(float dt);
	void render(sf::RenderTarget* target);
	Scene* getCurrentScene();
};

