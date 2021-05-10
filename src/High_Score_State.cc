#include "High_Score_State.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>



High_Score_State::High_Score_State()
    : menu{false}, state_text{}, current_leader_text{}, font{}, high_scores{}, current_score{"Banan", 400}
{
    
    if ( !font.loadFromFile (font_file) )
        throw std::invalid_argument ("Unable to load font");
    state_text = sf::Text{ "HIGH SCORE", font, 25 };
    add_current_score();
    read_file();
    print_hs();
    current_leader_text = sf::Text{high_scores.at(0).name + ": " + std::to_string(high_scores.at(0).score) + " Points", font, 25 };

}

void High_Score_State::handle_event (sf::Event event) 
{
    if ( event.type == sf::Event::KeyPressed )
    {
        if ( event.key.code == sf::Keyboard::Key::Escape)
            menu = true;
    }

    
}

void High_Score_State::update ()
{

}

void High_Score_State::render(sf::RenderTarget & target)
{
    auto bounds { state_text.getGlobalBounds () };
    auto size   { target.getSize () };

    state_text.setPosition ((size.x - bounds.width) / 2,
                      (size.y - bounds.height) / 2-30);

    target.draw (state_text);

    bounds = current_leader_text.getGlobalBounds ();
    
    current_leader_text.setPosition ((size.x - bounds.width) / 2,
                      (size.y - bounds.height) / 2+50);
    
    target.draw(current_leader_text);
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
    
    if(name_list.find(current_score.name) == name_list.end()) // ska kasta exception "namn finns redan"
    {
        return;
    }
    

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
        name_list.insert(name);
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


