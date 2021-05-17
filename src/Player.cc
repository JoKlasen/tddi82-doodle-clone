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
    // wrap around
    if ( this->position.x >= screen_width )
        this->position.x = 0;
    if ( this->position.x <= (0 - this->dimensions.x ) )
        this->position.x = (screen_width - this->dimensions.x );

    Entity::acceleration += 0.2;    // Öka fallhastighet

    this->position.y += Entity::acceleration;

    if ( this->position.y >= (screen_height - this->dimensions.y/2) )
        Entity::acceleration = -10;

    

}

void Player::move(sf::Vector2f const & value)
{
    this->position.x += value.x;
    this->position.y += value.y;
}