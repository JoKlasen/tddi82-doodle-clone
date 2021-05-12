#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include <string>
#include <memory>
#include "State.h"

class Game 
{
public:
    Game (std::string const & title, unsigned width, unsigned height);

    void start ();



private:
    //Variabler
    sf::RenderWindow window;
    std::map<int, std::unique_ptr<State>> states;
    int current_state;
    bool running;

    //Funktioner
    void handle_events(); 

    void delay (sf::Clock & clock) const;
};

#endif // GAME_H
