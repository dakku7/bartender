#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
private:
	sf::Sprite* sprite;  // указатель на спрайт, который будет отображать анимацию
	std::vector<sf::Texture*> frames; // вектор указателей на текстуры, которые будут использоваться для анимации

	float timer = 0.f;
	int currentFrame = 0;
	float frameTime = 0.f;

public:
	Animation(std::vector<sf::Texture*>& target_frames, float frame_time);
	void update(float dt);
};

