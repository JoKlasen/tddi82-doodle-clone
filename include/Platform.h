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
    Platform(std::string name, sf::Vector2f position= sf::Vector2f(), std::vector<sf::Rect< float >> CollisionContainer = std::vector<sf::Rect< float >>{});
    
    void render( sf::RenderTarget & ) override;
    void handle_collision( Entity & ) override;
    void update() override;
    
    sf::Rect< float > getGlobalBounds() override;

    sf::FloatRect getGlobalBounds() const override; //tillfälig

protected:
    virtual void default_shape();

    double jump_value{10.0};
    sf::Sprite shape; 
    //sf::RectangleShape shape{ sf::Vector2f(75, 20) };

};

#endif
