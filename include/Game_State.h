#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "State.h"
#include "Game_World.h"

//#include <vector>

class Game_State : public State
{
public:

    Game_State ();

    void handle_event (sf::Event event) override;
    void update () override;
    void render (sf::RenderTarget & target) override;
    virtual int get_next_state() override;


private:
    //Datamedlemar
    bool game_over;
    bool menu;
    bool pause;


    Game_World game_world;

    //Funktioner
    //void cleanup ();


};

#endif