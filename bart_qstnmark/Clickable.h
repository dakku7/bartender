#pragma once
#include "Entity.h"

enum class ClickType {
	Default
};

class Clickable : public Entity {
private:
	ClickType actionType;

public:
	Clickable(ClickType action = ClickType::Default)
		: actionType(action)
	{

	}
	virtual bool contains(sf::Vector2f point) const = 0;
	virtual void clicked() = 0;
	virtual void setHovered(bool expr) = 0;

	ClickType getClickType() {
		return actionType;
	}
};