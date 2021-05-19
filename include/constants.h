#pragma once


int const screen_width  { 532 };
int const screen_height { 850 };

double const fps { 60.0 };

//Texture files
std::string const font_file         {"./resources/fonts/DoodleJump.ttf"};
std::string const background_file   {"./resources/images/Background.png"};
std::string const spritesheet_file  {"./resources/images/sprite_sheet.png"};
std::string const hs_file           {"./resources/high_score.txt"};

//Textures from sprite_sheet
sf::IntRect const green_platform        { 0, 1, 105, 30 };
sf::IntRect const red_platform_intact   { 0, 31, 105, 30 };
sf::IntRect const blue_platform         { 0, 61, 105, 30 };
sf::IntRect const white_platform        { 0, 91, 105, 30 };
sf::IntRect const red_platform_broken   { 0, 554, 105, 60 };
sf::IntRect const player_right          { 0, 121, 110, 80 };
sf::IntRect const player_left           { 0, 201, 110, 80 };
sf::IntRect const player_right_landing  { 0, 289, 110, 80 };
sf::IntRect const player_left_landing   { 0, 371, 110, 80 };
//Inte testade
sf::IntRect const spring1               { 0, 445, 45, 53 };
sf::IntRect const spring2               { 0, 501, 45, 53 };
sf::IntRect const squiggle              { 0, 614, 100, 5 };
sf::IntRect const key_left              { 92, 621, 16, 16 };
sf::IntRect const key_right             { 92, 641, 16, 16 };

//Sound files
std::string const jump_file         {"./resources/sounds/jump.wav"};