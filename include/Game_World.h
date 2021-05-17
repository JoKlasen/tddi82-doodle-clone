#ifndef GAME_WORLD_H
#define GAME_WORLD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Entity.h"
#include "Platform.h"
#include "Player.h"

class Game_World
{
public:
    Game_World ();

    void handle_event (sf::Event event); 
    void update ();
    void render (sf::RenderTarget & target);
    

private:
    int score;
    std::vector< std::unique_ptr<Entity> > entities;
    Player player;


    void placePlatforms();
    void destroyPlatforms();

    bool testPlayerCollision (Entity const & obj);
};

#endif