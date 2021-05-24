#include "Entity.h"
#include "Player.h"
#include "Power_Up.h"
#include "Sounds.h"
#include "constants.h"
#include <vector>
#include <iostream>

std::vector<int> Player::power_vec{0,0,0,0,0,0,0,0};

Player::Player()
    : Entity{ "Player", sf::Vector2f{}, std::vector<sf::Rect< float >>{} }, life {3}, shield{false}, jetpack{false}, power_sprite{}, shield_shape{100, 50}, fade{}, clock{}
    {
        sprite.setTexture(Texture_Manager::load(spritesheet_file));
        sprite.setTextureRect(player_right);
        sprite.setPosition( (screen_width/2 - sprite.getGlobalBounds().width/2), (screen_height/2 - sprite.getGlobalBounds().height/2) );

        power_sprite.setTexture(Texture_Manager::load(spritesheet_power_file));
        
        //sprite.setScale(0.75, 0.75);
        
        initCollisionContainer();
        
        shield_shape.setOrigin(50, 50);
        shield_shape.setFillColor(sf::Color(0, 200, 0, 150));

        clock.restart();
        
    }
    

////////////////
// Public functions
////////////////

void Player::render( sf::RenderTarget & target)
{
    target.draw(sprite);
    drawJetpack(target);
    drawShield(target);
}





void Player::handle_collision( Entity & ent)
{
   
    while (!collisionList.empty())
    {

        
        collisionList.pop_back();
    }
}


void Player::update()
{
   // std::cout << life << std::endl;
    
    handle_input();

    // Hopp/fall
    Entity::acceleration += 0.2;    // Öka fallhastighet
    sprite.move(0, Entity::acceleration);
    if (Entity::acceleration >= 0)  // Om "studsande" sprite, byt till "vanlig"
    {
        if (facing_right)
        {   
            sprite.setTextureRect(player_right);
        }
        else
        {
            sprite.setTextureRect(player_left);
            
        }
    }

   
    //update player effects
    update_power_effect();
}


void Player::handle_input()
{
    
    // Flytta spelaren vid knappar
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {   
        if (facing_right)
        {   
            facing_right = false;
        }
        if (acceleration < 0)
            setCollisionSprite();
        else
            sprite.setTextureRect(player_left);
        move(sf::Vector2f(-4, 0));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {   
        if (!facing_right)
        {
            facing_right = true;
        }
        if (acceleration < 0)
            setCollisionSprite();
        else
            sprite.setTextureRect(player_right);
        move(sf::Vector2f(4, 0));
    }

    // wrap around
    if ( getPosition().x + getGlobalBounds().width/2 > screen_width )
        setPosition(-(getGlobalBounds().width/2) , getPosition().y);
    else if ( getPosition().x < (0 - getGlobalBounds().width/2) )
        setPosition( (screen_width - getGlobalBounds().width/2) , getPosition().y);
}


sf::Rect<float> Player::getGlobalBounds()
{
    return sprite.getGlobalBounds();
}

sf::FloatRect Player::getGlobalBounds() const
{
    return sprite.getGlobalBounds() ;
}

// bool Player::isFacingRight()
// {
//     return facing_right;
// }

void Player::setCollisionSprite()
{
    if (facing_right)
        sprite.setTextureRect(player_right_landing);
    else
        sprite.setTextureRect(player_left_landing);
}

int Player::get_life()
{
    return life;
}

void Player::set_life(int new_life)
{
    life = new_life;
}

void Player::giveDamage(int damage)
{
    if(!shield)
    {
        life -= damage;
        acceleration = -10;
    }
        

}
////////////////
// Private functions
////////////////

void Player::initCollisionContainer()
{
    auto box = sprite.getLocalBounds();
    box.width = box.width * sprite.getScale().x;
    box.height = box.height * sprite.getScale().y;
    CollisionContainer.push_back(sprite.getLocalBounds()); //might become an issue
    
    CollisionContainer.push_back(player_legs_box);
    CollisionContainer.push_back(player_body_box);
}

void Player::update_power_effect()
{
    // skapar bara referens till power_vec för läsbarhet
    int & spring_power = power_vec.at(Power_Up::SPRING_POWER);
    int & life_power = power_vec.at(Power_Up::LIFE_POWER);
    int & shield_power = power_vec.at(Power_Up::SHIELD_POWER);
    int & jetpack_power = power_vec.at(Power_Up::JETPACK_POWER);

    
    if(spring_power > 0)
    {
        // make player jump
        Entity::acceleration = -spring_power;
        Sounds::spring();
        spring_power = 0;
    }
    if(life_power > 0)
    {
        // add life to player
        if(life < 3)
        {   
            life += life_power;
            life_power = 0;
        }   
        
    }
    if(shield_power > 0 && !shield)
    {
        // do something if shield is on
        shield = true;
        clock.restart();
        shield_power = 0;

    }
    if(jetpack_power > 0)
    {
        jetpack = true;
        // do something if shield is on
        acceleration = -30;
        if(jetpack_power-- == 200)
            Sounds::rocket();

        if(jetpack_power == 0)
            jetpack = false;

    }

    if(shield && clock.getElapsedTime().asMilliseconds() > 10000 && shield == true) // räknar till 10 sekunder och stänger sedan av shield
    {
        shield = false;
        shield_power = 0;
        shield_shape.setFillColor(sf::Color(0, 200, 0, 150));
        fade = 0;
        std::cout << "over" << std::endl;


    }
    if(shield && clock.getElapsedTime().asMilliseconds() > 5000) // fade efter 5 sekunder
    {
        if(fade <= 300)
            shield_shape.setFillColor(sf::Color(0, 200, 0, 150- fade++/2));


        //std::cout << fade << std::endl;    
        
    }


     if(facing_right && jetpack)
    {
        power_sprite.setTextureRect(jetpack_fly_r);
        power_sprite.setPosition(getPosition().x + 10, getPosition().y + 40);
    }
    if(!facing_right && jetpack)
    {
        power_sprite.setTextureRect(jetpack_fly_l);
        power_sprite.setPosition(getPosition().x + 76, getPosition().y + 40);
    }
   
}
void Player::drawShield(sf::RenderTarget & target)
{
    if(shield)
    {
        shield_shape.setPosition(getPosition().x +5, getPosition().y -5);
        target.draw(shield_shape);
    }
}

void Player::drawJetpack(sf::RenderTarget & target)
{
    if(jetpack)
    {
        power_sprite.setScale(1.5, 1.5);
        target.draw(power_sprite);
    }
}

//static function

void Player::set_power(std::vector<int> vec)
{
    power_vec = vec;
    
}



