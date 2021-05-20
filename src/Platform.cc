#include "Platform.h"
#include "Entity.h"
#include "constants.h"
#include <SFML/Graphics.hpp>

#include <vector>
#include <string>

#include <iostream> //debug

//Sounds sounds;

//konstruktor
Platform::Platform( float x, float y )
    : Platform("Platform", sf::Vector2f(x, y) )
{ }

Platform::Platform(std::string pname, sf::Vector2f pposition, std::vector<sf::Rect<float>> pCollisionContainer)
    : Entity{pname, pposition, pCollisionContainer}//, sprite{Texture_Manager::load(spritesheet_file), green_platform}
{ 
    sprite.setTexture(Texture_Manager::load(spritesheet_file));
    sprite.setTextureRect(green_platform);
    sprite.setScale(0.75, 0.75);
    auto box = sprite.getLocalBounds();
    box.width = box.width * sprite.getScale().x;
    box.height = box.height * sprite.getScale().y;
    CollisionContainer.push_back(box); //might become an issue
}

void Platform::render(sf::RenderTarget & target)
{
    target.draw(sprite);
}

void Platform::update() 
{
    
}

void Platform::handle_collision( Entity & ent)
{
    while (!collisionList.empty())
    {
        double acc {ent.getAcceleration()};
        if (collisionList.back() == std::tuple<int, int>{PLAYER_LEGS, PLATFORM_ANY})
        {
	
	        if(acc > 0)
	        {
	            Entity::acceleration = -jump_value;
                ent.setCollisionSprite();
                Sounds::jump();
	        }
        }
	/*
        else if (collisionList.back() == std::tuple<int, int>{PLAYER_HEAD, PLATFORM_ANY})
        {
	        if(acc < 0)
	        {
	            Entity::acceleration = 0;
	        }
        }
	*/
        collisionList.pop_back();
    } 
}


sf::Rect< float > Platform::getGlobalBounds()
{
    return sprite.getGlobalBounds();
}

sf::FloatRect Platform::getGlobalBounds() const
{
    return sprite.getGlobalBounds();
}
