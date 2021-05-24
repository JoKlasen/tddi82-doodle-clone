#include "Threat.h"

Threat::Threat()
    : Threat{sf::Vector2f{0,0}}
{

}

Threat::Threat(sf::Vector2f pposition)
    : Entity{"",pposition, std::vector<sf::Rect<float>>{}}, damage{}, monster_speed{}, moving_right{false}, countdown{}, monstershift{}, hit{false}, rect{}, clock{}, hitPlayer{}
{
    clock.restart();
}

// Getters och setters
sf::Rect<float> Threat::getGlobalBounds() 
{
    return sprite.getGlobalBounds();
}
sf::FloatRect Threat::getGlobalBounds() const
{
    return sprite.getGlobalBounds();
}

void Threat::update() 
{
    if(moving_right)
    {
        move(sf::Vector2f(monster_speed, 0));
        if(getPosition().x + sprite.getGlobalBounds().width >= screen_width)
            moving_right = false;
    }
    else
    {
        move(sf::Vector2f(-monster_speed, 0));
        if(getPosition().x <= 0)
            moving_right = true;
    }
}

void Threat::render( sf::RenderTarget & target)
{
    int shake;
    if(hit)
        shake = 6;
    else
        shake = 3;    
    if(countdown >= shake)
        countdown = 0;
    sf::IntRect temp{rect.left + countdown++, rect.top + countdown++, rect.width, rect.height};
    
    sprite.setTextureRect(temp);
    target.draw(sprite);

    if(hit)
    {
        monstershift.setPosition(sprite.getPosition());
        monstershift.setTextureRect(temp);
        target.draw(monstershift);
    }

    if(hit && clock.getElapsedTime().asSeconds() >= 2)
        hit = false;

}
void Threat::handle_collision( Entity & )
{
    if(hit)
        return;
    hit = true;
    hitPlayer = true;
    clock.restart();
}

bool Threat::isHit()
{
    if(hitPlayer)
    {
        hitPlayer = false;
        return true;
    }
        
    return false;    
}

int Threat::get_damage()
{
    return damage;
}

// Monster Blue

MonsterBlue::MonsterBlue(sf::Vector2f pposition)
    : Threat(pposition)
{
    rect = monster_blue;
    sprite.setTexture(Texture_Manager::load(spritesheet_monster));
    sprite.setTextureRect(rect);

    monstershift.setTexture(Texture_Manager::load(spritesheet_monster));
    monstershift.setTextureRect(rect);
    monstershift.setColor(sf::Color(255, 0 , 0, 200));
    damage = 1;
    monster_speed = 3;
}


// Monster red

MonsterRed::MonsterRed(sf::Vector2f pposition)
    : Threat{pposition}
{
    rect = monster_red;
    sprite.setTexture(Texture_Manager::load(spritesheet_monster));
    sprite.setTextureRect(rect);

    monstershift.setTexture(Texture_Manager::load(spritesheet_monster));
    monstershift.setTextureRect(rect);
    monstershift.setColor(sf::Color(255, 0 , 0, 200));
    damage = 2;
    monster_speed = 5;
}