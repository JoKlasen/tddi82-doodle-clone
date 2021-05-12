#pragma once

#include <string>
#include <unordered_map>
#include <utility>
#include <stdexcept>
#include <SFML/Graphics.hpp>

template <typename T>
class Manager
{

public:

    
    static T & load (const std::string & file); // filnamnet utgår från root ex. (./resources/images/Apple.png)


private:

    static std::unordered_map <std::string, std::unique_ptr<T>> resource_map;
    
};

#include "../src/Manager.tcc"
