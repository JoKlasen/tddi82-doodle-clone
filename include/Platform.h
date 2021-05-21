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
    Platform( float, float );   //position 
    Platform(   std::string name = std::string{"Platform"},
                sf::Vector2f position = sf::Vector2f(), 
                std::vector<sf::Rect<float>> CollisionContainer = std::vector<sf::Rect<float>>{} );
    
    void render( sf::RenderTarget & ) override;
    void handle_collision( Entity & ) override;
    void update() override;
    
    sf::Rect<float> getGlobalBounds() override;
    sf::FloatRect getGlobalBounds() const override; //tillfälig
protected:
    void check_power();
    void make_power_up(std::unique_ptr<Power_Up> & );
    bool has_power_up;
    std::unique_ptr<Power_Up> power_up;
    double jump_value{10.0};

};

#endif
