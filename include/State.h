#ifndef STATE_H
#define STATE_H

//#include "Game_Event.h"

#include <SFML/Graphics.hpp> 
#include <string>

int const MENU_STATE{0};
int const GAME_STATE{1};
int const HIGH_SCORE_STATE{2};
int const PAUSE_STATE{3};
int const CURRENT_SCORE_STATE{4};

class State
{

public:
    virtual ~State () = default;

    virtual void handle_event (sf::Event event) = 0;

    virtual void update () = 0;

    virtual void render(sf::RenderTarget & target) = 0;

    virtual int get_next_state() = 0;

private:

};

#endif