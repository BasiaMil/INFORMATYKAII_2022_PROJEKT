#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include<random>
#include<iostream>
#include <string>#pragma once

class gwiazdozbior {
private:
	std::random_device rd;
	int N;
	sf::CircleShape* gwiazdy;
public:
	gwiazdozbior(int Nt);
	void draw(sf::RenderWindow& window);
	void move();

};
