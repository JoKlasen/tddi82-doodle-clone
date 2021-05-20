#include "Entity.h"
#include "Player.h"
#include "constants.h"
#include <vector>
#include <iostream>

Player::Player()
    : Entity{ "Player", sf::Vector2f{}, std::vector<sf::Rect< float >>{} }, life {3}, dimensions{60, 60}//, 
      //sprite{Texture_Manager::load(spritesheet_file), player_right}
    {
        sprite.setTexture(Texture_Manager::load(spritesheet_file));
        sprite.setTextureRect(player_right);
        this->position.x = (screen_width/2 - this->dimensions.x/2);
        this->position.y = (screen_height/2 - this->dimensions.y/2);
        
        std::cout << "Innan scale: LocalBounds= " << sprite.getLocalBounds().width << ", " << sprite.getLocalBounds().height <<
        " GlobalBounds= " << sprite.getGlobalBounds().width << ", " << sprite.getGlobalBounds().height << std::endl;

        //sprite.setScale(0.75, 0.75);
        
        std::cout << "Efter scale: LocalBounds= " << sprite.getLocalBounds().width << ", " << sprite.getLocalBounds().height <<
        " GlobalBounds= " << sprite.getGlobalBounds().width << ", " << sprite.getGlobalBounds().height << std::endl;

        initCollisionContainer();
    }
    

////////////////
// Public functions
////////////////

void Player::render( sf::RenderTarget & target)
{
    sprite.setPosition( this->getPosition() );
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
    this->position.y += Entity::acceleration;
}


void Player::handle_input()
{
    // Flytta spelaren vid knappar
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        sprite.setTextureRect(player_left);
        move(sf::Vector2f(-4, 0));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        sprite.setTextureRect(player_right);
        move(sf::Vector2f(4, 0));
    }

    // wrap around
    if ( this->position.x + dimensions.x/2 > screen_width )
        this->position.x = -(dimensions.x/2);
    else if ( this->position.x < (0 - this->dimensions.x/2 ) )
        this->position.x = (screen_width - this->dimensions.x/2 );
}


sf::Rect<float> Player::getGlobalBounds()
{
    return sprite.getGlobalBounds();
}

sf::FloatRect Player::getGlobalBounds() const
{
    return sprite.getGlobalBounds() ;
}

////////////////
// Private functions
////////////////

void Player::initCollisionContainer()
{
    CollisionContainer.push_back(sprite.getLocalBounds()); //might become an issue
    
    CollisionContainer.push_back(player_legs_box);
    CollisionContainer.push_back(player_body_box);

    // auto height {sprite.getLocalBounds ().height};
    
    // auto collisionRightbox {sprite.getLocalBounds ()};
    // collisionRightbox.left      = 30;
    // collisionRightbox.top       = height-15;
    // collisionRightbox.height    = 15;
    // collisionRightbox.width     = 50;

    // CollisionContainer.push_back(collisionRightbox);
    
    // auto collisionLeftbox {sprite.getLocalBounds ()};
    // collisionLeftbox.height     = height/2;
    // collisionLeftbox.left       = 30;
    // collisionLeftbox.width      = 50;

    // CollisionContainer.push_back(collisionLeftbox);
}