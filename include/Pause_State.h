#ifndef PAUSE_STATE_H
#define PAUSE_STATE_H
#include "Game_State.h"

class Pause_State: public Game_State
{
    public:
    Pause_State(State & pgame_world);
    void handle_event (sf::Event event) override;
    void update () override;
    void render (sf::RenderTarget & target) override;
    virtual int get_next_state() override;

    private:
    bool unpause;
    State & game_world;
    sf::RectangleShape filter;
    sf::Text paused;
    sf::Text resume;
    sf::Text quit;
};

#endif