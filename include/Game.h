#ifndef GAME_H
#define GAME_H

#include "State.h"
#include "State_Machine.h"

#include <SFML/Graphics.hpp>

#include <string>

class Game
{

public:

Game (std::string const & title, unsigned width, unsigned height);

void Start();

void Stop();

private:

void handle_events (State & state);


void delay (sf::Clock & clock) const;


sf::RenderWindow window;


State_Machine machine;

bool running;

};



#endif