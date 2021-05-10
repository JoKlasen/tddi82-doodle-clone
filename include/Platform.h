#include "Entity.h"

#include <SFML/Graphics.hpp>
//#include <SFML>

//#include <CircleShape.hpp>

class Platform : public Entity
{
private:
    std::string name {"Platform"};

    //sf::CircleShape shape(10 , 10);
    //sf::CircleShape shape{100.f};


public:
    Platform();

    void render( sf::RenderTarget & ) override;
    void handle_collision( Entity const& ) override;
    void update() override;

};