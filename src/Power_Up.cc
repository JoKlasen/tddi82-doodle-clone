#include "Power_Up.h"


// basklass powerup
Power_Up::Power_Up()
    :/*  sprite{}, */ active{true}, effects{0,0,0}, texture{}
{
}

void Power_Up::render(sf::RenderTarget & target)
{
    target.draw(shape);
    if(active)
    {
        //target.draw(sprite);
    }
}
    
bool Power_Up::is_active()
{
    return active;
}
void Power_Up::set_pos(sf::Vector2f const& pos)
{
    shape.setPosition(pos.x + 30, pos.y -30);
    //sprite.setPosition(pos.x + 30, pos.y -30);
}


// Spring
Spring::Spring()
    : Power_Up{}
{

    //sprite
    //texture = Manager<sf::Texture>::load("./resources/images/Apple.png");
    //sprite.setTexture(texture);
    //sprite.setScale(0.1, 0.1);
    //testshape
    Power_Up::shape.setFillColor(sf::Color::Red);

    // setting effect
    Power_Up::effects.at(0) = 2; 
}

std::vector<int> const& Spring::get_effect()
{
    
    return Power_Up::effects;
}

// Shield
Shield::Shield()
    : Power_Up{}
{
    // //sprite
    // texture = Manager<sf::Texture>::load("./resources/images/fire.png");
    // sprite.setTexture(texture);
    // sprite.setScale(0.1, 0.1);
    Power_Up::shape.setFillColor(sf::Color::Green);

    // setting effect
    Power_Up::effects.at(1) = 2; 
}
std::vector<int> const&  Shield::get_effect()
{
    return Power_Up::effects;
}

// Extra_life

Extra_Life::Extra_Life()
    : Power_Up{}
{
    //sprite
    //Power_Up:sprite = Manager<sf::Texture>::load();
    Power_Up::shape.setFillColor(sf::Color::Yellow);

    // setting effect
    Power_Up::effects.at(2) = 4; 
}

std::vector<int> const&  Extra_Life::get_effect()
{
    return Power_Up::effects;
    
}

/// Empty_power
Empty_Power::Empty_Power()
    : Power_Up{}
{

}
void Empty_Power::render(sf::RenderTarget &)
{

}
bool Empty_Power::is_active()
{
    return false;
}
void Empty_Power::set_pos(sf::Vector2f const&)
{

}

std::vector<int> const&  Empty_Power::get_effect()
{
    return Power_Up::effects;
}


