#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "State.h"
#include "Game_World.h"
#include "High_Score_State.h"

//#include <vector>

class Game_State : public State
{
public:
    Game_State();

    void handle_event (sf::Event event) override;
    void update () override;
    void render (sf::RenderTarget & target) override;
    void cleanup();
    virtual int get_next_state() override;

    static int score;

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