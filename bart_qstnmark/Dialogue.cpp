#include "Dialogue.h"

Dialogue::Dialogue(AssetManager* assmgr, SceneManager* scenemgr)
	: Scene(assmgr, scenemgr)
{
}

void Dialogue::handleEvent(sf::Event ev, sf::RenderWindow& window)
{
	switch (ev.type)
	{
	default:
		break;
	}
}

void Dialogue::update(float dt) 
{
	
}

void Dialogue::render(sf::RenderTarget* target) 
{

}