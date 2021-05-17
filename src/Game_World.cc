#include "Game_World.h"
#include <SFML/Graphics.hpp>
#include "constants.h"

#include <iostream>
#include <algorithm>
#include <random>


Game_World::Game_World ()
    : score{0}, entities{}, player{}
{
    entities.push_back( std::make_unique<Platform>() );
    entities.push_back( std::make_unique<Platform>(200, 100) );
    entities.push_back( std::make_unique<Platform>(200, 200) );
    entities.push_back( std::make_unique<Platform>(300, 300) );
    entities.push_back( std::make_unique<Platform>(100, 400) );
}

void Game_World::handle_event (sf::Event event)
{
    //player.handle_input();

}

void Game_World::placePlatforms()
{
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(1, 300);

    int dice_roll = distribution(generator);
    // Y-pos , X-pos
    if (entities.size() < 10)
    {

        entities.push_back( std::make_unique<Platform>(dice_roll, 0) );
    }
}


void Game_World::destroyPlatforms()
{
    // Tar bort entetis under skärm 
    std::cout << "entities: " << entities.size()  << "       player_y: " << player.getPosition().y << std::endl;

    auto it = remove_if(entities.begin(), entities.end(), 
                [](auto const& ent ){ return ent->getPosition().y > 400; } );
    entities.erase(it, entities.end()
    );
}



void Game_World::update ()
{
    //Random place new Platforms
    placePlatforms();

    destroyPlatforms();





    // Uppdaterar plats
    // Flytta spelaren i X-led efter knappinput, kör wraparound på kanter om nödvändigt och flyttar sedan spelaren i Y-led enligt acc.
    player.update ();
    for ( auto & ent : entities )
    {
        ent->update ();
    }


    // Flytta ner platform(ar)
    
    if (player.getPosition().y < screen_height/2 - 50)
    {
        player.setPosition(sf::Vector2f (player.getPosition().x, screen_height/2 - 50) );
        
        for (auto & ent : entities)
        {
            // Byt senare ut följande mot for loop för vector<entity>
            ent->move(0, -(ent->getAcceleration()));
        }
    }


    // Kollisionslogik för spelare mot generell entiry
    // TESTFIXASAP; Senare for each platform i vector<entity>
    
    for (auto & ent : entities)
    {
        if (testPlayerCollision( *ent ))
        {
            ent->handle_collision(player);
        }
    }




    // TESTFIXASAP;
    // Kollision med golv för testvärld denna bör bytas ut mot att sätta game_over-flaggan för att spelet ska ta slut, funkar som kollision just nu för att göra test enklare.
    if ( player.getPosition().y >= (screen_height - 30) ) // 30 = player->dimensions.y/2 byt ut mot någon form av getBounds().height/2
        player.setAcceleration(-10);
}

void Game_World::render (sf::RenderTarget & target)
{
    for ( auto & ent : entities )
    {
        ent->render (target);
    }
    player.render (target);
}



bool Game_World::testPlayerCollision (Entity const & obj)
{   
    // TESTFIXASAP; 60, 60, 70 och 20 representerar här spelarens hårdkodade width och height, platformens bredd respektive platformens höjd. Bör bytas ut mot getBounds eller liknande för generella entities
    /*auto player_rect = player.getGlobalBounds() ;
    std::cout << "player_rect.top: " << player_rect.top << std::endl;
    player_rect.top -=  20;
    auto obj_rect    = obj.getGlobalBounds() ;
    if (player_rect.intersects(obj_rect) ) //*/

    if ((player.getPosition().x + player.getGlobalBounds().width > obj.getPosition().x) &&
    (player.getPosition().x < obj.getPosition().x + obj.getGlobalBounds().width) &&
    (player.getPosition().y + player.getGlobalBounds().height >= obj.getPosition().y) &&
    (player.getPosition().y + player.getGlobalBounds().height < obj.getPosition().y + obj.getGlobalBounds().height) &&
    (player.getAcceleration() > 0) ) 
    {
        //std::cout << "CRASH" << std::endl <<"player_rect.top: " << player_rect.top << std::endl;
        return true;
    }
    else
    {
        return false;
    }
}







