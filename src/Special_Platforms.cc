#include "Special_Platforms.h"
#include "constants.h"

float const extra_jump_value = 15.0;
float const platform_speed = 2.0;

////////////////
//Extra_Jump_Platform
////////////////

void Extra_Jump_Platform::default_shape()
{
    shape.setOutlineColor(sf::Color::Yellow);
    shape.setOutlineThickness(5);
}

//konstruktor
Extra_Jump_Platform::Extra_Jump_Platform()
    : Platform()
{
    default_shape();
    jump_value = extra_jump_value;
}

Extra_Jump_Platform::Extra_Jump_Platform( float x, float y )
    : Extra_Jump_Platform( sf::Vector2f(x, y) )
{ }

Extra_Jump_Platform::Extra_Jump_Platform(sf::Vector2f pos)
    : Platform(pos)
{ 
    default_shape();
    jump_value = extra_jump_value;
}


////////////////
//Breaking_Platform
////////////////

//konstruktor
Breaking_Platform::Breaking_Platform()
    : Platform()
{
    default_shape();
}

Breaking_Platform::Breaking_Platform( float x, float y )
    : Breaking_Platform( sf::Vector2f(x, y) )
{ }

Breaking_Platform::Breaking_Platform(sf::Vector2f pos)
    : Platform(pos)
{ 
    default_shape();
}

//funktioner
void Breaking_Platform::default_shape()
{
    shape.setOutlineColor(sf::Color::Magenta);
    shape.setOutlineThickness(5);
}

void Breaking_Platform::render( sf::RenderTarget & target)
{
    if(intact)
        target.draw(shape);
}

void Breaking_Platform::handle_collision( Entity const& )
{
    if(intact)
    {
        Entity::acceleration = -(jump_value);
        intact = false;
    }
}

////////////////
//Moving_Platform
////////////////

//konstruktor
Moving_Platform::Moving_Platform()
    : Platform()
{
    default_shape();
}

Moving_Platform::Moving_Platform( float x, float y )
    : Moving_Platform( sf::Vector2f(x, y) )
{ }

Moving_Platform::Moving_Platform(sf::Vector2f pos)
    : Platform(pos)
{ 
    default_shape();
}

//funktioner
void Moving_Platform::default_shape()
{
    shape.setOutlineColor(sf::Color::Red);
    shape.setOutlineThickness(5);
}

void Moving_Platform::update()
{
    if(moving_right)
    {
        move(sf::Vector2f(platform_speed, 0));
        if(position.x + shape.getGlobalBounds().width >= screen_width)
        {
            moving_right = false;
        }
    }
    else
    {
        move(sf::Vector2f(-platform_speed, 0));
        if(position.x <= 0)
        {
            moving_right = true;
        }
    }
    Platform::update();
}
