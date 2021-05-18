#include "Game_World.h"
#include <SFML/Graphics.hpp>
#include "constants.h"
#include "Manager.h"
#include <iostream>

sf::Sprite ScoreBarFill;

Game_World::Game_World ()
    : score{0}, entities{}, player{}, platform{ 150, 630 }, platform2{0, 630},//platform{ sf::Vector2f(50, 50) }
      scoreBar{sf::Vector2f(screen_width, 40)}, scoreText{}, ScoreBarFill{Texture_Manager::load("./resources/images/testbar3.png")}
{
    scoreBar.setPosition(0,0);
    scoreBar.setFillColor(sf::Color(128, 128, 128, 128)); // Genomskinlig grå färg

    ScoreBarFill.setPosition(0, 35);

    scoreText.setFont(Font_Manager::load(font_file));
    scoreText.setString("Score: 0");
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setCharacterSize(30);
    scoreText.setPosition(10,3);

    //entities.push_back( Platform {} );
}

void Game_World::handle_event (sf::Event event)
{
    //player.handle_input();

}

void Game_World::update ()
{
    // Flytta spelaren i X-led efter knappinput, kör wraparound på kanter om nödvändigt och flyttar sedan spelaren i Y-led enligt acc.
    player.update ();

    // Flytta ner platform(ar) och räkna poäng
    if (player.getPosition().y < screen_height/2 - 50)
        {
            player.setPosition(sf::Vector2f (player.getPosition().x, screen_height/2 - 50) );
            score += -(player.getAcceleration())*10;
            // Byt senare ut följande mot for loop för vector<entity>
            platform.move(0, -(player.getAcceleration()));
            platform2.move(0, -(player.getAcceleration()));
            scoreText.setString("Score: " + std::to_string(score/10));
            //std::cout << score/10 << std::endl;        // debugg
        }


    // Kollisionslogik för spelare mot generell entiry
    // TESTFIXASAP; Senare for each platform i vector<entity>
    if (testPlayerCollision(platform))
        {
            platform.handle_collision(player);
        }
    if (testPlayerCollision(platform2))
        {
            platform2.handle_collision(player);
        }

    platform.update();
    platform2.update();
    // for ( auto & ent : entities )
    // {
    //     ent.update ();
    // }

    // TESTFIXASAP;
    // Kollision med golv för testvärld denna bör bytas ut mot att sätta game_over-flaggan för att spelet ska ta slut, funkar som kollision just nu för att göra test enklare.
    if ( player.getPosition().y >= (screen_height - 30) ) // 30 = player->dimensions.y/2 byt ut mot någon form av getBounds().height/2
        player.setAcceleration(-10);
}

void Game_World::render (sf::RenderTarget & target)
{
    // for ( auto & ent : entities )
    // {
    //     ent.render (target);
    platform.render(target);
    platform2.render(target);
    // }
    

    player.render(target);

    target.draw(scoreBar);
    target.draw(ScoreBarFill);
    target.draw(scoreText);
}

bool Game_World::testPlayerCollision (Entity const & obj)
{   
    // TESTFIXASAP; 60, 60, 70 och 20 representerar här spelarens hårdkodade width och height, platformens bredd respektive platformens höjd. Bör bytas ut mot getBounds eller liknande för generella entities
    if ( (player.getPosition().x + 60 > obj.getPosition().x) && 
         (player.getPosition().x < obj.getPosition().x + 70) &&
         (player.getPosition().y + 60 >= obj.getPosition().y) &&
         (player.getPosition().y + 60 < obj.getPosition().y + 20) &&
         (player.getAcceleration() > 0) )
        {
            return true;
        }
    else
        {
            return false;
        }
}

//void Game_World::