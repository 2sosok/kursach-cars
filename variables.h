#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include <SFML/Audio.hpp>
#include <string>
#include <fstream>
#include <chrono>
#include <thread>

using namespace sf;
using namespace std;



Font font_menu;
std::vector<sf::Text> text_menu_items;
vector<string> menu_items = { "Start new game","Settings","Quit" };

Font font_settings_menu;
std::vector<sf::Text> text_settings_menu_items;
vector<string> settings_menu_items = { "Volume","Difficult", "Theme"};

Font font_authorization_menu;
std::vector<sf::Text> text_authorization_menu_items;
vector<string> authorization_menu_items = { "Name","Enter" };

int authorization_name1 = 2;
int authorization_name2 = 2;
int authorization_name3 = 2;


std::vector<sf::Text> text_authorization_menu_items1;
vector<int> authorization_menu_items1 = { authorization_name1, authorization_name2,authorization_name3 };

int current_main_menu_item_index = 0;
int current_setting_menu_item_index = 0;
int current_authorization_menu_item_index = 0;

bool gameover = true;

bool gamepaused = false;

const int MENU_MAIN = 0;
const int MENU_SETTINGS = 1;
const int MENU_AUTHORIZATION = 2;
const int GAMMING = 1;
const int MENU = 0;
int current_state = MENU;

int current_menu = MENU_MAIN;


int current_difficult_menu_item_index = 0;

int settings_volume = 50;

int settings_difficult = 2;

int theme = 0;

const int FIELD_CELL_TYPE_NONE = 0;
const int FIELD_CELL_TYPE_CAR = -1;

Font game_over;
Text youlose;

Font font_authorization;
Text loginText("Login:", font_authorization, 30);


SoundBuffer menu_navigate;
Sound navigate;

Texture Background_Texture, Bar_Texture;
Sprite Background, Bar;

