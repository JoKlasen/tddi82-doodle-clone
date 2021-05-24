#include "State.h"
#include "Game_State.h"


Game_State::Game_State ()
    : game_over{false}, menu{false}, pause{false}, game_world{}
{
    
}

void Game_State::handle_event (sf::Event event)
{
    if ( event.type == sf::Event::KeyPressed )
    {
        if ( event.key.code == sf::Keyboard::Key::P || event.key.code == sf::Keyboard::Key::Escape)
            pause = true;
    }
    game_world.handle_event(event);
}

void Game_State::update ()
{
    game_world.update();
    if(game_world.getLife() < 1)
        game_over = true;
}

void Game_State::render (sf::RenderTarget & target)
{
    game_world.render(target);
}

int Game_State::get_next_state()
{
    if (game_over)
    {
        game_over = false;
        // för över poäng från gameworld till High_score_state på något vis.
        // Kör cleanup?
        cleanup();
        return HIGH_SCORE_STATE;
    }
    else if (menu)
    {
        menu = false;
        return MENU_STATE;
    }
    else if (pause)
    {
        pause = false;
        return PAUSE_STATE;
    }
    return GAME_STATE;
}

void Game_State::cleanup ()
{
    
}
