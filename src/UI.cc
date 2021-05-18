#include "UI.h"
#include "constants.h"
#include "Manager.h"
#include <iostream>

Button::Button(sf::Window & win)
    : pressed{false}, button_read{false}, text{}, window{win}
{
    
    UI::initText(text, "Button", 30, sf::Color::Black);
    UI::centerText(text, 0);
}

Button::Button(sf::Text button_text, sf::Window & win)
    : pressed{false}, button_read{false}, text{}, window{win}
{
    text = button_text;
}

void Button::draw(sf::RenderTarget& target)
{
    mouse_hover(); // changing text color if mouse is over text
    target.draw(text);
}

void Button::handle_event(sf::Event event)
{
    if(button_read)
    {
        pressed = false;
        button_read = false;
    }
    check_buttonPressed(event); // setting pressed = true if pressed

}

bool Button::is_pressed()
{
    button_read = true;
    return pressed;
}

void Button::setText(sf::Text & newText)
{
    text = newText;
}

void Button::mouse_hover()
{
    int x = sf::Mouse::getPosition(window).x;
    int y = sf::Mouse::getPosition(window).y;
    int left = text.getGlobalBounds().left;
    int top = text.getGlobalBounds().top;
    int width = text.getGlobalBounds().width;
    int height = text.getGlobalBounds().height;
    if(left < x && x < left+width && top < y && y < top+height)
    {
        text.setFillColor(sf::Color::Red);
    }
    else
    {
        text.setFillColor(sf::Color::Black);
    }
}

void Button::check_buttonPressed(sf::Event & event)
{
     // check pressed
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;
    int left = text.getGlobalBounds().left;
    int top = text.getGlobalBounds().top;
    int width = text.getGlobalBounds().width;
    int height = text.getGlobalBounds().height;
    
    if(left < x && x < left+width && top < y && y < top+height)
    {
        pressed = true;
    }
}

// general funktion

void UI::initText(sf::Text & sfText,std::string const& name, int caracterSize, sf::Color const& color )
{
    sfText.setString(name);
    sfText.setFont(Font_Manager::load(font_file));
    sfText.setFillColor(color);
    sfText.setCharacterSize(caracterSize);
    sfText.setPosition(0,0);
}

void UI::centerText(sf::Text & sfText, float y_offfset)
{
    sfText.setPosition((screen_width-sfText.getGlobalBounds().width) / 2, (screen_height - sfText.getGlobalBounds().height) / 2 + y_offfset);
}


