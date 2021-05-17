#ifndef PLATFORM_H
#define PLATFORM_H

#include "Entity.h"
#include <SFML/Graphics.hpp>
#include "Manager.h"


class Platform : public Entity
{



public:
   
    Platform();
    Platform( float, float );   //position 
    Platform( sf::Vector2f );   //position 
    Platform(std::string name, sf::Vector2f position= sf::Vector2f(), std::vector<int> CollisionContainer = std::vector<int>{});
    
    void render( sf::RenderTarget & ) override;
    void handle_collision( Entity const& ) override;
    void update() override;

private:
   

    class Power_Up: public Entity
    {
        
    public:

        Power_Up(int k)
            : sprite{}, active{true}
        {
            sprite.setTexture(Manager<sf::Texture>::load("./resources/images/Doodle_Jump.png"));
            //sprite.setPosition();
        }

        void render( sf::RenderTarget & target) 
        {
            target.draw(sprite);
        }
        void handle_collision( Entity const& )
        {
            if(active)
            {
                 // gör något med spelaren
            }
           // set actrive false
           active = false; 
        }
        void update()
        {

        }

    private:
        sf::Sprite sprite;
        bool active;
    };


    void default_shape();
    sf::RectangleShape shape{ sf::Vector2f(75, 20) };
    //Platform::Power_Up power_up;
   

};

#endif