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
    Platform(std::string name, sf::Vector2f position= sf::Vector2f(), std::vector<int> CollisionContainer = std::vector<int>{});
    
    void render( sf::RenderTarget & ) override;
    void handle_collision( Entity const& ) override;
    void update() override;

private:
    void make_power_up(std::unique_ptr<Power_Up> & );
    void default_shape();
    sf::RectangleShape shape{ sf::Vector2f(75, 20) };
    std::unique_ptr<Power_Up> power_up;
    bool has_power_up;
    
};

#endif