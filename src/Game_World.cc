#include "Game_World.h"
#include <SFML/Graphics.hpp>
#include "constants.h"
#include "Manager.h"
#include "UI.h"
#include <iostream>
#include <algorithm>
#include <random>

Game_World::Game_World ()
    : score{0}, entities{}, threats{}, player{},
      scoreBar{sf::Vector2f(screen_width, 40)}, scoreText{}, 
      scoreBarEdge{Texture_Manager::load(spritesheet_file), squiggle}
{
    // Initiera poängräknare-del
    initScore();

    // Initera platformar
    initPlatforms();

    //threats.push_back(MonsterBlue(sf::Vector2f(300, 300)));
    //threats.push_back(MonsterRed(sf::Vector2f(200, 500)));


}

////////////////
// Public functions
////////////////

int Game_World::getLife()
{
    return player.get_life();
}
int Game_World::getScore()
{
    
    return score;
}
bool Game_World::playerFellOut()
{
    return player.playerFellOut();
}

void Game_World::resetAcceleration()
{
    player.resetAcceleration();
}

void Game_World::handle_event (sf::Event)
{

}


void Game_World::update ()
{
    //Random place new Platforms
    placePlatforms();
    placeThreats();
    //Destroy Platforms under screen
    destroyPlatforms();
    destroyThreats();

    // Uppdaterar plats
    // Flytta spelaren i X-led efter knappinput, kör wraparound på kanter om nödvändigt och flyttar sedan spelaren i Y-led enligt acc.
    player.update();
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
         // threats
        for (Threat & ent : threats)
        {
            ent.move(0, -(ent.getAcceleration()));
        }    
    }

    // Kollisionslogik för spelare mot generell entiry
    for (auto & ent : entities)
    {
        if (testPlayerCollision( *ent ))
        {
            testCollisionContainer(player,*ent);
            ent->handle_collision(player);
            player.handle_collision(*ent);
        }
    }
    for (Threat & ent : threats)
    {
        if (testPlayerCollision( ent ))
        {
            testCollisionContainer(player, ent);
            ent.handle_collision(player);
            player.handle_collision(ent);
            if(ent.isHit())
                player.giveDamage(ent.get_damage());
        }
    }

    // TESTFIXASAP;
    // Kollision med golv för testvärld denna bör bytas ut mot att sätta game_over-flaggan för att spelet ska ta slut, funkar som kollision just nu för att göra test enklare.
    //if ( player.getPosition().y >= (screen_height - 30) ) // 30 = player->dimensions.y/2 byt ut mot någon form av getBounds().height/2
    //    player.setAcceleration(-10);

    //Kolla om man trillat av banan
    // if ( player.getPosition().y >= (screen_height - player.getGlobalBounds().height/2) )
    // {

    // }

}


void Game_World::render (sf::RenderTarget & target)
{
    for ( auto & ent : entities )
    {
        ent->render (target);
    }

    //threats
    for ( Threat & ent : threats )
    {
        ent.render (target);
    }

    player.render(target);

    target.draw(scoreBar);
    target.draw(scoreBarEdge);
    target.draw(scoreText);
}


////////////////
// Private functions
////////////////

// Platforms-hantering

void Game_World::initPlatforms()
{   
    //TESTFIX skulle kunna utvecklas till en slumpgenererad uppsättning.
    entities.push_back( std::make_unique<Platform>() );
    entities.push_back( std::make_unique<Moving_Platform>(200, 100) );
    entities.push_back( std::make_unique<Breaking_Platform>(200, 200) );
    entities.push_back( std::make_unique<Platform>(300, 300) ); // extra jump
    entities.push_back( std::make_unique<Platform>(100, 400) );
    entities.push_back( std::make_unique<Platform>(100, 500) );
    entities.push_back( std::make_unique<Platform>(100, 600) );
    entities.push_back( std::make_unique<Platform>(250, 700) );
}


void Game_World::placePlatforms()
{
    int spawn_distance {50};
    int spawn_y_pos {0};

    std::random_device generator;
    std::uniform_int_distribution<int> pos_distribution(1, (screen_width-78));     // 78 = platform.getGlobalBounds().width, men osäker på om det går att använda utan ett permanent platformsobjekt - Johan
    std::uniform_int_distribution<int> spawn_distribution(1, 5);

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
            entities.push_back( std::make_unique<Platform>(dice_x_roll, spawn_y_pos) ); // extra jump
        if (spawn_type == 5)
            entities.push_back( std::make_unique<Disappearing_Platform>(dice_x_roll, spawn_y_pos) );      
    }
    /*
    if (entities.size() < 10)
    {
        //int spawn_type  = spawn_distribution(generator);
        //if (spawn_type == 1)
        entities.push_back( std::make_unique<Platform>(dice_roll, spawn_y_pos) );
    } //*/
}

