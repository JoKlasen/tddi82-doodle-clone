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
    // Datamedlemmar
    int score;
    std::vector< std::unique_ptr<Entity> > entities;
    Player player;

    sf::RectangleShape scoreBar;
    sf::Text scoreText;
    sf::Sprite scoreBarEdge;

    // Platforms-hantering
    void initPlatforms();
    void placePlatforms();
    void destroyPlatforms();
    void updateEntities();
    
    // Kollisions-hantering
    void testCollisionContainer (Entity & obj1,Entity & obj2);
    bool testCollision (Entity & obj1,Entity & obj2);
    bool testPlayerCollision (Entity & obj);

    // Övrigt
    void initScore ();
};

#endif
