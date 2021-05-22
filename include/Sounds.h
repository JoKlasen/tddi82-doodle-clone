#ifndef SOUND_H
#define SOUND_H

#include <SFML/Audio.hpp>
#include "Manager.h"
#include "constants.h"


class Sounds
{
public:
    static void jump();
    static void spring();
    static void rocket();

private:
    static sf::Sound m_jump; 
    static sf::Sound spring_sound;
    static sf::Sound rocket_sound;
};


#endif //SOUND_H