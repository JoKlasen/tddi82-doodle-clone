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
    // Flytta spelaren vid knappar
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        player.move(sf::Vector2f(-4, 0));
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        player.move(sf::Vector2f(4, 0));


}

void Game_World::update ()
{
    // Uppdaterar plats
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
}

void Game_World::render (sf::RenderTarget & target)
{
    for ( auto & ent : entities )
    {
        ent->render (target);
    }


    player.render (target);
}