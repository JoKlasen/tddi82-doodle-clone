#ifndef SPECIAL_PLATFORMS_H
#define SPECIAL_PLATFORMS_H

#include "Entity.h"
#include "Platform.h"
#include <SFML/Graphics.hpp>

class Extra_Jump_Platform : public Platform
{
public:
    Extra_Jump_Platform( float, float );   //position 
    Extra_Jump_Platform( sf::Vector2f pos = sf::Vector2f{} );   //position

private:

};


class Breaking_Platform : public Platform
{
public:
    Breaking_Platform( float, float );   //position 
    Breaking_Platform( sf::Vector2f pos = sf::Vector2f{} );   //position 

    void handle_collision( Entity & ) override;
    void update() override;

private:
    bool intact{true};
    float fall_speed;
};


class Moving_Platform : public Platform
{
public:
    Moving_Platform( float, float );   //position 
    Moving_Platform( sf::Vector2f pos = sf::Vector2f{} );   //position 

    void update() override;

private:
    bool moving_right{true};    //Skulle kunna slumpas fram vid initiering, annars kommer alla platformar att alltid börja röra sig åt samma håll
};


class Disappearing_Platform : public Platform
{
public:
    Disappearing_Platform( float, float );   //position 
    Disappearing_Platform( sf::Vector2f pos = sf::Vector2f{} );   //position

    void render( sf::RenderTarget & ) override;
    void handle_collision( Entity & ) override;
    void update() override;

private:
    bool intact{true};
    int fade_val;
};

#endif //SPECIAL_PLATFORMS_H