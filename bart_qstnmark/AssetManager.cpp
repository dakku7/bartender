#include "AssetManager.h"
#include <iostream>

bool AssetManager::loadTexture(TextureID id)
{
    if (textures.find(id) != textures.end())
        return true;

    auto tex = std::make_unique<sf::Texture>();
    std::string path = getPath(id);
    if (path.empty()) {
        std::cout << "No path for TextureID=" << static_cast<int>(id) << "\n";
        return false;
    }

    if (!tex->loadFromFile(path)) {
        std::cout << "Error loading texture: " << path << "\n";
        return false;
    }
    textures.emplace(id, std::move(tex));
    return true;
}

std::string AssetManager::getPath(TextureID id)
{
    switch (id)
    {
    case TextureID::Menu_Backgorund:
        return "img\\menu\\background.png";
    case TextureID::Menu_Button:
        return "img\\menu\\button.png";
    case TextureID::Menu_Button_Lightened:
        return "img\\menu\\button_light.png";
    case TextureID::Game_Background:
        return "img\\game\\background.png";
    }
    return "";
}

const sf::Texture& AssetManager::getTexture(TextureID id)
{
    auto it = textures.find(id);
    if (it == textures.end()) {
        std::cout << "Requested texture not loaded: " << static_cast<int>(id) << "\n";
    }
    return *(it->second);
}
