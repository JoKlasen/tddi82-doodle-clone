#include "Game_World.h"
#include <SFML/Graphics.hpp>
#include "constants.h"


Game_World::Game_World ()
    : score{0}
{
    playershape.setPosition (screen_width/2 - playershape.getRadius(), screen_height /2 - playershape.getRadius());
    playershape.setFillColor (sf::Color::Blue);
}

void Game_World::handle_event (sf::Event event)
{
    // Flytta spelaren vid knappar
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        playershape.move(-4.f, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        playershape.move(4.f, 0);


    // wrap around
    if ( playershape.getPosition().x > screen_width )
        playershape.setPosition(0, playershape.getPosition().y);
    if ( playershape.getPosition().x < (0 - playershape.getLocalBounds().width ) )
        playershape.setPosition( (screen_width - playershape.getLocalBounds().width ), playershape.getPosition().y);

}

void Game_World::update ()
{
   
    // for ( auto & ent : entities )
    // {
    //     ent.update ();
    // }

    // player.update ();
}

void Game_World::render (sf::RenderTarget & target)
{
    target.draw(playershape);
    // for ( auto & ent : entities )
    // {
    //     ent.render (target);
    // }

    // player.render (target);
}