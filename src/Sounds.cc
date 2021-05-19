#include "Sounds.h"
#include <iostream>

sf::Sound Sounds::m_jump{};

void Sounds::jump ()
{
    Sounds::m_jump.setBuffer(Sound_Manager::load(jump_file)); 

    m_jump.play();
    //std::cout << "beep" << std::endl; //debugg
}