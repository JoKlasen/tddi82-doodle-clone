#ifndef CURRENT_HS_STATE_H
#define CURRENT_HS_STATE_H

#include "High_Score_State.h"

class Current_HS_State: public High_Score_State
{
public:
    Current_HS_State(sf::Window & window);

    void handle_event (sf::Event event) override;

    void update () override;

    void render(sf::RenderTarget & target) override;

    int get_next_state() override;

private:

    //functions
    void initLeaders();

    //variables
    std::vector<sf::Text> topTen;
    bool updateLeader;
    Button back_button;

};

#endif