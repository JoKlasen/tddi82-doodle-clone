#include "Game_World.h"
#include <SFML/Graphics.hpp>
#include "constants.h"


Game_World::Game_World ()
    : score{0}, entities{}, player{}
{
    entities.push_back( std::make_unique<Platform>() );
    entities.push_back( std::make_unique<Platform>(200, 100) );
    entities.push_back( std::make_unique<Platform>(200, 150) );
}

void Game_World::handle_event (sf::Event event)
{
    //player.handle_input();

}

void Game_World::update ()
{
    // Uppdaterar plats
    // Flytta spelaren i X-led efter knappinput, kör wraparound på kanter om nödvändigt och flyttar sedan spelaren i Y-led enligt acc.
    player.update ();
    for ( auto & ent : entities )
    {
        ent->update ();
    }

    // Tar bort entetis under skärm 
    /*
    entities.erase(
        remove(entities.begin(), entities.end(), 
            [](Entity const& ent){
                return ent.getPosition().x < 0; 
            } ), 
        entities.end()
    );
    //*/


    // Flytta ner platform(ar)
    for (auto & ent : entities)
    {
        if (ent->getPosition().y < screen_height/2 - 50)
        {
            ent->setPosition(sf::Vector2f (ent->getPosition().x, screen_height/2 - 50) );
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
    if ( (player.getPosition().x + 60 > obj.getPosition().x) && (player.getPosition().x < obj.getPosition().x + 70) 
         && (player.getPosition().y + 60 >= obj.getPosition().y) && (player.getPosition().y + 60 < obj.getPosition().y + 20)
         && (player.getAcceleration() > 0) )
        {
            return true;
        }
    else
        {
            return false;
        }
}