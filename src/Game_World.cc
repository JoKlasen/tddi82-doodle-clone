#include "Game_World.h"
#include <SFML/Graphics.hpp>
#include "constants.h"


Game_World::Game_World ()
    : score{0}, entities{}, player{}
{

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
    player.update ();
    // for ( auto & ent : entities )
    // {
    //     ent.update ();
    // }

    
}

void Game_World::render (sf::RenderTarget & target)
{
    
    // for ( auto & ent : entities )
    // {
    //     ent.render (target);
    // }

    player.render (target);
}