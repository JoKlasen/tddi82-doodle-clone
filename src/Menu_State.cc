#include "Menu_State.h"
#include "State.h"
#include "Manager.h"
#include "constants.h"
#include "Platform.h"   

sf::CircleShape shape(100.f);
//titel
//new game
//continue
//highscore

sf::Texture texture;
sf::Sprite sprite;



Menu_State::Menu_State()
    : play{false}, exit_game{false}, high_score{false}
{
    texture = Manager<sf::Texture>::load("./resources/images/Apple.png");
    sprite.setTexture(texture);
    
    Platform p();
    Platform p1("oskar");
}

void Menu_State::handle_event(sf::Event event)
{
    if ( event.type == sf::Event::KeyPressed )
    {
        if ( event.key.code == sf::Keyboard::Key::H )
            high_score = true;
        else if ( event.key.code == sf::Keyboard::Key::Return )
            play = true;
    }
}
void Menu_State::update()
{
    
    //platform.update();

    shape.setFillColor(sf::Color::Green);
}
void Menu_State::render(sf::RenderTarget & target)
{
    //target.draw(shape);

    target.draw(sprite);
    //platform.render(target);

}

}
int Menu_State::get_next_state() 
{
    if(high_score)
    {
        high_score = false;
        return HIGH_SCORE_STATE;
    }
    else if(play)
    {
        play = false;
        return GAME_STATE;
    }
        

    return MENU_STATE;    
}