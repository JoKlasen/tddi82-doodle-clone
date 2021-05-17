#include "Platform.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <random>
#include <vector>
#include <string>

#include <iostream> //debug


void Platform::default_shape()
{
    shape.setOutlineColor(sf::Color::Blue);
    shape.setOutlineThickness(5);
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
    : Entity(), power_up{}, has_power_up{false}
{
    default_shape();

    // power_up

    make_power_up(power_up);
}

Platform::Platform( float x, float y )
    : Platform( sf::Vector2f(x, y) )
{ }

Platform::Platform(sf::Vector2f pos)
    : Entity(), power_up{}, has_power_up{false}
{
    Entity::position = pos; 
    default_shape();

    // power_up
    make_power_up(power_up);

}

Platform::Platform(std::string pname, sf::Vector2f pposition, std::vector<int> pCollisionContainer)
    : Entity{pname, pposition, pCollisionContainer}, power_up{},has_power_up{false}
{
    default_shape();

    // power_up
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

void Platform::handle_collision( Entity const&)
{
    Entity::acceleration = -7.5;
    //auto = &e;

    
}

