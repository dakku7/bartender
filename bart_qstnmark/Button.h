#pragma once
#include <functional>
#include "SFML/Graphics.hpp"
#include "Clickable.h"
#include "AssetManager.h"


class Button : public Clickable {
public: 
	using Callback = std::function<void()>;

private:
	sf::Sprite button;
	TextureID id;
	TextureID id_light;

	AssetManager* ass_mgr;
	bool isHovered = false;

	//callback for click method
	Callback callback;
public:
	Button(TextureID basic_tex, TextureID lighted_tex, AssetManager* asset_mgr);
	void initSprite();

	void setHovered(bool exprs) override;
	void setCallback(Callback func);
	bool contains(sf::Vector2f point) const override;
	void clicked() override;

	void update(float dt) override;
	void render(sf::RenderTarget* window) override;

	void setPosition(const sf::Vector2f& pos);
	sf::Vector2f getPosition() const override;
	sf::Sprite& getSprite();
};
