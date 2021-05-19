#include "Platform.h"
#include "Entity.h"
#include "constants.h"
#include <SFML/Graphics.hpp>
#include <random>
#include <vector>
#include <string>

#include <iostream> //debug


void Platform::default_shape()
{
    //shape.setOutlineColor(sf::Color::Blue);
    //shape.setOutlineThickness(5);
    CollisionContainer.push_back(shape.getLocalBounds ()); //migt become a isue
}

void Platform::make_power_up(std::unique_ptr<Power_Up> & pwup) // ändra här för hur ofta power_ups ska spawna
{
    std::random_device rd;
    std::uniform_int_distribution<int> distrib(0, 3);
    std::mt19937 gen(rd());
    int rand = distrib(gen);
    if(rand != 8)
    {
        pwup = std::make_unique<Spring>();
        has_power_up = true;
    }
    else if(rand > 2)
    {
        pwup = std::make_unique<Shield>();
        has_power_up = true;
    }
    else
    {
        pwup = std::make_unique<Empty_Power>();
    }
}

//konstruktor
Platform::Platform()
    : Entity(), shape{Texture_Manager::load(spritesheet_file), green_platform}, has_power_up{false}, power_up{nullptr}
{   
    shape.setScale(0.75, 0.75);
    make_power_up(power_up);
    //default_shape();
}

Platform::Platform( float x, float y )
    : Platform( sf::Vector2f(x, y) )
{
}

Platform::Platform(sf::Vector2f pos)
    : Entity(), shape{Texture_Manager::load(spritesheet_file), green_platform},has_power_up{false},power_up{nullptr}
{
    shape.setScale(0.75, 0.75);
    Entity::position = pos; 
    CollisionContainer.push_back(shape.getLocalBounds ()); //migt become a isue
    make_power_up(power_up);
    //default_shape();
}

Platform::Platform(std::string pname, sf::Vector2f pposition, std::vector<sf::Rect< float >> pCollisionContainer)
    : Entity{pname, pposition, pCollisionContainer}, shape{Texture_Manager::load(spritesheet_file), green_platform}, has_power_up{false},power_up{nullptr}
{
    //default_shape();
    make_power_up(power_up);
}

void Platform::render(sf::RenderTarget & target)
{
    target.draw(shape);
    //std::cout << "Platform::render()" << std::endl;   //debug
    power_up->render(target);
}

void Platform::update() 
{
    shape.setPosition( position );
    power_up->set_pos(shape.getPosition());
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
