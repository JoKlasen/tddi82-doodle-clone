#include "Menu_State.h"
#include "State.h"

sf::CircleShape shape(100.f);
//titel
//new game
//continue
//highscore

Menu_State::Menu_State()
    : play{false}, exit_game{false}, high_score{false}
{

}

void Menu_State::handle_event(sf::Event event)
{
    if ( event.type == sf::Event::KeyPressed )
    {
        if ( event.key.code == sf::Keyboard::Key::H)
            high_score = true;
    }
}
void Menu_State::update()
{
    
    shape.setFillColor(sf::Color::Green);
}
void Menu_State::render(sf::RenderTarget & target)
{
    target.draw(shape);
}

int Menu_State::get_next_state() 
{
    if(high_score)
    {
        high_score = false;
        return HIGH_SCORE_STATE;
    }
        

    return MENU_STATE;    
}