#include "Platform.h"
#include "Entity.h"
#include "constants.h"
#include <SFML/Graphics.hpp>
#include <random>
#include <vector>
#include <string>

#include <iostream> //debug

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
    //std::cout << "Platform::render()" << std::endl;   //debug
    power_up->render(target);
    target.draw(sprite);
}

void Platform::update() 
{
    sf::Vector2f pos {CollisionContainer.at(0).left, CollisionContainer.at(0).top};
    power_up->set_pos(pos);
    
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
