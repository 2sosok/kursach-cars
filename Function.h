#pragma once
#include "Car.h"
#include "Player.h"
#include <vector>
#include <string>
#include "variables.h"
#include "Car.h"
#include "Player.h"



void init_game() {
	srand(time(NULL));
	Background_Texture.loadFromFile("D:/_Си++_/kursach oop/images/Road.jpg");
	Bar_Texture.loadFromFile("D:/_Си++_/kursach oop/images/Bar.jpg");

	Background.setTexture(Background_Texture);
	Bar.setTexture(Bar_Texture);

	Bar.setPosition(0, 1200);

	font_menu.loadFromFile("D:/c++/kursach/font/PixeloidSansBold-PKnYd.ttf");

	font_settings_menu.loadFromFile("D:/c++/kursach/font/PixeloidSansBold-PKnYd.ttf");

	font_authorization_menu.loadFromFile("D:/c++/kursach/font/PixeloidSansBold-PKnYd.ttf");

	game_over.loadFromFile("D:/c++/kursach/font/PixeloidSans-mLxMm.ttf");
	youlose.setFont(game_over);

	font_authorization.loadFromFile("D:/c++/kursach/font/PixeloidSans-mLxMm.ttf");

	menu_navigate.loadFromFile("D:/c++/kursach/sounds/270324__littlerobotsoundfactory__menu_navigate_00.wav");
	navigate.setBuffer(menu_navigate);


	for (int i = 0; i < menu_items.size(); i++) {
		text_menu_items.emplace_back(sf::Text());
		text_menu_items.back().setString(menu_items.at(i));
		text_menu_items.back().setFont(font_menu);
		text_menu_items.back().setCharacterSize(40);

	}

	for (int i = 0; i < settings_menu_items.size(); i++) {
		text_settings_menu_items.emplace_back(sf::Text());
		text_settings_menu_items.back().setString(settings_menu_items.at(i));
		text_settings_menu_items.back().setFont(font_settings_menu);
		text_settings_menu_items.back().setCharacterSize(40);

	}

	for (int i = 0; i < authorization_menu_items.size(); i++) {
		text_authorization_menu_items.emplace_back(sf::Text());
		text_authorization_menu_items.back().setString(authorization_menu_items.at(i));
		text_authorization_menu_items.back().setFont(font_authorization_menu);
		text_authorization_menu_items.back().setCharacterSize(40);
	}

}

void draw_menu(sf::RenderWindow& window) {
	const float menu_items_interval = 20;

	float current_menu_item_offset_y = 0;

	float menu_item_max_width = 0;

	float const menu_width = window_width;
	float const menu_height = window_height;

	float const menu_position_x = (window_width - menu_width) / 2;
	float const menu_position_y = (window_height - menu_height) / 2;



	for (int i = 0; i < text_menu_items.size(); i++) {

		text_menu_items.at(0).setString(menu_items.at(0) = "Start new game");

		
		if (gamepaused) {
			text_menu_items.at(0).setString(menu_items.at(0) = "Continue");

		}


		text_menu_items.at(i).setPosition(window_width / 2 - 150, current_menu_item_offset_y + 500);
		text_menu_items.at(i).setFillColor(current_main_menu_item_index == i ? Color(224, 224, 224) : sf::Color(128, 128, 128));
		current_menu_item_offset_y += text_menu_items.at(i).getLocalBounds().height + menu_items_interval;
		menu_item_max_width = max(menu_item_max_width, text_menu_items.at(i).getLocalBounds().width);


	}


	sf::RectangleShape menu_rect(sf::Vector2f(menu_width, menu_height));
	menu_rect.setPosition(menu_position_x, menu_position_y);
	menu_rect.setFillColor(Color::White);
	switch (theme) {
	case 0:
		menu_rect.setFillColor(Color(181, 184, 177));
		break;
	case 1:
		menu_rect.setFillColor(Color(78, 87, 84));
		break;

	case 2:
		menu_rect.setFillColor(Color(71, 74, 81));

		break;

	case 3:
		menu_rect.setFillColor(Color(141, 145, 122));
		break;

	case 4:
		menu_rect.setFillColor(Color(67, 75, 77));
		break;
	case 5:
		menu_rect.setFillColor(Color(108, 105, 96));


	}
	window.draw(menu_rect);

	for (int i = 0; i < text_menu_items.size(); i++) {
		text_menu_items.at(i).move(menu_position_x, menu_position_y);
		window.draw(text_menu_items.at(i));
	}



}

