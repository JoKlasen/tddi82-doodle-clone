#ifndef ENTITY_H
#define ENTITY_H

//#include <SFML/Vector2.hpp>

//#include <System.hpp>

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>


class Entity
{
public:
    virtual ~Entity () = default;
    Entity();
    Entity(std::string pname,
    sf::Vector2f pposition,        
    sf::Vector2f pacceleration,
    std::vector<int> pCollisionContainer );

    virtual void render( sf::RenderTarget & ) = 0;
    virtual void handle_collision( Entity const& ) = 0;
    virtual void update() = 0;
    //virtual void movement_behavior() = 0;       //? tycker att dena ska vara private och lokal för "läggre" klasser 

protected:
    std::string name;
    sf::Vector2f position;          //sf::Vector2<float>
    sf::Vector2f acceleration;
    std::vector<int> CollisionContainer; // ska vara collision box

};


#endif // ENTITY_H