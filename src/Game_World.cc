#include "Game_World.h"
#include <SFML/Graphics.hpp>
#include "constants.h"


Game_World::Game_World ()
    : score{0}
{

}

void Game_World::update ()
{
    playershape.setPosition (screen_width/2 - playershape.getRadius(), screen_height /2 - playershape.getRadius());
    playershape.setFillColor (sf::Color::Blue);
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