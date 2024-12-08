#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Car : public Drawable
{
public:
	Car(float posX);
	Texture Car_Texture;
	Sprite s;
	float posX;
	float posY;
	float speed = 18;
	int points = 0;
	float rnd;
	bool a = 0;


	void Falling();
	void Spawn();
	void AddPoints();
	bool ChceckCollision(float x, float y);
	void Reset();
	void restart();
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
Car::Car(float posX)
{
	Car_Texture.loadFromFile("D:/_Си++_/kursach cars/Images/enemy.png");


	s.setTexture(Car_Texture);
	s.setScale(0.5f, 0.5f);
	s.setPosition(20, 20);
	s.setOrigin(100, 100);
	s.setRotation(180);

	posY = 0;
	this->posX = posX;
	rnd = rand() % 6 + 1;
	Spawn();
}

void Car::Falling()
{
	posY = s.getPosition().y;

	if (posY < 1200)
	{
		s.setPosition(posX, posY + speed);
	}

	if (posY >= 1198)
	{
		Spawn();

	}
}

void Car::AddPoints()
{
	points += 10;
}

void Car::Spawn()
{
	posY = 0;
	rnd = rand() % 6 + 1;

	if (rnd == 1)
		posX = 90;

	if (rnd == 2)
		posX = 250;

	if (rnd == 3)
		posX = 380;

	if (rnd == 4)
		posX = 500;

	if (rnd == 5)
		posX = 640;

	if (rnd == 6)
		posX = 800;


	s.setPosition(posX, posY);

}

bool Car::ChceckCollision(float playerX, float playerY)
{
	// Проверка столкновения с игроком
	const float carWidth = 65; // Ширина машины (на основании вашего условия)
	const float carHeight = 135; // Высота машины (на основании вашего условия)

	// Проверка, пересекаются ли прямоугольники машины и игрока
	if (this->posX < playerX + carWidth && this->posX + carWidth > playerX &&  // по оси X
		this->posY < playerY + carHeight && this->posY + carHeight > playerY)  // по оси Y
	{
		return true;
	}

	return false;
}

void Car::Reset() {
	points = 0;
	a = 0;
	posX = -200; // Or some other value off-screen to the left
	posY = -200; // Or some other value off-screen at the top
	Spawn();
}

void Car::restart() {
	Reset();
}