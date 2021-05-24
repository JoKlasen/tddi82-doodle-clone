#include "Sounds.h"

sf::Sound Sounds::m_jump{};
sf::Sound Sounds::spring_sound{};
sf::Sound Sounds::rocket_sound{};
sf::Sound Sounds::damage_sound{};

void Sounds::jump ()
{
    Sounds::m_jump.setBuffer(Sound_Manager::load(jump_file)); 

    m_jump.play();
}

void Sounds::spring ()
{
    Sounds::spring_sound.setBuffer(Sound_Manager::load(spring_sound_file)); 

    spring_sound.play();
}
void Sounds::rocket()
{
    Sounds::rocket_sound.setBuffer(Sound_Manager::load(rocket_sound_file)); 

    rocket_sound.play();
}
void Sounds::damage()
{
    Sounds::damage_sound.setBuffer(Sound_Manager::load("./resources/sounds/mixkit-small-hit-in-a-game-2072.wav")); 

    damage_sound.play();
}