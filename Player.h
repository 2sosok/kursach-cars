#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

const int window_width = 900;
const int window_height = 1300;


class Player : public Drawable
{
public:
    Player();
    Texture Player_Texture;
    Sprite s;

    float speed = 16;
    float BeginX = 450;
    float High = 1000;
    float pos;

    void GoRight();
    void GoLeft();

    void Reset();

private:

    Sprite m_sprite;
    Texture m_texture;
    VertexArray m_vertices;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(m_sprite, states);
        states.texture = &m_texture;
        target.draw(m_vertices, states);
    }



};

Player::Player()
{
    Player_Texture.loadFromFile("D:/_Си++_/kursach oop/images/Player.png");
   

    s.setTexture(Player_Texture);
    s.setScale(0.5f, 0.5f);
    s.setPosition(BeginX, High);

}

void Player::GoRight()
{
    pos = s.getPosition().x;

    if (pos < 770)
        s.setPosition(pos + speed, High);
}

void Player::GoLeft()
{
    pos = s.getPosition().x;

    if (pos > 50)
        s.setPosition(pos - speed, High);
}

void Player::Reset() {
    pos = BeginX;
    s.setPosition(pos, High); // Update both x and y positions
}
