#ifndef MENU_STATE_H
#define MENU_STATE_H
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Platform.h"
#include "UI.h"

class Menu_State: public State
{

public:
    Menu_State(sf::Window & window);

    void handle_event (sf::Event event) override;

    void update () override;

    void render(sf::RenderTarget & target) override;

    int get_next_state() override;

    void initMenuItem(sf::Text & object, int x, int y, std::string name, int caracterSize, sf::Color color);
    bool mouseEventMenuItem(sf::Event event, sf::Text & sfText);

private:
    //Variabler
    bool play;
    bool exit_game;
    bool high_score;
    bool options;
    
    sf::Text titelText;
    sf::Text playText;
    sf::Text highScoreText;
    sf::Text optionsText;

    Button play_button;
    Button hs_button;
    Button options_button;
    Platform platform;
    
};


#endif
