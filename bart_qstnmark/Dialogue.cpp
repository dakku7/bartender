#include "Dialogue.h"

Dialogue::Dialogue(AssetManager* assmgr, SceneManager* scenemgr)
	: Scene(assmgr, scenemgr)
{
}

void Dialogue::handleEvent(sf::Event& ev, sf::RenderWindow& window)
{
    switch (ev.type)
    {
    case sf::Event::KeyPressed:
        if (ev.key.code == sf::Keyboard::Space)
            nextLine();
        break;

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

void Dialogue::nextLine()
{
}
