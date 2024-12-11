#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <utility>
#include <string>
#include "GuiEntry.h"
#include "GuiStyle.h"

class Gui : public sf::Transformable, public sf::Drawable
{
private:
    /* If true the menu entries will be horizontally, not vertically, adjacent */
    bool horizontal;

    GuiStyle style;

    sf::Vector2f dimensions;

    int padding;

public:
    std::vector<GuiEntry> entries;

    bool visible;

    /* Constructor */
    Gui(sf::Vector2f dimensions, int padding, bool horizontal,
        GuiStyle &style, std::vector<std::pair<std::string, std::string> > entries)
    {
        visible = false;
        this->horizontal = horizontal;
        this->style = style;
        this->dimensions = dimensions;
        this->padding = padding;

        /* Construct the background shape */
        sf::RectangleShape shape;
        shape.setSize(dimensions);
        shape.setFillColor(style.bodyCol);
        shape.setOutlineThickness(-style.borderSize);
        shape.setOutlineColor(style.borderCol);

        /* Construct each gui entry */
        for (auto entry : entries)
        {
            /* Construct the text */
            sf::Text text;
            text.setString(entry.first);
            text.setFont(*style.font);
            text.setFillColor(style.textCol);
            text.setCharacterSize(dimensions.y - style.borderSize - padding);

            this->entries.push_back(GuiEntry(entry.second, shape, text));
        }
    }

    sf::Vector2f getSize();

    /* Return the entry that the mouse is hovering over. Returns
     * -1 if the mouse if outside of the Gui */
    int getEntry(const sf::Vector2f mousePos);

    /* Change the text of an entry. */
    void setEntryText(int entry, std::string text);

    /* Change the entry dimensions. */
    void setDimensions(sf::Vector2f dimensions);

    /* Draw the menu. */
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    void show();

    void hide();

    /* Highlights an entry of the menu. */
    void highlight(const int entry);

    /* Return the message bound to the entry. */
    std::string activate(const int entry);
    std::string activate(const sf::Vector2f mousePos);
};

#endif /* GUI_HPP */
