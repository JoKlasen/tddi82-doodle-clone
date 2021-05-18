#ifndef GAME_WORLD_H
#define GAME_WORLD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Entity.h"
#include "Platform.h"
#include "Special_Platforms.h"
#include "Player.h"

class Game_World
{
public:
    Game_World ();

    void handle_event (sf::Event); 
    void update ();
    void render (sf::RenderTarget & target);
    

private:
    int score;
    std::vector< std::unique_ptr<Entity> > entities;
    Player player;

    //Platform platform; //Debug
    //Disappearing_Platform platform2;

    sf::RectangleShape scoreBar;
    sf::Text scoreText;
    sf::Sprite ScoreBarFill;

    void placePlatforms();
    void destroyPlatforms();
    void updateEntities();
    

    bool testPlayerCollision (Entity const & obj);
};

#endif