void draw_settings_menu(sf::RenderWindow& window) {
	const float settings_menu_items_interval = 20;

	float current_settings_menu_item_offset_y = 0;

	float settings_menu_item_max_width = 0;




	for (int i = 0; i < text_settings_menu_items.size(); i++) {

		text_settings_menu_items.at(i).setPosition(window_width / 2 - 150, current_settings_menu_item_offset_y + 500);
		text_settings_menu_items.at(i).setFillColor(current_setting_menu_item_index == i ? Color(224, 224, 224) : sf::Color(128, 128, 128));
		current_settings_menu_item_offset_y += text_settings_menu_items.at(i).getLocalBounds().height + settings_menu_items_interval;
		settings_menu_item_max_width = max(settings_menu_item_max_width, text_settings_menu_items.at(i).getLocalBounds().width);


		if (settings_menu_items.at(i) == "Volume") {
			text_settings_menu_items.at(i).setString(settings_menu_items.at(i) + ": " + to_string(settings_volume));
		}
		if (settings_menu_items.at(i) == "Difficult") {
			text_settings_menu_items.at(i).setString(settings_menu_items.at(i) + ": " + to_string(settings_difficult));
		}
		if (settings_menu_items.at(i) == "Theme") {
			text_settings_menu_items.at(i).setString(settings_menu_items.at(i) + ": " + to_string(theme));
		}

	}

	float const settings_menu_width = window_width;
	float const settings_menu_height = window_height;

	float const settings_menu_position_x = (window_width - settings_menu_width) / 2;
	float const settings_menu_position_y = (window_height - settings_menu_height) / 2;


	sf::RectangleShape settings_menu_rect(sf::Vector2f(settings_menu_width, settings_menu_height));
	settings_menu_rect.setPosition(settings_menu_position_x, settings_menu_position_y);
	settings_menu_rect.setFillColor(Color::White);
	switch (theme) {
	case 0:
		settings_menu_rect.setFillColor(Color(181, 184, 177));
		break;
	case 1:
		settings_menu_rect.setFillColor(Color(78, 87, 84));
		break;

	case 2:
		settings_menu_rect.setFillColor(Color(71, 74, 81));

		break;

	case 3:
		settings_menu_rect.setFillColor(Color(141, 145, 122));
		break;

	case 4:
		settings_menu_rect.setFillColor(Color(67, 75, 77));
		break;
	case 5:
		settings_menu_rect.setFillColor(Color(108, 105, 96));


	}
	window.draw(settings_menu_rect);

	for (int i = 0; i < text_settings_menu_items.size(); i++) {
		text_settings_menu_items.at(i).move(settings_menu_position_x, settings_menu_position_y);
		window.draw(text_settings_menu_items.at(i));
	}

}

void draw_authorization_menu(sf::RenderWindow& window) {
	const float authorization_menu_items_interval = 20;

	float current_authorization_menu_item_offset_y = 0;

	float authorization_menu_item_max_width = 0;

	float const authorization_menu_width = window_width;
	float const authorization_menu_height = window_height;

	float const authorization_menu_position_x = (window_width - authorization_menu_width) / 2;
	float const authorization_menu_position_y = (window_height - authorization_menu_height) / 2;



	for (int i = 0; i < text_authorization_menu_items.size(); i++) {
		text_authorization_menu_items.at(1).setString(authorization_menu_items.at(1) = "Enter");

		text_authorization_menu_items.at(i).setPosition(window_width / 2 - 150, current_authorization_menu_item_offset_y + 500);
		text_authorization_menu_items.at(i).setFillColor(current_authorization_menu_item_index == i ? Color(224, 224, 224) : sf::Color(128, 128, 128));
		current_authorization_menu_item_offset_y += text_authorization_menu_items.at(i).getLocalBounds().height + authorization_menu_items_interval;
		authorization_menu_item_max_width = max(authorization_menu_item_max_width, text_authorization_menu_items.at(i).getLocalBounds().width);


	}


	sf::RectangleShape authorization_menu_rect(sf::Vector2f(authorization_menu_width, authorization_menu_height));
	authorization_menu_rect.setPosition(authorization_menu_position_x, authorization_menu_position_y);
	authorization_menu_rect.setFillColor(Color::White);
	authorization_menu_rect.setFillColor(Color(181, 184, 177));
	window.draw(authorization_menu_rect);

	for (int i = 0; i < text_authorization_menu_items.size(); i++) {
		text_authorization_menu_items.at(i).move(authorization_menu_position_x, authorization_menu_position_y);
		window.draw(text_authorization_menu_items.at(i));
	}
	std::string inputName;
}

void draw_lose(sf::RenderWindow& window) {
	youlose.setString("YOU LOSE");
	youlose.setCharacterSize(120);
	youlose.setFillColor(Color::Red);
	youlose.setPosition((window_width - youlose.getLocalBounds().width + 1) / 2, (window_height - youlose.getLocalBounds().height + 1) / 2);
	window.draw(youlose);

}

void set_volume() {
	navigate.setVolume(settings_volume);
}

