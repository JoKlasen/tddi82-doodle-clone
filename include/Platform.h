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
    
    
    void render( sf::RenderTarget & ) override;
    void handle_collision( Entity const& ) override;
    void update() override;

    sf::FloatRect getGlobalBounds() const override; //tillfälig

private:
    void default_shape();


    sf::RectangleShape shape{ sf::Vector2f(50, 10) };

    double jump_value {7.5};
};

#endif