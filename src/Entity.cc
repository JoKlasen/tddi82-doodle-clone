#include "Entity.h"

// Construktorer

Entity::Entity()
    : name{"bertil"}, position{}, acceleration{}, CollisionContainer{}
{

}

Entity::Entity(std::string pname,
    sf::Vector2f pposition,        
    sf::Vector2f pacceleration,
    std::vector<int> pCollisionContainer )
        : name{pname}, position{pposition}, acceleration{pacceleration}, CollisionContainer{pCollisionContainer}
    {

    }

// Getters och setters

std::string getName() const
{
    return this->name;
}

void setName(std::string value)
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