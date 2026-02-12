#include "SceneManager.h"

SceneManager::SceneManager(AssetManager* assets, sf::RenderWindow* window)
	: ass_mgr(assets), window(window)
{
}


void SceneManager::pushScene(std::unique_ptr<Scene> scene)
{
	pendingActions.push_back({ ActionType::Push, std::move(scene) });
}

void SceneManager::popScene()
{
	pendingActions.push_back({ ActionType::Pop, nullptr });
}

void SceneManager::replaceScene(std::unique_ptr<Scene> scene)
{
	pendingActions.push_back({ ActionType::Replace, std::move(scene) });
}

void SceneManager::applyPendingChanges()
{
	for (auto& action : pendingActions) {
		switch (action.type) {
		
			case ActionType::Push:   
				scenes.push_back(std::move(action.scene)); 
				break;

			case ActionType::Pop:    
				if (!scenes.empty())
				{
					scenes.pop_back();
				}
				break;

			case ActionType::Replace:
				if (!scenes.empty())
				{
					scenes.pop_back();
				}
				scenes.push_back(std::move(action.scene));
				break;

		default: 
			break;
		}
	}
	pendingActions.clear();
}


void SceneManager::handleEvents(sf::Event& ev, sf::RenderWindow& window)
{
	//если сцен в векторе будет 0, то включаем GameScene
	//при переходе на сцену выше, условно меню -> настройки 
	//в векторе морозиться прошлая сцена и рендерится наша новая
	if (!scenes.empty())
		scenes.back()->handleEvent(ev, window);
}

void SceneManager::update(float dt)
{
	for (int i = scenes.size() - 1; i >=0 ; --i)
	{
		scenes[i]->update(dt);
		if (scenes[i]->blocksUpdateBelow()) {
			break;
		}
	}
	applyPendingChanges();
}

void SceneManager::render(sf::RenderTarget* target)
{
	if (scenes.empty()) return;

	int startIndex = static_cast<int>(scenes.size()) - 1;

	// ищем самую нижнюю сцену которую нужно рисовать
	for (int i = startIndex; i >= 0; --i)
	{
		if (scenes[i]->blocksRenderBelow())
		{
			startIndex = i;
			break;
		}
	}

	// теперь рисуем снизу вверх
	for (int i = startIndex; i < scenes.size(); ++i)
	{
		target->setView(scenes[i]->getView());
		scenes[i]->render(target);
	}
}

Scene* SceneManager::getCurrentScene()
{
	return scenes.back().get();
}

sf::RenderWindow* SceneManager::getWindow()
{
	return window;
}

void SceneManager::setWindowSize(int x,int y) {
	window->setSize(sf::Vector2u(x,y));
}