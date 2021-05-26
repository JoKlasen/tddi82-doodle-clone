#include "Current_HS_State.h"
#include <iostream>
#include <algorithm>




Current_HS_State::Current_HS_State(sf::Window & window)
    : High_Score_State{}, topTen{}, updateLeader{}, back_button{window}
{
    // state text
    state_text.setString("Current High Scores");
    UI::centerText(state_text, -200);

    //back button
    sf::Text temp{};
    UI::initText(temp, 50.f, 50.f, "back", 30,  sf::Color::Black);
    temp.setStyle(sf::Text::Bold);
    back_button.setText(temp);

    //init topTen
    initLeaders();

}


void Current_HS_State::handle_event (sf::Event event) 
{
    back_button.handle_event(event);

    if(back_button.is_pressed())
    {
        menu = true;
    }
}

void Current_HS_State::update ()
{   

    if(updateLeader)
    {
        read_file();
        initLeaders();
    }
}

void Current_HS_State::render(sf::RenderTarget & target)
{
    target.draw(state_text);

    back_button.draw(target);

    //draw topTen
   
    for(sf::Text & e: topTen)
    {
        target.draw(e);
    }
}

int Current_HS_State::get_next_state()
{
    if(menu)
   {
       menu = false;
       updateLeader = true;
       //cleanup();
       return MENU_STATE;
   }
        

    return CURRENT_SCORE_STATE;    
}



// private function

void Current_HS_State::initLeaders()
{
    topTen.erase(topTen.begin(), topTen.end());

    int avstand{40};
    for(int i{}; i < 10; i++)
    {
        sf::Text temp{};
        UI::initText(temp, std::to_string(i+1) + ".  " + high_scores.at(i).name + ":  " + std::to_string(high_scores.at(i).score), 30, sf::Color::Black);
        UI::centerText(temp, avstand*i);
        topTen.push_back(temp);
    }
}