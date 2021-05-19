#pragma once

#include <string>
#include <unordered_map>
#include <utility>
#include <stdexcept>
#include <SFML/Graphics.hpp>





/*
För att drawa en bild till window 
laddar man först ett Texture med bilden
genom att köra:

"texture = Manager<sf::Texture>::load("./resources/type/file");"

Därefter laddar man spriten med texture:

"sprite.setTexture(texture);"

Till sist kan man köra window.draw(sprite);
*/


template <typename T>
class Manager
{

public:

    
    static T & load (const std::string & file); // filnamnet utgår från root ex. (./resources/images/Apple.png)


private:

    static std::unordered_map <std::string, std::unique_ptr<T>> resource_map;
    
};

using Texture_Manager = Manager <sf::Texture>;
using Font_Manager    = Manager <sf::Font>;

#include "../src/Manager.tcc"
