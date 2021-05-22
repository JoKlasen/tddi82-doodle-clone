#include "Platform.h"
#include "Entity.h"
#include "Player.h"
#include "constants.h"
#include <SFML/Graphics.hpp>
#include <random>
#include <vector>
#include <string>

#include <iostream> //debug

void Platform::make_power_up(std::unique_ptr<Power_Up> & pwup) // ändra här för hur ofta power_ups ska spawna
{
    std::random_device rd;
    std::uniform_int_distribution<int> distrib(1, 100);
    std::mt19937 gen(rd());
    int rand = distrib(gen);
    //std::cout << rand << std::endl;
    if(rand < 5)
    {
        pwup = std::make_unique<Spring>();
        has_power_up = true;
    }
    else if(rand >= 5 && rand < 10)
    {
        pwup = std::make_unique<Shield>();
        has_power_up = true;
    }
    else if(rand >= 10 && rand < 15)
    {
        pwup = std::make_unique<Extra_Life>();
        has_power_up = true;
    }
    else if(rand == 100 ) // rand =100
    {
        pwup = std::make_unique<Jetpack>();
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
    : Entity{pname, pposition, pCollisionContainer}, power_up{nullptr}, has_power_up{false}//, sprite{Texture_Manager::load(spritesheet_file), green_platform}
{ 
    sprite.setTexture(Texture_Manager::load(spritesheet_file));
    sprite.setTextureRect(green_platform);
    sprite.setScale(0.75, 0.75);
    auto box = sprite.getLocalBounds();
    box.width = box.width * sprite.getScale().x;
    box.height = box.height * sprite.getScale().y;
    CollisionContainer.push_back(box); //might become an issue

    // making powerup
    make_power_up(power_up);
}

void Platform::render(sf::RenderTarget & target)
{
    //std::cout << "Platform::render()" << std::endl;   //debug
   
    target.draw(sprite);
   
    power_up->render(target);   
}

void Platform::update() 
{
    sf::Vector2f pos {CollisionContainer.at(0).left, CollisionContainer.at(0).top};
    power_up->set_pos(getPosition());
    
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
                check_power();
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


// protected
void Platform::check_power()
{
    if(has_power_up)
    {
        Player::set_power(power_up->get_effect());
        power_up->set_active(false);
        has_power_up = false;
    }
}