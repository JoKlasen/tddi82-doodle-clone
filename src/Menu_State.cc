#include "Menu_State.h"
#include "State.h"

sf::CircleShape shape(100.f);
//titel
//new game
//continue
//highscore

Menu_State::Menu_State()
    : play{false}
{

}

void Menu_State::handle_event(sf::Event event)
{
    
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
    return MENU_STATE;
}