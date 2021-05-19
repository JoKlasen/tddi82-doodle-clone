#ifndef PLATFORM_H
#define PLATFORM_H

#include "Entity.h"
#include <SFML/Graphics.hpp>


class Platform : public Entity
{
public:

    Platform();
    Platform( float, float );   //position 
    Platform( sf::Vector2f );   //position, dom övre konstruktorerna använder sig av denna, gör ändringar här 
    Platform(std::string name, sf::Vector2f position= sf::Vector2f(), std::vector<int> CollisionContainer = std::vector<int>{});
    
    
    virtual void render( sf::RenderTarget & ) override;
    virtual void handle_collision( Entity const& ) override;
    virtual void update() override;

    sf::FloatRect getGlobalBounds() const override; //tillfälig

protected:
    double jump_value{10.0};
    sf::Sprite shape; 

};

#endif