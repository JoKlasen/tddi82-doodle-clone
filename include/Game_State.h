#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "State.h"

#include <vector>

class Game_State : public State
{
public:

    Game_State () = default;

    void handle_event (sf::Event event) override;
    void update () override;
    void render (sf::RenderTarget & target) override;
    virtual int get_next_state() override;


private:
    //Variabler
    //bool end_game{false};

    //Funktioner
    //void cleanup ();


};

#endif