#ifndef PLATFORM_H
#define PLATFORM_H

#include "Entity.h"
#include <SFML/Graphics.hpp>


class Platform : public Entity
{
public:

    Platform();
    Platform( float, float );
    Platform( sf::Vector2f );
    Platform(std::string name, sf::Vector2f position= sf::Vector2f(), std::vector<int> CollisionContainer = std::vector<int>{});
    
    void render( sf::RenderTarget & ) override;
    void handle_collision( Entity const& ) override;
    void update() override;

private:
    void default_shape();


    sf::RectangleShape shape{ sf::Vector2f(75, 20) };

};

#endif