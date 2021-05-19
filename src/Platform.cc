#include "Platform.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>

#include <vector>
#include <string>

#include <iostream> //debug

//Sounds sounds;

void Platform::default_shape()
{
    //shape.setOutlineColor(sf::Color::Blue);
    //shape.setOutlineThickness(5);
}

 

//konstruktor
Platform::Platform()
    : Entity(), shape{Texture_Manager::load(spritesheet_file), green_platform}
{   
    shape.setScale(0.75, 0.75);
    //default_shape();
}

Platform::Platform( float x, float y )
    : Platform( sf::Vector2f(x, y) )
{ }

Platform::Platform(sf::Vector2f pos)
    : Entity(), shape{Texture_Manager::load(spritesheet_file), green_platform}
{
    shape.setScale(0.75, 0.75);
    Entity::position = pos; 
    //default_shape();
}

Platform::Platform(std::string pname, sf::Vector2f pposition, std::vector<int> pCollisionContainer)
    : Entity{pname, pposition, pCollisionContainer}, shape{Texture_Manager::load(spritesheet_file), green_platform}
{
    //default_shape();
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
    Entity::acceleration = -jump_value;
    Sounds::jump();
    //auto = &e;
}

sf::FloatRect Platform::getGlobalBounds() const
{
    return shape.getGlobalBounds() ;
}