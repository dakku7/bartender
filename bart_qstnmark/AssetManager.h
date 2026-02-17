#pragma once
#include <SFML/Graphics.hpp>

enum class TextureID {
	//id list
	Menu_Backgorund,
	Menu_Button,
	Menu_Button_Lightened,
	Game_Background,
	Game_Grid,
	Bar,

  //options
	Options_Background,
	Options_Arrow_Right,
	Options_Arrow_Left,
	Options_Arrow_Right_Lightened,
	Options_Arrow_Left_Lightened,

	//main char
	Main_Char_Default,
	
	//customers
	Customer_Default,
	Customer_Interact_Icon,

	Dialogue_Bar
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

