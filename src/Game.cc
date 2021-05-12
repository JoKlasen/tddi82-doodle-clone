#include "Game.h"
#include "Menu_State.h" 
#include "Game_State.h" 
#include "High_Score_State.h" 
#include "State.h" 
#include "constants.h" 

using namespace sf;


Game::Game (std::string const & title, unsigned width, unsigned height)
        : window { VideoMode { width, height }, title, Style::Titlebar | Style::Close },
        states{},
        current_state{ MENU_STATE },
        running { true }
        
{
    // Insert all sates you want in your game in the states map
    states.insert(
        std::pair<int,
            std::unique_ptr<State>>({MENU_STATE, std::make_unique<Menu_State>()}));

    /*
    states.insert(std::pair<int,
            std::unique_ptr<State>>({GAME_STATE,
                                    std::make_unique<Game_State>()}));
     */
    states.insert(std::pair<int,
            std::unique_ptr<State>>({HIGH_SCORE_STATE,
                                    std::make_unique<High_Score_State>()}));
   
}

void Game::start ()
{
    Clock clock {}; // startar räkning
    while ( running )
    {
        // Handle user events e.g. mouse click or key pressed
        handle_events();

        // Let the current state do its update
        states.at(current_state) -> update();

        /*
         * clear fills the entire window with one color
         * (by default black) thus overwriting everything
         * that was drawn before.
         *
         * If we do not perform this step we allow for weird
         * graphical artifacts to show up.
         */
        window.clear ();

        // let the current state render itself onto the window
        states.at(current_state) -> render(window);

        /*
         * No drawn pixels will be shown in the window
         * until this function is called.
         *
         * All drawing operations are performed on a
         * hidden buffer in memory, so if we want them
         * to actually show up on the screen we have
         * make sure that the window switches to drawing
         * that buffer instead of its current one.
         * (This technique is called 'double buffering')
         */
        window.display ();
    
        /*
         * When all logic and rendering has been performed
         * we are now ready to update the current_state
         */
         current_state = states.at(current_state) -> get_next_state();

        /*
         * Wait if we still haven't reached the target
         * time for a frame.
         */
        delay (clock);
    }
}

void Game::handle_events ()
{
    /*
     * event is an object which contains all
     * relevant information for an event that
     * occured in the window (i.e. key-pressed,
     * mouse clicks etc.).
     *
     * The function 'pollEvent' takes the next
     * event in the event queue and places it
     * in the 'event' variable so that we can
     * read what that event was.
     *
     * While there are events in event queue
     * 'pollEvent' will return true.
     */
    Event event;
    while ( window.pollEvent (event) )
    {
        // Check if the window has been closed.
        // This event fires whenever the user
        // presses the X icon, or if the operating
        // system kills it.
        if ( event.type == Event::Closed )
            running = false;

        // send the event to 'state'
        states.at(current_state) -> handle_event (event);
    }
}

void Game::delay (sf::Clock & clock) const
{
    sleep (milliseconds (1000.0 / fps) - clock.getElapsedTime ());
    clock.restart ();
}
