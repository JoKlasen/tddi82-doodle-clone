#ifndef STATE_H
#define STATE_H

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