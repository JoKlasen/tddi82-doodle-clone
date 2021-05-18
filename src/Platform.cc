#include "Platform.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>

#include <vector>
#include <string>

#include <iostream> //debug


void Platform::default_shape()
{
    shape.setOutlineColor(sf::Color::Blue);
    shape.setOutlineThickness(5);
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
    Entity::acceleration = -(jump_value);
    //auto = &e;
}

