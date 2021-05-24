#ifndef TEXTFIELD_H
#define TEXTFIELD_H

#include <SFML/Graphics.hpp>
#include "constants.h"

class Textfield
{

public:

Textfield();

void handle_event(sf::Event event);

void render(sf::RenderTarget & target);

std::string get_entered_name();

void setPosition(float x, float y);
void setFieldText(std::string const&);
void reset();

int getWidth();
int getHight();

bool isEntered();

private:
int const char_limit;
int const align_text{15};
sf::String input;
sf::Text text;
sf::Text description;
sf::Vector2f position;
sf::RectangleShape box; 
bool isSelected;
bool isEntered_flag;


};

#endif 