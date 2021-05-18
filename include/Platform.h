#ifndef PLATFORM_H
#define PLATFORM_H

#include "Entity.h"
#include <SFML/Graphics.hpp>


class Platform : public Entity
{
public:

    Platform();
    Platform( float, float );   //position 
    Platform( sf::Vector2f );   //position 
    Platform(std::string name, sf::Vector2f position= sf::Vector2f(), std::vector<int> CollisionContainer = std::vector<int>{});
    
    virtual void render( sf::RenderTarget & ) override;
    virtual void handle_collision( Entity const& ) override;
    virtual void update() override;

protected:
    virtual void default_shape();

    double jump_value{7.6};
    sf::Sprite shape; 
    //sf::RectangleShape shape{ sf::Vector2f(75, 20) };

};

#endif