#include "Textfield.h"
#include "Manager.h"
#include <algorithm>



Textfield::Textfield()
    : char_limit{20}, font{}, input{}, text{}, description{}, position{}, box{}, isSelected{false}, isEntered_flag{false}
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
    text.setCharacterSize(20);
    text.setString(input);
    text.setOrigin(text.getGlobalBounds().left, text.getGlobalBounds().height/2);
    text.setPosition(box.getGlobalBounds().left + 10, box.getGlobalBounds().top + box.getGlobalBounds().height/2 - text.getGlobalBounds().height/2 -5);

    // description
    description.setFont(font);
    description.setCharacterSize(20);
    description.setString("Textfield");
    description.setPosition(box.getGlobalBounds().left + 10, box.getGlobalBounds().top - 25);
}


Textfield::Textfield(sf::Vector2f pposition = sf::Vector2f(50, 50), int width = 300, int height = 50, int limit = 30, std::string pdescription = std::string("Textfield"))
    : char_limit{limit}, font{}, input{}, text{}, description{}, position{pposition}, box{}, isSelected{false}, isEntered_flag{false}
{
    //box
    box.setPosition(position);
    box.setSize(sf::Vector2f(width, height));
    box.setFillColor(sf::Color::Transparent);
    box.setOutlineThickness(2);
    box.setOutlineColor(sf::Color::White);

    //text
    font = Manager<sf::Font>::load("./resources/fonts/font.ttf");
    text.setFont(font);
    text.setCharacterSize(20);
    text.setString(input);
    text.setOrigin(text.getGlobalBounds().left, text.getGlobalBounds().height/2);
    text.setPosition(box.getGlobalBounds().left + 10, box.getGlobalBounds().top + box.getGlobalBounds().height/2 - text.getGlobalBounds().height/2 -5);

    // description
    description.setFont(font);
    description.setCharacterSize(20);
    description.setString(pdescription);
    description.setPosition(box.getGlobalBounds().left + 10, box.getGlobalBounds().top - 25);
}

void Textfield::handle_event(sf::Event event)
{

    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !isEntered_flag)
    {
        if(event.mouseButton.x <= box.getGlobalBounds().width + box.getGlobalBounds().left 
            && event.mouseButton.x >= box.getGlobalBounds().left
            && event.mouseButton.y <= box.getGlobalBounds().height + box.getGlobalBounds().top 
            && event.mouseButton.y >= box.getGlobalBounds().top
        )
        {
           
            isSelected = true;
            if(input.getSize() == 0)
            {
                text.setString(input + "_");
            }
                
           
        }
        else
        {
            isSelected = false;
            text.setString(input);
        }
        
    }
    
    if(event.type == sf::Event::TextEntered && isSelected && !isEntered_flag)
    {
        if(event.text.unicode < 128)
        {
            if(char_limit != static_cast<int>(input.getSize()) && event.text.unicode != 8)
            {
                input += event.text.unicode;
                text.setString(input);
            }
            
            if(event.text.unicode == 8 && input.getSize() > 0)
            {
                std::string temp;
                std::copy(input.begin(), --input.end(), std::back_inserter(temp));
                input = temp;
                if(input.getSize() == 0)
                {
                    text.setString(input + "_");
                }
                else
                {
                    text.setString(input);
                }
                
            }
        }
    }

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::Return && isSelected)
    {
        std::cout << "entered" << std::endl;
        isEntered_flag = true;
        isSelected = false;
        text.setString(" ");
    }
}

void Textfield::render(sf::RenderTarget & target)
{
    target.draw(box);
    target.draw(description);
    target.draw(text);
}

std::string Textfield::get_entered_name()
{
    if(isEntered_flag)
    {
        return std::string(input); 
    }
    else
    {
        throw std::logic_error{"Namn är inte inmatat"};
    }
}

bool Textfield::isEntered()
{
    return isEntered_flag;
}

//Textfield(sf::Font pfont, int size, sf::Vector2f pposition);