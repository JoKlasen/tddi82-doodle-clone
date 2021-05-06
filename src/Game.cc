#include "Game.h"
//#include "Events.h" 
//#include "Menu_State.h" 
//#include "State.h" 
#include "constants.h" 

using namespace sf;


Game :: Game (std::string const & title,
              unsigned            width,
              unsigned            height)
    : window { VideoMode { width, height },
               title, Style::Titlebar | Style::Close },
      //machine { nullptr },
      running { true }
{
}

void Game :: start ()
{
    Clock clock {}; // startar räkning
    while ( running )
    {

        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);

        // State & state { machine.current_state () };
        
        // handle_events (state);

        
        // Game_Event event {state.update ()};

      
        // window.clear (); // rensar skärmen

       
        // state.render (window); // state:s render körs

        
        // window.display (); // visar det som renderats

        
        // event.apply (machine, *this);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();

       
        delay (clock); // räknar ut delayen utifrån clock
    }
}

// void Game :: stop ()
// {
//     running = false;
// }

// void Game :: handle_events (State & state)  
// {
//     Event event;
//     while ( window.pollEvent (event) ) // hämtar alla event i queuen
//     {
//         if ( event.type == Event::Closed )  // kollar om man tryckt på kryss eller avsluta
//             running = false;

//         state.handle_event (event); // handle_event i State anropas
//     }
// }

void Game :: delay (sf::Clock & clock) const
{
    sleep (milliseconds (1000.0 / fps) - clock.getElapsedTime ());
    clock.restart ();
}