void Game_World::placeThreats()
{
    int const spawn_distance = 200;
    
    int stage = 0;
   
    if(score > 100000)
    {
        stage = 2000;
    }
    if(score > 200000)
    {
        stage = 4000;
    }
    if(score > 300000)
    {
        stage = 5000;
    }
    if(score > 500000)
    {
        stage = 10000;
    }

    //std::cout << stage << std::endl;

    std::random_device rd;
    std::uniform_int_distribution<int> dist(1, 10100-stage); // 10000
    std::uniform_int_distribution<int> typedist(1, 2);
    std::mt19937 gen(rd());
    int type = typedist(gen);
    int distans = dist(gen);

    int latest_threat; 
    if(threats.size() == 0)
        latest_threat = 300;
    else
        latest_threat = threats.back().getPosition().y;

    if (  latest_threat > spawn_distance)
        {
        if(distans < 10)
        {
            if(type == 1)
            {
                threats.push_back(MonsterBlue(sf::Vector2f(300, -60)));
            }
            else if(type == 2)
            {
                threats.push_back(MonsterRed(sf::Vector2f(300, -60)));
            }
        }
    }
}


void Game_World::destroyPlatforms()
{
    int destroy_y_line {screen_height};

    // Tar bort entities under skärm 
    auto it = remove_if(entities.begin(), entities.end(), 
                [destroy_y_line](auto const& ent ){ return ent->getPosition().y > destroy_y_line; } );
    entities.erase(it, entities.end());
}

void Game_World::destroyThreats()
{
    if(threats.size() == 0)
        return;
    int destroy_y_line {screen_height};
     // Tar bort entities under skärm 
    auto it = std::remove_if(threats.begin(), threats.end(), 
                [destroy_y_line](auto const& ent ){ return ent.getPosition().y > destroy_y_line; } );
    threats.erase(it, threats.end());

    
}

void Game_World::updateEntities()
{
    for ( auto & ent : entities )
    {
        ent->update ();
    }

    for(Threat & ent: threats)
    {
        ent.update();
    }
}


// Kollisions-hantering

void Game_World::testCollisionContainer (Entity & obj1,Entity & obj2)
{   
    // std::cout << "Test Game_World.cc: "<< std::endl; //TESTREMOVEASAP
    // std::cout << obj1.getCollisionContainer().size() << " " <<obj2.getCollisionContainer().size() << std::endl;
    int i = 0;
    for (auto box1 : obj1.getCollisionContainer())
    {
        int j = 0;

        box1.left += obj1.getGlobalBounds().left;
        box1.top += obj1.getGlobalBounds().top;
        //box1.height = box1.height * obj1.getScale().y;        // OBS detta måste göras om det inte hanteras av entitetens konstruktor
        // std::cout << box1.left << " " << box1.top << " " << box1.width << " " << box1.height << std::endl;
        for (auto box2 : obj2.getCollisionContainer())
        {
          
	        box2.left += obj2.getGlobalBounds().left;
	        box2.top += obj2.getGlobalBounds().top;


	        // std::cout << box2.left << " " << box2.top << " " << box2.width << " " << box2.height << std::endl;
            if (box1.intersects(box2))
	        {
	            // std::cout << i <<" "<< j << std::endl; //TESTREMOVEASAP
                // std::cout << box1.left << ", " << box1.top << " " << box2.left << ", " << box2.top << std::endl;
	            obj1.collisionList.push_back(std::tuple<int, int>{i, j});
	            obj2.collisionList.push_back(std::tuple<int, int>{i, j});
	        }
	        j++;
        }
        i++;
    }
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

// Initiering av grafiska objekt

void Game_World::initScore()
{
    scoreBar.setPosition(0,0);
    scoreBar.setFillColor(sf::Color(128, 128, 128, 128)); // Genomskinlig grå färg

    scoreBarEdge.setPosition(0, 35);
    scoreBarEdge.setScale( 5.32, 1.0 );

    UI::initText(scoreText, 10, 2, "Score: 0", 30, sf::Color::Black);
    scoreText.setStyle(sf::Text::Bold);
}