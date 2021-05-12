#ifndef TEXTFIELD_H
#define TEXTFIELD_H

#include <SFML/Graphics.hpp>

class Textfield
{

public:

Textfield();
//Textfield(sf::Font pfont, int size, sf::Vector2f pposition);

void handle_event(sf::Event event);

void render(sf::RenderTarget & target);

private:

sf::Font font;
sf::String input;
sf::Text text;
sf::Vector2f position;
sf::RectangleShape box; 


};

#endif 