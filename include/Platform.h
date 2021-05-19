#ifndef PLATFORM_H
#define PLATFORM_H

#include "Entity.h"
#include <SFML/Graphics.hpp>
#include "Manager.h"
#include "Power_Up.h"
#include <memory>


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
    void make_power_up(std::unique_ptr<Power_Up> & );
    double jump_value{10.0};
    sf::Sprite shape; 
    bool has_power_up;
    std::unique_ptr<Power_Up> power_up;
    //sf::RectangleShape shape{ sf::Vector2f(75, 20) };

};

#endif
