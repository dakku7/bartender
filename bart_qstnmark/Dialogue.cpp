#include "Dialogue.h"

Dialogue::Dialogue(AssetManager* assmgr, SceneManager* scenemgr, std::shared_ptr<Customer> customer)
    : Scene(assmgr, scenemgr), current_customer(customer), view(sf::Vector2f(WIDTH / 2, HEIGHT / 2), sf::Vector2f(WIDTH, HEIGHT))
{
    init();
}

void Dialogue::init()
{
    ass_mgr->loadTexture(TextureID::Dialogue_Bar);
    panel.setTexture(ass_mgr->getTexture(TextureID::Dialogue_Bar));
    panel.setPosition(DIALOGUE_BOX_X, DIALOGUE_BOX_Y);
    font.loadFromFile("font\\dialogue.ttf");
    text.setFont(font);
    text.setPosition(DIALOGUE_BOX_X, DIALOGUE_BOX_Y);
    takeTextLines();
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
    if (currentLine >= lines.size()) {
        scene_mgr->popScene();
        current_customer->setCustomerStatus(CustomerState::WaitingDrink);
        return;
    }
    else {
        text.setString(lines[currentLine]);

    }
}

void Dialogue::render(sf::RenderTarget* target) 
{
    target->draw(panel);
    target->draw(text);
}

void Dialogue::nextLine()
{
    currentLine++;
}

void Dialogue::takeTextLines()
{
    for (int i = 0; i < current_customer->getDialogue().size(); i++)
    {
        this->lines.push_back(current_customer->getDialogue()[i]);
    }
}
