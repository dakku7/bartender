#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
private:
	sf::Sprite* sprite;
	std::vector<sf::Texture*> frames;

	float timer = 0.f;
	int currentFrame = 0;
	float frameTime = 0.f;

public:
	Animation(std::vector<sf::Texture*>& target_frames, float frame_time);
	void update(float dt);
};

