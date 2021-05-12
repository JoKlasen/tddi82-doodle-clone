#include "Menu_State.h"
#include "State.h"
#include "Manager.h"
#include "constants.h"

sf::CircleShape shape(100.f);

Menu_State::Menu_State()
    : play{false}, exit_game{false}, high_score{false}, im1{}
{
    im1 = Manager<sf::Image>::load("Apple.png");
    

}

void Menu_State::handle_event(sf::Event event)
{
    
}
void Menu_State::update()
{
   
    shape.setFillColor(sf::Color::Green);
}
void Menu_State::render(sf::RenderTarget & target)
{
    target.draw(shape);

    sf::Texture texture;
    if ( !texture.loadFromFile ("Apple.png") )
    {
        // gick inte att ladda bilden
        throw std::logic_error{"kunde inte ladd fil hej hoppsan"};
    }
    
    // skapa sprite
    sf::Sprite sprite { texture };
    sprite.setPosition (screen_width / 2, screen_height / 2);

    // sätt origin på sprite till mitten
    auto size { texture.getSize () };
    sprite.setOrigin (size.x / 2, size.y / 2);

    target.draw(sprite);

}
int Menu_State::get_next_state() 
{
    return MENU_STATE;
}