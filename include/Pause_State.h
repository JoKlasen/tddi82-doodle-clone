#ifndef PAUSE_STATE_H
#define PAUSE_STATE_H
#include "Game_State.h"
#include "UI.h"



class Pause_State: public Game_State
{
    public:
    Pause_State(State & pgame_world, sf::Window & window);
    void handle_event (sf::Event event) override;
    void update () override;
    void render (sf::RenderTarget & target) override;
    virtual int get_next_state() override;

    private:
    bool unpause;
    bool main_menu;
    State & game_world;
    sf::RectangleShape filter;
    sf::Text paused;
    sf::Text resume;
    sf::Text quit;
    Button resume_b;
    Button quit_b;
};

#endif