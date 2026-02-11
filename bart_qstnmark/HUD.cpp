#include "HUD.h"

void HUD::render(sf::RenderWindow& window)
{
    window.draw(timeBar.sprite);
    window.draw(timeBar.fill_bar);
    window.draw(dialogBox.text);
    window.draw(dialogBox.sprite);
}
