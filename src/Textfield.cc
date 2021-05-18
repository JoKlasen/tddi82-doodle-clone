#include "Textfield.h"
#include "Manager.h"
#include <algorithm>



Textfield::Textfield()
    : char_limit{20}, input{}, text{}, description{}, position{}, box{}, isSelected{false}, isEntered_flag{false}
{
    position = sf::Vector2f(50.0, 50.0);

    //box
    box.setPosition(position);
    box.setSize(sf::Vector2f(300, 50.0));
    box.setFillColor(sf::Color::Transparent);
    box.setOutlineThickness(2);
    box.setOutlineColor(sf::Color(150, 150, 150));

    //text
    text.setFont(Manager<sf::Font>::load(font_file));
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setCharacterSize(25);
    text.setString(input);
    text.setOrigin(text.getGlobalBounds().left, text.getGlobalBounds().height/2);
    

    // description
    description.setFont(Manager<sf::Font>::load(font_file));
    description.setFillColor(sf::Color::Black);
    description.setStyle(sf::Text::Bold);
    description.setCharacterSize(25);
    description.setString("Textfield");
    
    setPosition(position.x, position.y);
    
}

void Textfield::handle_event(sf::Event event)
{
    // kollar om man trycker i textfield
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
    
    // kontrollerar tecken och lägger till string
    if(event.type == sf::Event::TextEntered && isSelected && !isEntered_flag)
    {
        if(event.text.unicode < 128)
        {
            if(char_limit != static_cast<int>(input.getSize()) && event.text.unicode != 8 && event.text.unicode != 27) // 8 = backspace, 27 = esc
            {
                input += event.text.unicode;
                text.setString(input);
            }
            
            if(event.text.unicode == 8 && input.getSize() > 0) // kollar om backspace är tryckt och tar då bort en char
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


void Textfield::setPosition(float x, float y)
{
    position.x = x;
    position.y = y;
    box.setPosition(position);
    text.setPosition(box.getGlobalBounds().left + 10, box.getGlobalBounds().top + box.getGlobalBounds().height/2 - text.getGlobalBounds().height/2 -align_text);
    description.setPosition(box.getGlobalBounds().left + 10, box.getGlobalBounds().top - 28);
}

void Textfield::setFieldText(std::string const& str)
{
    description.setString(str);
}

int Textfield::getWidth()
{
    return box.getGlobalBounds().width;
}


int Textfield::getHight()
{
    return box.getGlobalBounds().height;
}

//Textfield(sf::Font pfont, int size, sf::Vector2f pposition);