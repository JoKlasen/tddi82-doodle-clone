#ifndef ENTITY_H
#define ENTITY_H

//#include <SFML/Vector2.hpp>

//#include <System.hpp>

#include <vector>
#include <string>


class Entity
{
private:

protected:
    std::string name {"Entity"};

    sf::Vector2f position;          //sf::Vector2<float>
    sf::Vector2f acceleration;
    //std::vector<Collision_Box> CollisionContainer


public:
    virtual ~Entity () = default;

    virtual void render( sf::RenderTarget & ) = 0;
    virtual void handle_collision( Entity const& ) = 0;
    virtual void update() = 0;
    //virtual void movement_behavior() = 0;       //? tycker att dena ska vara private och lokal för "läggre" klasser 

};


#endif // ENTITY_H