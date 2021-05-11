#ifndef HIGH_SCORE_STATE_H
#define HIGH_SCORE_STATE_H
#include "State.h"
#include <SFML/Graphics.hpp>
#include <set>

class High_Score_State: public State
{
public:
    High_Score_State();

    void handle_event (sf::Event event) override;

    void update () override;

    void render(sf::RenderTarget & target) override;

    int get_next_state() override;

    void set_current_score(int score);
    void set_current_name(std::string name);
    void add_current_score();


private:
    const std::string font_file = "resources/fonts/font.ttf"; 
    const std::string hs_file = "resources/high_score.txt";

    struct High_Score
    {
        std::string name;
        int score;
    };

    //Variabler
    bool menu;
    sf::Text state_text;
    sf::Text current_leader_text;
    sf::Font font;
    std::vector<High_Score> high_scores;
    High_Score current_score;
    std::set<std::string> name_list;


    //Functions
    void read_file();
    void print_hs();
    
    
};


#endif 