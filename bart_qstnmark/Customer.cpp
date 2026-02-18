#include "Customer.h"

Customer::Customer(AssetManager* assmgr, std::string name, Mood mood)
	: Character(name, mood), ass_mgr(assmgr)
{
	init();
}

void Customer::init() {
	ass_mgr->loadTexture(TextureID::Customer_Default);
	ass_mgr->loadTexture(TextureID::Customer_Interact_Icon);

	interactIcon.setTexture(ass_mgr->getTexture(TextureID::Customer_Interact_Icon));
	interactIcon.setScale(1.5, 1.5);

	sf::FloatRect temp = interactIcon.getLocalBounds();
	interactIcon.setOrigin(temp.width / 2.f, temp.height);
	

	sprite.setTexture(ass_mgr->getTexture(TextureID::Customer_Default));
	sprite.setPosition(ENTRANCE_ZONE_X, ENTRANCE_ZONE_Y);

	this->state = CustomerState::Walking;
}

//rename func
void Customer::reactionToInteraction()
{
	
}

void Customer::update(float dt)
{
	switch (state)
	{
	case CustomerState::Walking:
		moveTowards(dt);
		break;
	case CustomerState::Waiting:
		waitForInteraction();
		break;
	case CustomerState::InDialogue:
		break;
	case CustomerState::WaitingDrink:
		break;
	case CustomerState::Drinking:
		break;
	case CustomerState::Leaving:
		break;
	default:
		break;
	}
}

void Customer::render(sf::RenderTarget* window)
{
	window->draw(this->sprite);
	if (interact) {
		interactIcon.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width / 2, sprite.getPosition().y + 60);
		window->draw(interactIcon);
	}
}

void Customer::moveTowards(float dt)
{
	sf::Vector2f currentPos = sprite.getPosition();
	sf::Vector2f target(INTERACT_ZONE_X, INTERACT_ZONE_Y);

	sf::Vector2f direction = target - currentPos;

	float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

	if (length < 2.f)
	{
		state = CustomerState::Waiting;
		return;
	}

	direction /= length; // нормализация

	sprite.move(direction * move_speed * dt);
}

void Customer::waitForInteraction()
{
	if (state == CustomerState::Waiting) {
		interact = true;
	}

	if (!interact) return;



}

std::vector<std::string> Customer::getDialogue()
{
	return {
		"Good evening.",
		"I'd like something strong.",
		"Surprise me."
	};
}

void Customer::setCustomerStatus(CustomerState status)
{
	this->state = status;
}

sf::Vector2f Customer::getPosition() const
{
	return sprite.getPosition();
}