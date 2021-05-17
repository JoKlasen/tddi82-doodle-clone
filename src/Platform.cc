#include "Platform.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>

#include <vector>
#include <string>

#include <iostream> //debug


void Platform::default_shape()
{
    shape.setFillColor(sf::Color::Green);
    //shape.setOutlineColor(sf::Color::Green);
    //shape.setOutlineThickness(5);
}



//konstruktor
Platform::Platform()
    : Entity()
{
    default_shape();
}

Platform::Platform( float x, float y )
    : Platform( sf::Vector2f(x, y) )
{ }

Platform::Platform(sf::Vector2f pos)
    : Entity()
{
    Entity::position = pos; 
    default_shape();
}

Platform::Platform(std::string pname, sf::Vector2f pposition, std::vector<int> pCollisionContainer)
    : Entity{pname, pposition, pCollisionContainer}
{
    default_shape();
}

void Platform::render(sf::RenderTarget & target)
{
    target.draw(shape);
    //std::cout << "Platform::render()" << std::endl;   //debug
}

void Platform::update() 
{
    shape.setPosition( position ) ;
}

void Platform::handle_collision( Entity const&)
{
    Entity::acceleration = -7.5;
    //auto = &e;
}

sf::FloatRect Platform::getGlobalBounds() const
{
    return shape.getGlobalBounds() ;
}