#ifndef GAME_WORLD_H
#define GAME_WORLD_H

#include <SFML/Graphics.hpp>
#include <vector>
//#include "Entity.h"

class Game_World
{
public:
    Game_World ();

    void handle_event (sf::Event event); 
    void update ();
    void render (sf::RenderTarget & target);
    

private:
    sf::CircleShape playershape{30, 3};
    int score;
    //std::vector<Entity> entities;
    //Player player;
};

#endif