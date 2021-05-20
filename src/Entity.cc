#include "Entity.h"

// Konstruktorer

double Entity::acceleration = 0;

Entity::Entity()
    : collisionList{}, name{"bertil"}, sprite{}, position{}, CollisionContainer{}
{

}

Entity::Entity( std::string pname,
                //sf::Texture ptexture,
                //sf::IntRect psubtexture,
                sf::Vector2f pposition,        
                std::vector<sf::Rect<float>> pCollisionContainer )
    : collisionList{}, name{pname}, sprite{}, position{pposition}, CollisionContainer{pCollisionContainer}
    {
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
    return getGlobalBounds();
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
    return this->position;
}

void Entity::setPosition(sf::Vector2f value)
{
    this->position.x = value.x;
    this->position.y = value.y;
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
    this->position.x += value.x;
    this->position.y += value.y;
}

void Entity::move(float const & offsetX, float const & offsetY)
{
    this->position.x += offsetX;
    this->position.y += offsetY;
}
