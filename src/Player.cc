#include "Entity.h"
#include "Player.h"
#include "constants.h"
#include <vector>
#include <iostream>

Player::Player()
    : Entity{ "Player", sf::Vector2f{}, std::vector<sf::Rect< float >>{} }, life {3}
    {
        sprite.setTexture(Texture_Manager::load(spritesheet_file));
        sprite.setTextureRect(player_right);

        sprite.setPosition( (screen_width/2 - sprite.getGlobalBounds().width/2), (screen_height/2 - sprite.getGlobalBounds().height/2) );
        
        //sprite.setScale(0.75, 0.75);
        
        initCollisionContainer();
    }
    

////////////////
// Public functions
////////////////

void Player::render( sf::RenderTarget & target)
{
    target.draw(sprite);
}


void Player::handle_collision( Entity & ent)
{
    while (!collisionList.empty())
    {
        collisionList.pop_back();
    }
}


void Player::update()
{
    handle_input();

    // Hopp/fall
    Entity::acceleration += 0.2;    // Öka fallhastighet
    sprite.move(0, Entity::acceleration);
    if (Entity::acceleration >= 0)  // Om "studsande" sprite, byt till "vanlig"
    {
        if (facing_right)
        {   
            sprite.setTextureRect(player_right);
        }
        else
        {
            sprite.setTextureRect(player_left);
        }
    }
    

}


void Player::handle_input()
{
    // Flytta spelaren vid knappar
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {   
        if (facing_right)
        {   
            facing_right = false;
        }
        if (acceleration < 0)
            setCollisionSprite();
        else
            sprite.setTextureRect(player_left);
        move(sf::Vector2f(-4, 0));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {   
        if (!facing_right)
        {
            facing_right = true;
        }
        if (acceleration < 0)
            setCollisionSprite();
        else
            sprite.setTextureRect(player_right);
        move(sf::Vector2f(4, 0));
    }

    // wrap around
    if ( getPosition().x + getGlobalBounds().width/2 > screen_width )
        setPosition(-(getGlobalBounds().width/2) , getPosition().y);
    else if ( getPosition().x < (0 - getGlobalBounds().width/2) )
        setPosition( (screen_width - getGlobalBounds().width/2) , getPosition().y);
}


sf::Rect<float> Player::getGlobalBounds()
{
    return sprite.getGlobalBounds();
}

sf::FloatRect Player::getGlobalBounds() const
{
    return sprite.getGlobalBounds() ;
}

// bool Player::isFacingRight()
// {
//     return facing_right;
// }

void Player::setCollisionSprite()
{
    if (facing_right)
        sprite.setTextureRect(player_right_landing);
    else
        sprite.setTextureRect(player_left_landing);
}

////////////////
// Private functions
////////////////

void Player::initCollisionContainer()
{
    auto box = sprite.getLocalBounds();
    box.width = box.width * sprite.getScale().x;
    box.height = box.height * sprite.getScale().y;
    CollisionContainer.push_back(sprite.getLocalBounds()); //might become an issue
    
    CollisionContainer.push_back(player_legs_box);
    CollisionContainer.push_back(player_body_box);
}