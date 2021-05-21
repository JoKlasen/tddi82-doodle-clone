#include "Special_Platforms.h"
#include "constants.h"

float const extra_jump_value = 15.0;
float const moving_platform_speed = 2.0;

////////////////
//Extra_Jump_Platform
////////////////

Extra_Jump_Platform::Extra_Jump_Platform( float x, float y )
    : Extra_Jump_Platform( sf::Vector2f(x, y) )
{ }

Extra_Jump_Platform::Extra_Jump_Platform(sf::Vector2f pos)
    : Platform("Extra_Jump_Platform", pos)
{ 
    jump_value = extra_jump_value;
}

////////////////
//Breaking_Platform
////////////////

//konstruktor
Breaking_Platform::Breaking_Platform( float x, float y )
    : Breaking_Platform( sf::Vector2f(x, y) )
{ }

Breaking_Platform::Breaking_Platform(sf::Vector2f pos)
    : Platform("Breaking_Platform", pos), fall_speed{0}
{
    sprite.setTextureRect(red_platform_intact);
}

//funktioner
void Breaking_Platform::handle_collision( Entity & ent)
{
    while (!collisionList.empty())
    {
        double acc {ent.getAcceleration()};
        if (collisionList.back() == std::tuple<int, int>{PLAYER_LEGS, PLATFORM_ANY})
        {
	
	        if(acc > 0)
	        {
                if(intact)
                {
                    intact = false;
                    sprite.setTextureRect(red_platform_broken);
                    check_power();
                }
	        }
        }
        collisionList.pop_back();
    } 
}

void Breaking_Platform::update()
{
    if(!intact)
    {
        fall_speed += 0.2;
        move(0, fall_speed);
        //this->position.y += fall_speed;
    }
    Platform::update();
}

////////////////
//Moving_Platform
////////////////

//konstruktor
Moving_Platform::Moving_Platform( float x, float y )
    : Moving_Platform( sf::Vector2f(x, y) )
{ }

Moving_Platform::Moving_Platform(sf::Vector2f pos)
    : Platform("Moving_Platform", pos)
{   
    sprite.setTextureRect(blue_platform);
}

//funktioner
void Moving_Platform::update()
{
    if(moving_right)
    {
        move(sf::Vector2f(moving_platform_speed, 0));
        if(getPosition().x + sprite.getGlobalBounds().width >= screen_width)
            moving_right = false;
    }
    else
    {
        move(sf::Vector2f(-moving_platform_speed, 0));
        if(getPosition().x <= 0)
            moving_right = true;
    }
    Platform::update();
}

////////////////
//Disappearing_Platform
////////////////

//konstruktor
Disappearing_Platform::Disappearing_Platform( float x, float y )
    : Disappearing_Platform( sf::Vector2f(x, y) )
{ }

Disappearing_Platform::Disappearing_Platform(sf::Vector2f pos)
    : Platform("Disappearing_Platform", pos), fade_val{255}
{
    sprite.setTextureRect(white_platform);
}

//funktioner
void Disappearing_Platform::render( sf::RenderTarget & target)
{
    //if(intact)
        Platform::render(target);
}

void Disappearing_Platform::handle_collision( Entity & ent)
{while (!collisionList.empty())
    {
        double acc {ent.getAcceleration()};
        if (collisionList.back() == std::tuple<int, int>{PLAYER_LEGS, PLATFORM_ANY})
        {
	
	        if(acc > 0)
	        {
                if(intact)
                {
                    intact = false;
	                Entity::acceleration = -jump_value;
                    ent.setCollisionSprite();
                    Sounds::jump();
                    check_power();
                }
	        }
        }
        collisionList.pop_back();
    } 
}

void Disappearing_Platform::update()
{
    if(!intact)
    {
        if (fade_val != 0)
        {
            fade_val -= 15;
            sprite.setColor(sf::Color(255, 255, 255, fade_val));
        }
    }
    Platform::update();
}
