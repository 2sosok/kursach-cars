#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Car.h"
#include "Function.h"

using namespace sf;

void resetGame(Player& player, Car& car1, Car& car2, Car& car3, Car& car4, Car& car5) {


    car1.Reset();
    car2.Reset();
    car3.Reset();
    car4.Reset();
    car5.Reset();
    player.Reset();

    // Убедитесь, что после сброса состояния, игра переходит в GAMMING
    current_state = GAMMING;


}



void menu(sf::RenderWindow& window)
{
    switch (current_menu) {
    case MENU_MAIN:
        draw_menu(window);
        //navigate.play();
        break;
    case MENU_SETTINGS:
        draw_settings_menu(window);
        break;

    default: navigate.play(); break;
    }
}



int main()
{

    RenderWindow window(VideoMode(window_width, window_height), "Car Game", sf::Style::Close);
    init_game();
    
    Player player;

    Car car1(90);
    Car car2(180);
    Car car3(270);
    Car car4(360);
    Car car5(450);



    while (window.isOpen())
    {
        Event basics;
        while (window.pollEvent(basics))
        {

            if (basics.type == Event::Closed)
                window.close();
            switch(current_state){
            case MENU:
                if (basics.type == sf::Event::KeyPressed) {
                    if (current_state == MENU) {
                        // navigate.play();

                        if (current_menu == MENU_MAIN) {
                            switch (basics.key.code) {
                            case sf::Keyboard::Up:
                                current_main_menu_item_index--;
                                if (current_main_menu_item_index < 0) {
                                    current_main_menu_item_index = text_menu_items.size() - 1;
                                }
                                navigate.play();

                                break;
                            case sf::Keyboard::Down:
                                current_main_menu_item_index++;
                                if (current_main_menu_item_index > text_menu_items.size() - 1) {
                                    current_main_menu_item_index = 0;
                                }
                                navigate.play();

                                break;
                            case sf::Keyboard::Enter:
                                if (menu_items.at(current_main_menu_item_index) == "Start new game") {
                                    resetGame(player, car1, car2, car3, car4, car5); // Сброс состояния игры
                                    current_state = GAMMING;
                                }


                                if (menu_items.at(current_main_menu_item_index) == "Settings") {
                                    current_menu = MENU_SETTINGS;
                                    navigate.play();
                                }



                                if (menu_items.at(current_main_menu_item_index) == "Quit") {
                                    window.close();
                                    sleep(milliseconds(0));
                                }


                                break;

                            }

                        }
                        if (current_menu == MENU_SETTINGS) {
                            switch (basics.key.code) {
                            case sf::Keyboard::Up:
                                current_setting_menu_item_index--;
                                if (current_setting_menu_item_index < 0) {
                                    current_setting_menu_item_index = text_settings_menu_items.size() - 1;
                                }
                                navigate.play();
                                break;
                            case sf::Keyboard::Down:
                                current_setting_menu_item_index++;
                                if (current_setting_menu_item_index > text_settings_menu_items.size() - 1) {
                                    current_setting_menu_item_index = 0;
                                }
                                navigate.play();
                                break;
                            case sf::Keyboard::Right:
                                if (settings_menu_items.at(current_setting_menu_item_index) == "Volume") {
                                    settings_volume += 5;
                                    if (settings_volume > 100) {
                                        settings_volume = 0;
                                    }
                                    navigate.play();

                                }
                                if (settings_menu_items.at(current_setting_menu_item_index) == "Difficult") {
                                    settings_difficult += 1;
                                    if (settings_difficult > 3) {
                                        settings_difficult = 0;
                                    }
                                    navigate.play();

                                }
                                if (settings_menu_items.at(current_setting_menu_item_index) == "Theme") {
                                    theme += 1;
                                    if (theme > 5) {
                                        theme = 0;
                                    }
                                    navigate.play();

                                }


                                break;

                            case sf::Keyboard::Left:
                                if (settings_menu_items.at(current_setting_menu_item_index) == "Volume") {
                                    settings_volume -= 5;
                                    if (settings_volume < 0) {
                                        settings_volume = 100;
                                    }
                                    navigate.play();

                                }
                                if (settings_menu_items.at(current_setting_menu_item_index) == "Difficult") {
                                    settings_difficult -= 1;
                                    if (settings_difficult < 0) {
                                        settings_difficult = 3;
                                    }
                                    navigate.play();

                                }
                                if (settings_menu_items.at(current_setting_menu_item_index) == "Theme") {
                                    theme -= 1;
                                    if (theme < 0) {
                                        theme = 5;
                                    }
                                    navigate.play();

                                }

                                break;
                            case sf::Keyboard::Escape:
                                current_menu = 0;



                            }


                        }

                    }
                    if (current_state == GAMMING) {
                        switch (basics.key.code) {
                        case sf::Keyboard::Escape:
                            current_state = MENU;
                        }
                    }
                }
            }
        }
        window.setFramerateLimit(60);

        set_volume();

        
        if (current_state==MENU) {//Combine the conditions
            menu(window);
        }
        if (current_state==GAMMING) {

            // Обновление состояния машин
            car1.Falling();
            car2.Falling();
            car3.Falling();
            car4.Falling();
            car5.Falling();

            // Управление игроком

            if (Keyboard::isKeyPressed(Keyboard::Right)) player.GoRight();
            if (Keyboard::isKeyPressed(Keyboard::Left)) player.GoLeft();

            // Отрисовка
            window.draw(Background);
            window.draw(player.s);
            window.draw(car1.s);
            window.draw(car2.s);
            window.draw(car3.s);
            window.draw(car4.s);
            window.draw(car5.s);
            window.draw(Bar);



            if (car1.ChceckCollision(player.pos, player.High) == true)
            {
                resetGame(player, car1,car2, car3,car4, car5);
                navigate.play();
                current_state = MENU;
            }

            if (car2.ChceckCollision(player.pos, player.High) == true)
            {
                resetGame(player, car1, car2, car3, car4, car5);
                navigate.play();
                current_state = MENU;
            }

            if (car3.ChceckCollision(player.pos, player.High) == true)
            {
                resetGame(player, car1, car2, car3, car4, car5);
                navigate.play();
                current_state = MENU;
            }

            if (car4.ChceckCollision(player.pos, player.High) == true)
            {
                resetGame(player, car1, car2, car3, car4, car5);
                navigate.play();
                current_state = MENU;
            }

            if (car5.ChceckCollision(player.pos, player.High) == true)
            {
                resetGame(player, car1, car2, car3, car4, car5);
                navigate.play();
                current_state = MENU;
            }
            

        }


        window.display();
        

        

    }



}
