#ifndef UI_H
#define UI_H


#include "Textfield.h"
#include <string>
#include <SFML/Graphics.hpp>
#include "Game.h"


class Button
{

public:
    Button(sf::Window & win);
    Button(sf::Text button_text, sf::Window & win);
    void draw(sf::RenderTarget& target);
    void handle_event(sf::Event event); 
    bool is_pressed();
    void setText(sf::Text & newText);
private:
    bool pressed;
    bool button_read;
    sf::Text text;
    sf::Window & window;
    

    //funktion
    void mouse_hover();
    void check_buttonPressed(sf::Event & event);

};


class UI
{
    public:
    static void initText(sf::Text & sfText, std::string const& name, int caracterSize, sf::Color const& color ); // sätter värden efter init
    static void centerText(sf::Text & sfText, float y_offfset); // texten blir centrerad i x-led och man kan sätta en offset i y-led

};

#endif
