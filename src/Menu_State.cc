#include "Menu_State.h"
#include "State.h"
#include "Manager.h"
#include "constants.h"
#include "Platform.h"   

//sf::CircleShape shape(100.f);
//titel
//new game
//continue
//highscore

//sf::Texture texture;
//sf::Sprite sprite;
//sf::Texture backgroundTexture;
//sf::Sprite background;



Menu_State::Menu_State()
    : play{false}, exit_game{false}, high_score{false}, options{},
      titelText{}, playText{}, highScoreText{}, optionsText{},
      platform{}
{
    // init texts
    initMenuItem(titelText,     50,  100, "doodle jump", 60, sf::Color::Red);
    initMenuItem(playText,      125, 200, "play",        40, sf::Color::Black);
    initMenuItem(highScoreText, 380, 400, "scores",      40, sf::Color::Black);
    initMenuItem(optionsText,   330, 480, "options",     40, sf::Color::Black);
    
}
void Menu_State::initMenuItem(sf::Text & sfText, int x, int y, std::string name, int caracterSize, sf::Color color )
{
    sfText.setFont(Font_Manager::load(font_file));
    sfText.setString(name);
    sfText.setFillColor(color);
    sfText.setCharacterSize(caracterSize);
    sfText.setPosition(x,y);
}

bool Menu_State::mouseEventMenuItem(sf::Event event, sf::Text & sfText)
{
    bool clicked = false;
    int left = sfText.getGlobalBounds().left;
    int top = sfText.getGlobalBounds().top;
    int width = sfText.getGlobalBounds().width;
    int height = sfText.getGlobalBounds().height;
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;
    
    if(left < x && x < left+width && top < y && y < top+height)
    {
        clicked = true;
    }
    return clicked;
}

void Menu_State::handle_event(sf::Event event)
{
    if ( event.type == sf::Event::KeyPressed )
    {
        if ( event.key.code == sf::Keyboard::Key::H )
            high_score = true;
        else if ( event.key.code == sf::Keyboard::Key::P )
            play = true;
        else if ( event.key.code == sf::Keyboard::Key::Return )
            play = true;
    }
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if( mouseEventMenuItem(event, highScoreText) )
	        high_score = true;
	    else if ( mouseEventMenuItem(event, playText) )
            play = true;
	    else if ( mouseEventMenuItem(event, optionsText) )
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
    target.draw(playText);
    target.draw(highScoreText);
    target.draw(optionsText);
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
