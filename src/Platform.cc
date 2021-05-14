#include "Platform.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>

#include <vector>
#include <string>

#include <iostream> //debug


//konstruktor
Platform::Platform()
    : Entity()
{
    shape.setOutlineColor(sf::Color::Blue);
    shape.setOutlineThickness(5);
}
/*
Platform::Platform(int x)
    : Entity()
{
    shape.setOutlineColor(sf::Color::Blue);
    shape.setOutlineThickness(5);
} //*/

Platform::Platform(std::string pname, sf::Vector2f pposition, std::vector<int> pCollisionContainer)
    : Entity{pname, pposition, pCollisionContainer}
{
    shape.setOutlineColor(sf::Color::Blue);
    shape.setOutlineThickness(5);
}

void Platform::render(sf::RenderTarget & target)
{
    target.draw(shape);
    //std::cout << "Platform::render()" << std::endl;   //debug
}

void Platform::update() 
{
    shape.setPosition( position ) ;
    //shape.setPosition( 10, 20 );
}

void Platform::handle_collision( Entity const&)
{
    //auto = &e;
}

