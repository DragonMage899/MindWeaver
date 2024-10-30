#include <SFML/Graphics.hpp>
#include <map>
#include <string>

#include "texture_manager.hpp"

void TextureManager::loadTexture(const std::string& name, const std::string& filename)
{
    //input: name of texture and file path
    //load textures from that file and add it to the std::map

    /* Load the texture */
    sf::Texture tex;
    tex.loadFromFile(filename);

    /* Add it to the list of textures */
    this->textures[name] = tex;

    return;
}

sf::Texture& TextureManager::getRef(const std::string& texture)
{
    return this->textures.at(texture);
}