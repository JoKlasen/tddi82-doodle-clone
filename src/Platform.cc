#include "Platform.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>

#include <vector>
#include <string>

#include <iostream> //debug


//konstruktor
Platform::Platform()
    : Platform(sf::Vector2f(0, 0))
{ }

Platform::Platform( float x, float y )
    : Platform( sf::Vector2f(x, y) )
{ }

Platform::Platform(sf::Vector2f pos)
    : Entity(), shape{Texture_Manager::load(spritesheet_file), green_platform}
{
    shape.setScale(0.75, 0.75);
    Entity::position = pos; 
}

Platform::Platform(std::string pname, sf::Vector2f pposition, std::vector<int> pCollisionContainer)
    : Entity{pname, pposition, pCollisionContainer}, shape{Texture_Manager::load(spritesheet_file), green_platform}
{ }

void Platform::render(sf::RenderTarget & target)
{
    target.draw(shape);
}

void Platform::update() 
{
    shape.setPosition( position ) ;
}

void Platform::handle_collision( Entity const&)
{
    Entity::acceleration = -jump_value;
    //auto = &e;
}

sf::FloatRect Platform::getGlobalBounds() const
{
    return shape.getGlobalBounds() ;
}