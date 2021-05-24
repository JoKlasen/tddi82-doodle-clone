#ifndef THREAT_H
#define THREAT_H
#include "Entity.h"




class Threat: public Entity
{

public:
    Threat();
    Threat(sf::Vector2f pposition);

    virtual void render( sf::RenderTarget & ) override;
    virtual void handle_collision( Entity & ) override;
    virtual void update() override;
    
    // Getters och setters
    sf::Rect<float> getGlobalBounds() override;
    sf::FloatRect getGlobalBounds() const override; 
    bool isHit();
    int get_damage();

protected:
    sf::IntRect rect;
    sf::Clock clock;
    unsigned damage;
    int monster_speed;
    bool moving_right;
    int countdown;
    bool hit;
    bool hitPlayer;
    sf::Sprite monstershift;
};

class MonsterBlue: public Threat
{
public:
    MonsterBlue(sf::Vector2f pposition);
private:
};

class MonsterRed: public Threat
{
public:
    MonsterRed(sf::Vector2f pposition);
private:
};


#endif