#include "../include/Game.h"
#include "../include/constants.h"

int main ()
{
    Game g { "Hopp,hopp!", screen_width, screen_height };
    g.start ();
}
