#pragma once


int const screen_width  { 532 };
int const screen_height { 850 };


int const PLAYER_ANY{0};
int const PLAYER_LEGS{1};
int const PLAYER_HEAD{2};

int const PLATFORM_ANY{0};
std::string const font_file         {"./resources/fonts/DoodleJump.ttf"};
std::string const background_file   {"./resources/images/Background.png"};
std::string const spritesheet_file  {"./resources/images/sprite_sheet.png"};
std::string const hs_file           {"./resources/high_score.txt"};
double const fps { 60.0 };

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
