#include "High_Score_State.h"
#include "constants.h"
#include "Manager.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>



High_Score_State::High_Score_State()
    : menu{false}, state_text{}, high_scores{}, current_score{}, textfield{}
{
    // Text
<<<<<<< HEAD
    
    state_text = sf::Text{ "HIGH SCORE", Font_Manager::load(font_file), 30 };
=======
    state_text = sf::Text{ "HIGH SCORE", Manager<sf::Font>::load(font_file), 30 };
>>>>>>> origin/johan-dev
    state_text.setFillColor(sf::Color::Black);
    state_text.setStyle(sf::Text::Bold);
    state_text.setPosition ((screen_width-state_text.getGlobalBounds().width) / 2, (screen_height - state_text.getGlobalBounds().height) / 2 - 100);

    // Text-field
    textfield.setPosition ((screen_width-textfield.getWidth()) / 2, (screen_height - textfield.getHight()) / 2 + 40);
    textfield.setFieldText("Enter name:");

    // Läser in hs
    read_file();

}

void High_Score_State::handle_event (sf::Event event) 
{
    if ( event.type == sf::Event::KeyPressed )
    {
        if ( event.key.code == sf::Keyboard::Key::Escape)
            menu = true;
    }

    // Textfield
    textfield.handle_event(event);
}

void High_Score_State::update ()
{
    if(textfield.isEntered())
    {
        current_score.name = textfield.get_entered_name();
    }
}

void High_Score_State::render(sf::RenderTarget & target)
{
    //state-text
    target.draw (state_text);

    //textfield
    textfield.render(target);
}

int High_Score_State::get_next_state()
{
   if(menu)
   {
       menu = false;
       return MENU_STATE;
   }
        

    return HIGH_SCORE_STATE;    
}

void High_Score_State::set_current_score(int score)
{
    current_score.score = score;
}

void High_Score_State::set_current_name(std::string name)
{
    current_score.name = name;
}

void High_Score_State::add_current_score()
{
    if(current_score.name == "") // kasta exception "måste ange namn"
    {
        return;
    }
    
    high_scores.push_back(High_Score{current_score.name, current_score.score});
    std::sort(high_scores.begin(), high_scores.end(), [](High_Score a, High_Score b) {
        return a.score > b.score;
    });

    std::ofstream ofs(hs_file, std::ios::app);
    
    if(ofs.fail())
    {
        std::cerr << "Error: File could not be found or opened!" << std::endl;
        return;
    }
    ofs << "\n" << current_score.score << ":" << current_score.name;

    ofs.close();
}
//////////////
// Private
//////////////

void High_Score_State::read_file()
{
    std::ifstream ifs{};
    ifs.open(hs_file);

    if(ifs.fail())
    {
        std::cerr << "Error: File could not be found or opened!" << std::endl;
        return;
    }

    std::string line;
    while(std::getline(ifs, line))
    {
        std::stringstream ss{line};
        std::string name;
        int score;
        char c;

        ss >> score;
        ss >> c;
        ss >> name;
    
        high_scores.push_back(High_Score{name, score});
        //std::cout << name << std::endl;
    }
    std::sort(high_scores.begin(), high_scores.end(), [](High_Score a, High_Score b) {
        return a.score > b.score;
    });
    ifs.close();

}

void High_Score_State::print_hs()
{
    std::cout << "Current highscores:" << std::endl;
    int pos{1};
    for(High_Score e: high_scores)
    {
        std::cout << pos++ << ": " << e.name << ":" << e.score << std::endl;
    }
}


