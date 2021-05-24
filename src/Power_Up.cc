#include "Power_Up.h"
#include "Player.h"


// basklass powerup
Power_Up::Power_Up()
    :sprite{}, active{true}, effects{0,0,0,0,0,0,0,}, texture{}
{
    
}

void Power_Up::render(sf::RenderTarget & target)
{
    
    if(active)
    {
        target.draw(shape);
        target.draw(sprite);
    }
}
    
bool Power_Up::is_active()
{
    return active;
}
void Power_Up::set_pos(sf::Vector2f const& pos)
{
    shape.setPosition(pos.x + 30, pos.y -30);
    sprite.setPosition(pos.x + 30, pos.y -30);
}
void Power_Up::set_active(bool a)
{
    active = a;
}


// Spring
Spring::Spring()
    : Power_Up{}
{

    //sprite
    sprite.setTexture(Manager<sf::Texture>::load(spritesheet_file));
    sprite.setTextureRect(spring_pushed);
    sprite.setOrigin(0, 28);
    

    //testshape
    Power_Up::shape.setFillColor(sf::Color::Transparent);

    // setting effect
    Power_Up::effects.at(SPRING_POWER) = 15; 
}

void Spring::set_pos(sf::Vector2f const& pos)
{   
    sprite.setPosition(pos.x + 20, pos.y + 5);

    if(!active)
        sprite.setPosition(pos.x + 20, pos.y - 20);
}
void Spring::render(sf::RenderTarget & target)
{
    if(active)
    {
        target.draw(sprite);
    }
    else
    {
        sprite.setTextureRect(spring_unpushed);
        
        target.draw(sprite);
    }
}

std::vector<int> const& Spring::get_effect()
{
    
    return Power_Up::effects;
}

// Shield
Shield::Shield()
    : Power_Up{}
{
    //sprite
    sprite.setTexture(Texture_Manager::load(spritesheet_power_file));
    sprite.setTextureRect(shield_pic);
    Power_Up::shape.setFillColor(sf::Color::Transparent);

    // setting effect
    Power_Up::effects.at(SHIELD_POWER) = 2; 
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
    sprite.setTexture(Manager<sf::Texture>::load("./resources/images/Apple.png"));
    sprite.setScale(0.1, 0.1);
    
    Power_Up::shape.setFillColor(sf::Color::Transparent);
    // setting effect
    Power_Up::effects.at(LIFE_POWER) = 1; 
}

std::vector<int> const&  Extra_Life::get_effect()
{
    return Power_Up::effects;
    
}

// Jetpack

Jetpack::Jetpack()
    : Power_Up{}
{
    //sprite
    sprite.setTexture(Texture_Manager::load(spritesheet_power_file));
    sprite.setTextureRect(jetpack_pic);


    Power_Up::shape.setFillColor(sf::Color::Transparent);

    // setting effect
    Power_Up::effects.at(JETPACK_POWER) = 200; 
}

std::vector<int> const&  Jetpack::get_effect()
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


