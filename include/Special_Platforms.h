#ifndef SPECIAL_PLATFORMS_H
#define SPECIAL_PLATFORMS_H

#include "Entity.h"
#include "Platform.h"
#include <SFML/Graphics.hpp>

class Extra_Jump_Platform : public Platform
{
public:
    Extra_Jump_Platform();
    Extra_Jump_Platform( float, float );   //position 
    Extra_Jump_Platform( sf::Vector2f );   //position 

private:
    void default_shape() override;
};

class Breaking_Platform : public Platform
{
public:
    Breaking_Platform();
    Breaking_Platform( float, float );   //position 
    Breaking_Platform( sf::Vector2f );   //position 

    void render( sf::RenderTarget & ) override;
    void handle_collision( Entity const& ) override;

private:
    void default_shape() override;
    bool intact{true};
};

class Moving_Platform : public Platform
{
public:
    Moving_Platform();
    Moving_Platform( float, float );   //position 
    Moving_Platform( sf::Vector2f );   //position 

    void update() override;

private:
    void default_shape() override;
    bool moving_right{true};    //Skulle kunna slumpas fram vid initiering, annars kommer alla platformar att alltid börja röra sig åt samma håll
};

#endif //SPECIAL_PLATFORMS_H