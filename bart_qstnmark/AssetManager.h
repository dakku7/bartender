#pragma once
#include <SFML/Graphics.hpp>

enum class TextureID {
	//id list
	Menu_Backgorund,
	Menu_Button,
	Menu_Button_Lightened,
	Game_Background,
};

class AssetManager
{
public:
	bool loadTexture(TextureID id);
	const sf::Texture& getTexture(TextureID id);
private:
	std::map<TextureID, std::unique_ptr<sf::Texture>> textures;
	std::string getPath(TextureID id);
};

