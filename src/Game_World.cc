#include "Game_World.h"
#include <SFML/Graphics.hpp>
#include "constants.h"
#include "Manager.h"
#include <iostream>
#include <algorithm>
#include <random>

Game_World::Game_World ()
    : score{0}, entities{}, player{}, //platform{ 150, 630 }, platform2{0, 630},//platform{ sf::Vector2f(50, 50) }
      scoreBar{sf::Vector2f(screen_width, 40)}, scoreText{}, ScoreBarFill{Texture_Manager::load("./resources/images/testbar3.png")}
{
    // Initiera poängräknare-del
    scoreBar.setPosition(0,0);
    scoreBar.setFillColor(sf::Color(128, 128, 128, 128)); // Genomskinlig grå färg

    ScoreBarFill.setPosition(0, 35);

    scoreText.setFont(Font_Manager::load(font_file));
    scoreText.setString("Score: 0");
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setCharacterSize(30);
    scoreText.setPosition(10,3);
    scoreText.setStyle(sf::Text::Bold);

    // Initera platformar
    entities.push_back( std::make_unique<Platform>() );
    entities.push_back( std::make_unique<Moving_Platform>(200, 100) );
    entities.push_back( std::make_unique<Breaking_Platform>(200, 200) );
    entities.push_back( std::make_unique<Extra_Jump_Platform>(300, 300) );
    entities.push_back( std::make_unique<Platform>(100, 400) );
    entities.push_back( std::make_unique<Platform>(100, 500) );
    entities.push_back( std::make_unique<Platform>(100, 600) );
    entities.push_back( std::make_unique<Platform>(100, 700) );
}

void Game_World::handle_event (sf::Event)
{

}

void Game_World::placePlatforms()
{
    int spawn_distance {50};
    int spawn_y_pos {0};

    std::random_device generator;
    std::uniform_int_distribution<int> pos_distribution(1, 300);
    std::uniform_int_distribution<int> spawn_distribution(1, 4);

    /*
    std::cout << "entities: " << entities.size()  
              << "       player_y: " << player.getPosition().y 
              << "       Last Entity:" << entities.back()->getPosition().y << std::endl;
    */

    if ( entities.back()->getPosition().y > spawn_distance)
    {
        int dice_x_roll   = pos_distribution(generator);
        int spawn_type  = spawn_distribution(generator);

        if (spawn_type == 1)
            entities.push_back( std::make_unique<Platform>(dice_x_roll, spawn_y_pos) );
        if (spawn_type == 2)
            entities.push_back( std::make_unique<Moving_Platform>(dice_x_roll, spawn_y_pos) );
        if (spawn_type == 3)
            entities.push_back( std::make_unique<Breaking_Platform>(dice_x_roll, spawn_y_pos) );
        if (spawn_type == 4)
            entities.push_back( std::make_unique<Extra_Jump_Platform>(dice_x_roll, spawn_y_pos) );
    }
    /*
    if (entities.size() < 10)
    {
        //int spawn_type  = spawn_distribution(generator);
        //if (spawn_type == 1)
        entities.push_back( std::make_unique<Platform>(dice_roll, spawn_y_pos) );
    } //*/
}


void Game_World::destroyPlatforms()
{
    int destroy_y_line {screen_height};

    // Tar bort entetis under skärm 
    auto it = remove_if(entities.begin(), entities.end(), 
                [destroy_y_line](auto const& ent ){ return ent->getPosition().y > destroy_y_line; } );
    entities.erase(it, entities.end()
    );
}

void Game_World::updateEntities()
{
    for ( auto & ent : entities )
    {
        ent->update ();
    }
}

void Game_World::update ()
{
    //Random place new Platforms
    placePlatforms();
    //Destroy Platforms under screen
    destroyPlatforms();


    // Uppdaterar plats
    // Flytta spelaren i X-led efter knappinput, kör wraparound på kanter om nödvändigt och flyttar sedan spelaren i Y-led enligt acc.
    player.update ();
    updateEntities();


    // Flytta ner platform(ar) och räkna poäng
    if (player.getPosition().y < screen_height/2 - 50)
    {
        player.setPosition(sf::Vector2f (player.getPosition().x, screen_height/2 - 50) );
        score += -(player.getAcceleration())*10;
        scoreText.setString("Score: " + std::to_string(score/10));
        //std::cout << score/10 << std::endl;        // debugg

        for (auto & ent : entities)
        {
            ent->move(0, -(ent->getAcceleration()));
        }

    }


    // Kollisionslogik för spelare mot generell entiry
    for (auto & ent : entities)
    {
        if (testPlayerCollision( *ent ))
        {
            testCollisionContainer(player,*ent);
            ent->handle_collision(player);
            player->handle_collision(*ent);
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
   

    player.render(target);

    target.draw(scoreBar);
    //target.draw(ScoreBarFill);
    target.draw(scoreText);
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
