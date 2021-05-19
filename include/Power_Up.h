#ifndef POWER_UP_H
#define POWER_UP_H
#include <SFML/Graphics.hpp>
#include "Manager.h"
#include <vector>



class Power_Up
{
    public:
    Power_Up();
    virtual ~Power_Up () = default;

    virtual void render(sf::RenderTarget & target);
    virtual bool is_active();
    virtual void set_pos(sf::Vector2f const&);
    virtual std::vector<int> const&  get_effect() = 0;

    protected:
    //sf::Sprite sprite;
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