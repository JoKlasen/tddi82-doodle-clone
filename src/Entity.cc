#include "Entity.h"


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
