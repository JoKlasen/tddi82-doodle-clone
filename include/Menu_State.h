#ifndef MENU_STATE_H
#define MENU_STATE_H
#include <SFML/Graphics.hpp>
#include "State.h"

class Menu_State: public State
{

public:

Menu_State();

void handle_event (sf::Event event) override;
Game_Event update() override;
void render(sf::RenderTarget & target) override;

private:

bool play;

bool exit_game;

bool high_score;

};


#endif