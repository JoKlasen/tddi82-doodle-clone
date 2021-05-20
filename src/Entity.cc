#include "Entity.h"

// Konstruktorer

double Entity::acceleration = 0;

Entity::Entity()
    : collisionList{}, name{"bertil"}, sprite{}, CollisionContainer{}
{

}

Entity::Entity( std::string pname,
                //sf::Texture ptexture,
                //sf::IntRect psubtexture,
                sf::Vector2f pposition,        
                std::vector<sf::Rect<float>> pCollisionContainer )
    : collisionList{}, name{pname}, sprite{}, CollisionContainer{pCollisionContainer}
    {
        sprite.setPosition(pposition);
        // if ( (psubtexture.width != 0) && (psubtexture.height != 0) )
        //     sprite.setTextureRect(psubtexture);
    }


// Getters och setters
std::vector<sf::Rect<float>> Entity::getCollisionContainer()
{
    return CollisionContainer;
}

sf::FloatRect Entity::getGlobalBounds() const
{
    return sprite.getGlobalBounds();
}

std::string Entity::getName() const
{
    return this->name;
}

void Entity::setName(std::string value)
{
    this->name = value;
}

sf::Vector2f Entity::getPosition() const
{
    return sprite.getPosition();
}

void Entity::setPosition(sf::Vector2f value)
{
    sprite.setPosition(value);
}

void Entity::setPosition(float valueX, float valueY)
{   
    sf::Vector2f value(valueX, valueY);
    sprite.setPosition(value);
}

double Entity::getAcceleration() const
{
    return this->acceleration;
}

void Entity::setAcceleration(double value)
{
    this->acceleration = value;
}

void Entity::move(sf::Vector2f const & value)
{
    sprite.move(value);
}

void Entity::move(float const & offsetX, float const & offsetY)
{
    sf::Vector2f value(offsetX, offsetY);
    sprite.move(value);
}

void Entity::setCollisionSprite()
{
    
}