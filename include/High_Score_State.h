#ifndef HIGH_SCORE_STATE_H
#define HIGH_SCORE_STATE_H
#include "State.h"
#include "UI.h"
#include <SFML/Graphics.hpp>
#include <set>
#include "Textfield.h"

class High_Score_State: public State
{
public:
    High_Score_State();

    virtual void handle_event (sf::Event event) override;

    virtual void update () override;

    virtual void render(sf::RenderTarget & target) override;

    virtual int get_next_state() override;

    void set_current_score(int score);
    void set_current_name(std::string name);
    void add_current_score();


protected:
    
    struct High_Score
    {
        std::string name;
        int score;
    };

    //Variabler
    bool menu;
    sf::Text                state_text;
    sf::Text                playerScore;
    std::vector<High_Score> high_scores;
    High_Score              current_score;
    Textfield               textfield;
    //Functions
    void read_file();
    void print_hs();
    void cleanup();
    
    
};


#endif 