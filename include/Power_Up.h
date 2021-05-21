#ifndef POWER_UP_H
#define POWER_UP_H
#include <SFML/Graphics.hpp>
#include "Manager.h"
#include <vector>


// basklassen
class Power_Up
{
    public:
    static const int SPRING_POWER = 0;
    static const int LIFE_POWER = 1;
    static const int SHIELD_POWER = 2;
    static const int JETPACK_POWER = 3;

    Power_Up();
    virtual ~Power_Up () = default;

    virtual void render(sf::RenderTarget & target);
    virtual bool is_active();
    virtual void set_pos(sf::Vector2f const&);
    virtual void set_active(bool);
    virtual std::vector<int> const&  get_effect() = 0;

    protected:
    sf::Sprite sprite;
    sf::RectangleShape shape{sf::Vector2f(20, 20) }; // shape för test
    bool active;
    std::vector<int> effects; // spring, shield, extra-life 
    sf::Texture texture;
};






class Spring: public Power_Up
{
    public: 
    Spring();
    std::vector<int> const& get_effect() override;
    void set_pos(sf::Vector2f const&) override;
    void render(sf::RenderTarget & target) override;
    private:
    
};
class Shield: public Power_Up
{
    public: 
    Shield();
    std::vector<int> const&  get_effect() override;
    private:
    
};

class Extra_Life: public Power_Up
{
    public: 
    Extra_Life();
    std::vector<int> const&  get_effect() override;
    private:
    
};
class Jetpack: public Power_Up
{
    public: 
    Jetpack();
    std::vector<int> const&  get_effect() override;
    private:
    
};
class Empty_Power: public Power_Up
{
    public: 
    Empty_Power();
    void render(sf::RenderTarget & target) override;
    bool is_active() override;
    void set_pos(sf::Vector2f const&) override;
    std::vector<int> const& get_effect() override;
    private:
    
};

#endif