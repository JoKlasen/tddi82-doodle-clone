#include "Menu_State.h"
#include "State.h"
#include "Platform.h"   

sf::CircleShape shape(100.f);



Menu_State::Menu_State()
    : play{false}, exit_game{false}, high_score{false}
{
    Platform p();
    Platform p1("oskar");
}

void Menu_State::handle_event(sf::Event event)
{
    
}
void Menu_State::update()
{
    //platform.update();

    shape.setFillColor(sf::Color::Green);
}
void Menu_State::render(sf::RenderTarget & target)
{
    //platform.render(target);

    target.draw(shape);
}

int Menu_State::get_next_state() 
{
    return MENU_STATE;
}