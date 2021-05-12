#include "Textfield.h"
#include "Manager.h"



Textfield::Textfield()
    : font{}, input{}, text{}, position{}, box{}
{
    position = sf::Vector2f(50.0, 50.0);

    
    

    //box
    box.setPosition(position);
    box.setSize(sf::Vector2f(300, 50.0));
    box.setFillColor(sf::Color::Transparent);
    box.setOutlineThickness(2);
    box.setOutlineColor(sf::Color::White);

    //text
    font = Manager<sf::Font>::load("./resources/fonts/font.ttf");
    text.setFont(font);
    input = "Hello world!";
    
    text.setCharacterSize(20);
    text.setString(input);
    text.setOrigin(text.getGlobalBounds().left, text.getGlobalBounds().height/2);
    text.setPosition(box.getGlobalBounds().left + 10, box.getGlobalBounds().top + box.getGlobalBounds().height/2 - text.getGlobalBounds().height/2);
    
}

void Textfield::handle_event(sf::Event event)
{

}

void Textfield::render(sf::RenderTarget & target)
{
    target.draw(box);
    target.draw(text);
}

//Textfield(sf::Font pfont, int size, sf::Vector2f pposition);