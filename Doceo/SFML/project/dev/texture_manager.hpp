#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class TextureManager
{
    private:

    /* Array of textures used */
    std::map<std::string, sf::Texture> textures; //Map of texture
        //NB: sf::textures are immutable and drawable (can't be changed on a pixel by pixel basis, unlike sf::image which can be changed but can't be drawn)

    public:

    /* Add a texture from a file */
    void loadTexture(const std::string& name, const std::string &filename);

    /* Translate an id into a reference */
    sf::Texture& getRef(const std::string& texture); //Look for texture in our map, return reference

    /* Constructor */
    TextureManager()
    {
    }
};

#endif