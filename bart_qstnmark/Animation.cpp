#include "Animation.h"

Animation::Animation(std::vector<sf::Texture*>& target_frames, float frame_time)
	: frames(target_frames), frameTime(frame_time) // конструктор класса Animation,
{                                                  //который принимает вектор указателей на текстуры и время между кадрами
	if (!frames.empty()) { // проверка на глупость, 
        sprite->setTexture(*frames[0]); //если вектор текстур не пустой, то устанавливаем первую текстуру спрайта
    }
}

void Animation::update(float dt) // метод update класса Animation, который обновляет анимацию
{
    timer += dt;
	if (timer >= frameTime) // если таймер превышает время между кадрами, то переходим к следующему кадру
    {
        currentFrame++;

		if (currentFrame >= frames.size()) { // если текущий кадр превышает количество кадров, то возвращаемся к первому кадру
            currentFrame = 0;
        }

		sprite->setTexture(*frames[currentFrame]); // устанавливаем текстуру спрайта на текущий кадр

		timer = 0.f; // сбрасываем таймер
    }
}
