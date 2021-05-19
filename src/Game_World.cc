#include "Game_World.h"
#include <SFML/Graphics.hpp>
#include "constants.h"
#include <iostream>


Game_World::Game_World ()
    : score{0}, entities{}, player{}, platform{ 150, 660 }//platform{ sf::Vector2f(50, 50) }
{
    //entities.push_back( Platform {} );
}

void Game_World::handle_event (sf::Event event)
{
    //player.handle_input();

}

void Game_World::update ()
{
    // Flytta spelaren i X-led efter knappinput, kör wraparound på kanter om nödvändigt och flyttar sedan spelaren i Y-led enligt acc.
    player.update ();

    // Flytta ner platform(ar)
    if (player.getPosition().y < screen_height/2 - 50)
        {
            player.setPosition(sf::Vector2f (player.getPosition().x, screen_height/2 - 50) );
            // Byt senare ut följande mot for loop för vector<entity>
            platform.move(0, -(player.getAcceleration()));
            
        }


    // Kollisionslogik för spelare mot generell entiry
    // TESTFIXASAP; Senare for each platform i vector<entity>
    if (testCollision(player,platform))
        {
	    testCollisionContainer(player,platform);
            player.handle_collision(platform);
            platform.handle_collision(player);
        }

    platform.update();
    // for ( auto & ent : entities )
    // {
    //     ent.update ();
    // }

    // TESTFIXASAP;
    // Kollision med golv för testvärld denna bör bytas ut mot att sätta game_over-flaggan för att spelet ska ta slut, funkar som kollision just nu för att göra test enklare.
    if ( player.getPosition().y >= (screen_height - 30) ) // 30 = player->dimensions.y/2 byt ut mot någon form av getBounds().height/2
        player.setAcceleration(-10);
}

void Game_World::render (sf::RenderTarget & target)
{
    // for ( auto & ent : entities )
    // {
    //     ent.render (target);
    platform.render(target);
    // }
    

    player.render (target);
}

void Game_World::testCollisionContainer (Entity & obj1,Entity & obj2)
{   
    int i = 0;
    for (auto box1 : obj1.getCollisionContainer())
    {
        int j = 0;
        box1.left += obj1.getGlobalBounds().left;
        box1.top += obj1.getGlobalBounds().top;
        for (auto box2 : obj2.getCollisionContainer())
        {
	        box2.left += obj2.getGlobalBounds().left;
	        box2.top += obj2.getGlobalBounds().top;
	        if (box1.intersects(box2))
	        {
	            //std::cout << i <<" "<< j << std::endl;
	            obj1.colitionList.push_back(std::tuple<int, int>{i, j});
	            obj2.colitionList.push_back(std::tuple<int, int>{i, j});
	        }
	        j++;
        }
        i++;
    }
    //std::cout << std::endl;
}

bool Game_World::testCollision (Entity & obj1,Entity & obj2)
{   
    if(obj1.getGlobalBounds().intersects(obj2.getGlobalBounds()))
    {
        return true;
    }
    return false;
}

bool Game_World::testPlayerCollision (Entity & obj)
{   
    if(player.getGlobalBounds().intersects(obj.getGlobalBounds()))
    {
        return true;
    }
  return false;
        
}
