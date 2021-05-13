#ifndef TEXTFIELD_H
#define TEXTFIELD_H

#include <SFML/Graphics.hpp>

class Textfield
{

public:

Textfield();
Textfield(sf::Vector2f pposition, int width, int height, int limit, std::string pdescription);

void handle_event(sf::Event event);

void render(sf::RenderTarget & target);

std::string get_entered_name();

bool isEntered();

private:
int const char_limit;
sf::Font font;
sf::String input;
sf::Text text;
sf::Text description;
sf::Vector2f position;
sf::RectangleShape box; 
bool isSelected;
bool isEntered_flag;

};

#endif 