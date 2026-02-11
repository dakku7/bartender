#pragma once
#include "SFML/Graphics.hpp"

struct TimeBar
{
    sf::Sprite sprite;
    sf::RectangleShape fill_bar;
    float x = 0.f;
    float y = 0.f;
    float fill = 0.f;
    float max_fill = 100.f;
};

struct DialogBox
{
    sf::Sprite sprite;
    float x = 0.f;
    float y = 0.f;

    //примерный текст хз надо заменить на класс желатенльо
    sf::Text text;
};

class HUD
{
private:
    TimeBar timeBar;
    DialogBox dialogBox;
public:
    void render(sf::RenderWindow& window);
    void update(float dt);
};