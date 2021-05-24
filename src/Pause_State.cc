#include "Pause_State.h"
#include "constants.h"
#include "Manager.h"



Pause_State::Pause_State(State & pgame_world, sf::Window & window)
    : unpause{false}, main_menu{false}, game_world{pgame_world}, filter{}, paused{}, resume{}, quit{}, resume_b{window}, quit_b{window}
{
    

    // init filter
    filter.setSize(sf::Vector2f(screen_width, screen_height));
    filter.setFillColor(sf::Color(150, 150, 150, 125));

    // text init

    UI::initText(paused, 
                "Paused", 
                60, 
                sf::Color::Black);
    paused.setStyle(sf::Text::Bold);
    UI::initText(resume, 
                "resume",
                40, 
                sf::Color::Black);
    UI::initText(quit, 
                "quit",
                40, 
                sf::Color::Black);                        

    UI::centerText(paused, -100); // texten blir centrerad i x-led och man kan sätta en offset i y-led
    UI::centerText(resume, 0);
    UI::centerText(quit, 80);

    resume_b.setText(resume);
    quit_b.setText(quit);
}

void Pause_State::handle_event (sf::Event event) 
{
    resume_b.handle_event(event);
    quit_b.handle_event(event);

    if(resume_b.is_pressed())
    {
        unpause = true;
    }
    else if (quit_b.is_pressed())
    {
        main_menu = true;
    }
    
}
void Pause_State::update ()
{
    
}

void Pause_State::render (sf::RenderTarget & target) 
{
    game_world.render(target);
    target.draw(filter);
    target.draw(paused);
    resume_b.draw(target);
    quit_b.draw(target);

}

int Pause_State::get_next_state()
{
    if(unpause)
    {
        unpause = false;
        return GAME_STATE;
    }
    else if(main_menu)
    {
        main_menu = false;
        cleanup();
        return MENU_STATE;
    }
    else
    {
        return PAUSE_STATE;
    }
}