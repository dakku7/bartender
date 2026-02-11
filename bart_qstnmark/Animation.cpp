#include "Animation.h"

Animation::Animation(std::vector<sf::Texture*>& target_frames, float frame_time)
    :  frames(target_frames), frameTime(frame_time)
{
    if (!frames.empty()) {
        sprite->setTexture(*frames[0]);
    }
}

void Animation::update(float dt)
{
    timer += dt;
    if (timer >= frameTime)
    {
        currentFrame++;

        if (currentFrame >= frames.size()) {
            currentFrame = 0;
        }

        sprite->setTexture(*frames[currentFrame]);

        timer = 0.f;
    }
}
