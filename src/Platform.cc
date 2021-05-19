#include "Platform.h"
#include "Entity.h"
#include "constants.h"
#include <SFML/Graphics.hpp>

#include <vector>
#include <string>

#include <iostream> //debug


void Platform::default_shape()
{
    //shape.setOutlineColor(sf::Color::Blue);
    //shape.setOutlineThickness(5);
    CollisionContainer.push_back(shape.getLocalBounds ()); //migt become a isue
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
{
}

Platform::Platform(sf::Vector2f pos)
    : Entity(), shape{Texture_Manager::load(spritesheet_file), green_platform}
{
    shape.setScale(0.75, 0.75);
    Entity::position = pos; 
    CollisionContainer.push_back(shape.getLocalBounds ()); //migt become a isue
    //default_shape();
}

Platform::Platform(std::string pname, sf::Vector2f pposition, std::vector<sf::Rect< float >> pCollisionContainer)
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

void Platform::handle_collision( Entity & ent)
{
    while (!colitionList.empty())
    {
        double acc {ent.getAcceleration()};
        if (colitionList.back() == std::tuple<int, int>{PLAYER_LEGS, PLATFORM_ANY})
        {
	
	        if(acc > 0)
	        {
	            Entity::acceleration = -jump_value;
	        }
        }
	/*
        else if (colitionList.back() == std::tuple<int, int>{PLAYER_HEAD, PLATFORM_ANY})
        {
	        if(acc < 0)
	        {
	            Entity::acceleration = 0;
	        }
        }
	*/
        colitionList.pop_back();
    } 
}





sf::Rect< float > Platform::getGlobalBounds()
{
    return shape.getGlobalBounds();
}

sf::FloatRect Platform::getGlobalBounds() const
{
    return shape.getGlobalBounds() ;
}
