#include "Special_Platforms.h"
#include "constants.h"

float const extra_jump_value = 15.0;
float const moving_platform_speed = 2.0;

////////////////
//Extra_Jump_Platform
////////////////

//konstruktor
Extra_Jump_Platform::Extra_Jump_Platform()
    : Extra_Jump_Platform(sf::Vector2f(0, 0))
{ }

Extra_Jump_Platform::Extra_Jump_Platform( float x, float y )
    : Extra_Jump_Platform( sf::Vector2f(x, y) )
{ }

Extra_Jump_Platform::Extra_Jump_Platform(sf::Vector2f pos)
    : Platform(pos)
{ 
    jump_value = extra_jump_value;
}

////////////////
//Breaking_Platform
////////////////

//konstruktor
Breaking_Platform::Breaking_Platform()
    : Breaking_Platform(sf::Vector2f(0, 0))
{ }

Breaking_Platform::Breaking_Platform( float x, float y )
    : Breaking_Platform( sf::Vector2f(x, y) )
{ }

Breaking_Platform::Breaking_Platform(sf::Vector2f pos)
    : Platform(pos), fall_speed{0}
{
    shape.setTextureRect(red_platform_intact);
}

//funktioner
void Breaking_Platform::handle_collision( Entity const& )
{
    if(intact)
    {
        intact = false;
        shape.setTextureRect(red_platform_broken);
    }
}

void Breaking_Platform::update()
{
    if(!intact)
    {
        fall_speed += 0.2;
        this->position.y += fall_speed;
    }
    Platform::update();
}

////////////////
//Moving_Platform
////////////////

//konstruktor
Moving_Platform::Moving_Platform()
    : Moving_Platform(sf::Vector2f(0, 0))
{ }

Moving_Platform::Moving_Platform( float x, float y )
    : Moving_Platform( sf::Vector2f(x, y) )
{ }

Moving_Platform::Moving_Platform(sf::Vector2f pos)
    : Platform(pos)
{   
    shape.setTextureRect(blue_platform);
}

//funktioner
void Moving_Platform::update()
{
    if(moving_right)
    {
        move(sf::Vector2f(moving_platform_speed, 0));
        if(position.x + shape.getGlobalBounds().width >= screen_width)
            moving_right = false;
    }
    else
    {
        move(sf::Vector2f(-moving_platform_speed, 0));
        if(position.x <= 0)
            moving_right = true;
    }
    Platform::update();
}

////////////////
//Disappearing_Platform
////////////////

//konstruktor
Disappearing_Platform::Disappearing_Platform()
    : Disappearing_Platform(sf::Vector2f(0, 0))
{ }

Disappearing_Platform::Disappearing_Platform( float x, float y )
    : Disappearing_Platform( sf::Vector2f(x, y) )
{ }

Disappearing_Platform::Disappearing_Platform(sf::Vector2f pos)
    : Platform(pos), fade_val{255}
{
    shape.setTextureRect(white_platform);
}

//funktioner
void Disappearing_Platform::render( sf::RenderTarget & target)
{
    //if(intact)
        Platform::render(target);
}

void Disappearing_Platform::handle_collision( Entity const& ent)
{
    if(intact)
    {
        intact = false;
        Platform::handle_collision(ent);
    }
}

void Disappearing_Platform::update()
{
    if(!intact)
    {
        if (fade_val != 0)
        {
            fade_val -= 15;
            shape.setColor(sf::Color(255, 255, 255, fade_val));
        }
    }
    Platform::update();
}