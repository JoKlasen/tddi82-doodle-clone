#include "Pause_State.h"
#include "constants.h"
#include "Manager.h"


Pause_State::Pause_State(State & pgame_world)
    : unpause{false}, game_world{pgame_world}, filter{}, paused{}, resume{}, quit{}
{
    // init filter
    filter.setSize(sf::Vector2f(screen_width, screen_height));
    filter.setFillColor(sf::Color(150, 150, 150, 125));

    // text init
    paused.setFont(Font_Manager::load(font_file));
    resume.setFont(Font_Manager::load(font_file));
    quit.setFont(Font_Manager::load(font_file));

    paused.setString("Paused");
    resume.setString("resume");
    quit.setString("quit");

    paused.setFillColor(sf::Color::Black);
    resume.setFillColor(sf::Color::Black);
    quit.setFillColor(sf::Color::Black);

    paused.setCharacterSize(60);
    paused.setStyle(sf::Text::Bold);
    resume.setCharacterSize(40);
    quit.setCharacterSize(40);

    paused.setPosition ((screen_width-paused.getGlobalBounds().width) / 2, (screen_height - paused.getGlobalBounds().height) / 2 - 100);
    resume.setPosition ((screen_width-resume.getGlobalBounds().width) / 2, (screen_height - resume.getGlobalBounds().height) / 2 );
    quit.setPosition ((screen_width-quit.getGlobalBounds().width) / 2, (screen_height - quit.getGlobalBounds().height) / 2 + 80);

}

void Pause_State::handle_event (sf::Event event) 
{

}
void Pause_State::update ()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        unpause = true;
    }
}

void Pause_State::render (sf::RenderTarget & target) 
{
    game_world.render(target);
    target.draw(filter);
    target.draw(paused);
    target.draw(resume);
    target.draw(quit);

}

int Pause_State::get_next_state()
{
    if(unpause)
    {
        unpause = false;
        return GAME_STATE;
    }
    else
    {
        return PAUSE_STATE;
    }
}