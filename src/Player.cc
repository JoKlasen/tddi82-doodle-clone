#include "Entity.h"
#include "Player.h"
#include "constants.h"
#include <vector>

Player::Player()
    : Entity{ "Player", sf::Vector2f{}, std::vector<int>{} }, life {3}, dimensions{60, 60}
    {
        this->position.x = (screen_width/2 - this->dimensions.x/2);
        this->position.y = (screen_height/2 - this->dimensions.y/2);
        
        playershape.setFillColor (sf::Color::Blue);
    }


void Player::render( sf::RenderTarget & target)
{
    playershape.setPosition( this->getPosition() );
    target.draw(playershape);
}

void Player::handle_collision( Entity const& )
{

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
        move(sf::Vector2f(-4, 0));
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        move(sf::Vector2f(4, 0));
    
    // wrap around
    if ( this->position.x + dimensions.x/2 > screen_width )
        this->position.x = -(dimensions.x/2);
    else if ( this->position.x < (0 - this->dimensions.x/2 ) )
        this->position.x = (screen_width - this->dimensions.x/2 );
}

sf::FloatRect Player::getGlobalBounds() const
{
    return playershape.getGlobalBounds() ;
}

