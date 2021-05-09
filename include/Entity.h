#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Vector2.hpp>
#include <vector>
#include <string>


class Entity
{
private:
    std::string name {"Entity"};

    double X-axis;
    double Y-axis;
    sf::Vector2<double> acceleration;

    //std::vector<Collision_Box> CollisionContainer
public:

    virtual void render() = 0;
    virtual void handle_collision(Entety) = 0;
    virtual void update() = 0;
    virtual void movement_behavior() = 0;       //? tycker att dena ska vara private och lokal för "läggre" klasser 

}


#endif // ENTITY_H