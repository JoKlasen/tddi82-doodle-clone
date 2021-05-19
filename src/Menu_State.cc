#include "Menu_State.h"
#include "State.h"
#include "Manager.h"
#include "constants.h"
#include "Platform.h"   
#include "UI.h"

//sf::CircleShape shape(100.f);
//titel
//new game
//continue
//highscore

//sf::Texture texture;
//sf::Sprite sprite;
//sf::Texture backgroundTexture;
//sf::Sprite background;



Menu_State::Menu_State(sf::Window & window)
    : play{false}, exit_game{false}, high_score{false}, options{},
      titelText{}, playText{}, highScoreText{}, optionsText{}, play_button{window}, hs_button{window}, options_button{window},
      platform{}
{
    UI::initText(titelText,     50,  100, "doodle jump", 60, sf::Color::Red);
    UI::initText(playText,      125, 200, "play",        40, sf::Color::Black);
    UI::initText(highScoreText, 380, 400, "scores",      40, sf::Color::Black);
    UI::initText(optionsText,   330, 480, "options",     40, sf::Color::Black);
    play_button.setText(playText);
    hs_button.setText(highScoreText);
    options_button.setText(optionsText);

}

void Menu_State::handle_event(sf::Event event)
{
    play_button.handle_event(event);
    hs_button.handle_event(event);
    options_button.handle_event(event);

    if(play_button.is_pressed())
    {
        play = true;
    }
    else if(hs_button.is_pressed())
    {
        high_score = true;
    }
    else if(options_button.is_pressed())
    {
        options = true;
    }
}

void Menu_State::update()
{

}

void Menu_State::render(sf::RenderTarget & target)
{
    //target.draw(shape);

    //target.draw(sprite);//TESTFIXASAPEDVIN

    target.draw(titelText);
    play_button.draw(target);
    hs_button.draw(target);
    options_button.draw(target);
    
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
    else if(options)
    {
        options = false;
        return GAME_STATE;//TESTFIXASAPEDVIN
    } 

    return MENU_STATE;    
}
