#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include "constants.h"
#include "Manager.h"
#include "Sounds.h"

#include <vector>
#include <string>


class Entity
{
public:
    virtual ~Entity () = default;
    Entity();
    Entity( std::string pname = std::string{},
            //sf::Texture ptexture = sf::Texture{},
            //sf::IntRect psubtexture = sf::IntRect{},
            sf::Vector2f pposition = sf::Vector2f{},
            std::vector<sf::Rect<float>> pCollisionContainer = std::vector<sf::Rect<float>>{});

    virtual void render( sf::RenderTarget & ) = 0;
    virtual void handle_collision( Entity & ) = 0;
    virtual void update() = 0;
    
    // Getters och setters
    virtual sf::Rect<float> getGlobalBounds() = 0;
    virtual sf::FloatRect getGlobalBounds() const  = 0; 

    std::string getName() const;
    void setName(std::string value);

    sf::Vector2f getPosition() const;
    void setPosition(sf::Vector2f value);
    void setPosition(float valueX, float valueY);

    void move(sf::Vector2f const & value);
    void move(float const & offsetX, float const & offsetY); 

    double getAcceleration() const;
    void setAcceleration(double value);     // Inte helt hundra på om dessa behövs eller inte

    virtual void setCollisionSprite();      // Just nu för att ändra player

    void resetAcceleration();

    std::vector<sf::Rect<float>> getCollisionContainer();

    std::vector<std::tuple<int, int>> collisionList;
protected:
    // Datamedlemmar
    std::string name;
    sf::Sprite sprite;
    static double acceleration;
    std::vector<sf::Rect<float>> CollisionContainer;    // ska vara collision box

};


#endif // ENTITY_H
