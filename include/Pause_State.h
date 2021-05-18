#ifndef PAUSE_STATE_H
#define PAUSE_STATE_H
#include "Game_State.h"

class Pause_State: public Game_State
{
    public:

    void handle_event (sf::Event event) override;
    void update () override;
    void render (sf::RenderTarget & target) override;
    virtual int get_next_state() override;

    private:
    bool unpause;
    Game_World & game_world;
};

#endif