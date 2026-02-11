#include "Button.h"

Button::Button(TextureID basic_tex, TextureID lighted_tex, AssetManager* asset_mgr)
	: id(basic_tex), id_light(lighted_tex), ass_mgr(asset_mgr)
{
	initSprite();
}

void Button::initSprite()
{
	ass_mgr->loadTexture(id);
	ass_mgr->loadTexture(id_light);

	button.setTexture(ass_mgr->getTexture(id));
}

void Button::setHovered(bool exprs)
{
	isHovered = exprs;
	if (isHovered) {
		button.setTexture(ass_mgr->getTexture(id_light));
	}
	else {
		button.setTexture(ass_mgr->getTexture(id));

	}
}

void Button::setCallback(Callback func)
{
	callback = func;
}

bool Button::contains(sf::Vector2f point) const
{
	return this->button.getGlobalBounds().contains(point);
}

void Button::clicked()
{
	if (callback) {
		callback();
	}
}


void Button::update(float dt)
{

}

void Button::render(sf::RenderTarget* window)
{

	window->draw(this->button);
}

sf::Sprite& Button::getSprite()
{
	return button;
}

void Button::setPosition(const sf::Vector2f& pos)
{
	button.setPosition(pos);
}

sf::Vector2f Button::getPosition() const
{
	return button.getPosition();
}
