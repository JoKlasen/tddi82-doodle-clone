#ifndef PLAYER_H
#define PLATER_H

#include "Entity.h"
#include <SFML/Graphics.hpp>


class Player : public Entity
{
public:
    Player();
    
    void render( sf::RenderTarget & target) override;
    void handle_collision( Entity & ) override;
    void update() override;

    void handle_input();

    sf::Rect<float> getGlobalBounds() override;
    sf::FloatRect getGlobalBounds() const override; //tillfälig

    void setCollisionSprite() override;

private:
    // Datamedlemmar
    int life;
    bool facing_right{true};

    // Interna funktioner
    void initCollisionContainer();
};


#endif
