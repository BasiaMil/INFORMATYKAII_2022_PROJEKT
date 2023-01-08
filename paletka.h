#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include<random>
#include<iostream>
#include <string>

class paletka {
private:
	sf::RectangleShape palletka;
	sf::Vector2f position;
	float xVel = 10;
	float yVel = 10;

public:
	paletka(float x_in, float y_in);
	void przesun(float x_in, float y_in);
	sf::RectangleShape getPaletka();
	sf::Vector2f getPos();
};