#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>


class Entity
{
public:
    virtual ~Entity () = default;
    Entity();
    Entity( std::string pname,
            sf::Vector2f pposition,
            std::vector<sf::Rect< float >> pCollisionContainer);

    virtual void render( sf::RenderTarget & ) = 0;
    virtual void handle_collision( Entity & ) = 0;
    virtual void update() = 0;
    
    virtual sf::Rect< float > getGlobalBounds() = 0;
    //virtual void movement_behavior() = 0;         //? tycker att dena ska vara private och lokal för "läggre" klasser 

    void move(sf::Vector2f const & value);
    void move(float const & offsetX, float const & offsetY); 

    // Getters och setters

    std::string getName() const;
    void setName(std::string value);

    sf::Vector2f getPosition() const;
    void setPosition(sf::Vector2f value);

    double getAcceleration() const;
    void setAcceleration(double value);     // Inte helt hundra på om dessa behövs eller inte

    std::vector<sf::Rect< float >> getCollisionContainer();

    std::vector<std::tuple<int, int>> colitionList;
protected:
    std::string name;
    sf::Vector2f position;                  // sf::Vector2<float>
    static double acceleration;             // Ändrade denna, dels till double, för jag tror att vi bara behöver hålla koll på förändring i Y-led. Och dels till static för att jag tror att resten av planen kommer vara direkt beroende av spelaren. -Johan
    std::vector<sf::Rect< float >> CollisionContainer;    // ska vara collision box

};


#endif // ENTITY_H
