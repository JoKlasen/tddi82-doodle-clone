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
    int get_life();
    static void set_power(std::vector<int>);


private:
    // Datamedlemmar
    static std::vector<int> power_vec;
    int life;
    bool facing_right{true};
    bool shield;
    bool jetpack;
    sf::Sprite power_sprite;
    sf::CircleShape shield_shape;
    int fade;

    sf::Clock clock;

    // Interna funktioner
    void initCollisionContainer();
    
    void update_power_effect();
    void drawShield(sf::RenderTarget & target);
    void drawJetpack(sf::RenderTarget & target);
};


#endif
