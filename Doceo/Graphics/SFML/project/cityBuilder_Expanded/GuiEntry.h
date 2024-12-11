#ifndef GUIENTRY_H
#define GUIENTRY_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <utility>
#include <string>

class GuiEntry
{
public:
    /* Handles appearance of the entry */
    sf::RectangleShape shape;

    /* String returned when the entry is activated */
    std::string message;

    /* Text displayed on the entry */
    sf::Text text;

    GuiEntry(const std::string &message, sf::RectangleShape shape, sf::Text text)
    {
        this->message = message;
        this->shape = shape;
        this->text = text;
    }
    GuiEntry() {}
};


#endif