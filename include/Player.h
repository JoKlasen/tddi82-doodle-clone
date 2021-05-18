#ifndef PLAYER_H
#define PLATER_H

#include "Entity.h"
#include <SFML/Graphics.hpp>


class Player : public Entity
{
public:

    Player();
    
    void render( sf::RenderTarget & target) override;
    void handle_collision( Entity const& ) override;
    void update() override;

    void handle_input();


private:
    int life;
    sf::Vector2f dimensions{};      // Width, Height
    sf::CircleShape playershape{30, 3};
};


#endif