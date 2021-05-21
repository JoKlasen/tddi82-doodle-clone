#ifndef SOUND_H
#define SOUND_H

#include <SFML/Audio.hpp>
#include "Manager.h"
#include "constants.h"


class Sounds
{
public:
    static void jump();

private:
    static sf::Sound m_jump; 

};


#endif //SOUND_H