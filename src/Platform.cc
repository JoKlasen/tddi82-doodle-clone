#include "Platform.h"

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>




//konstruktor
Platform::Platform()
    : position{0.0, 0.0}, acceleration{0.0, 0.0}
{
    sf::CircleShape shape(10.f);
    shape.setPosition( position ) ;
}

void render(sf::RenderTarget & target)
{
    //target.draw(shape);
}

void update() 
{
    //shape.setFillColor(sf::Color::Red);
}

void handle_collision( Entity const& e)
{
    auto = &e;
}

