#ifndef STATE_H
#define STATE_H

//#include "Game_Event.h"

#include <SFML/Graphics.hpp> 

class State
{

public:

virtual ~State() = default;

virtual void handle_event (sf::Event event);

virtual Game_Event update() = 0;

virtual void render(sf::RenderTarget & target) = 0;

virtual void activate ();

virtual void deactivate ();

private:

};

#endif