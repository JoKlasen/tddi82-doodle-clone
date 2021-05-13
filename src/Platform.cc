#include "Platform.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>

#include <vector>
#include <string>




//konstruktor
Platform::Platform()
    : Entity()
{

}

Platform::Platform(std::string pname, sf::Vector2f pposition, std::vector<int> pCollisionContainer)
    : Entity{pname, pposition, pCollisionContainer}
{
    //sf::CircleShape shape(10.f);
    //shape.setPosition( position ) ;

}

void Platform::render(sf::RenderTarget & target)
{
    //target.draw(shape);
}

void Platform::update() 
{
    //shape.setFillColor(sf::Color::Red);
}

void Platform::handle_collision( Entity const& e)
{
    //auto = &e;
}

