
#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include<random>
#include<iostream>
#include <string>
#include"gwiazdozbior.h"

gwiazdozbior::gwiazdozbior(int Nt) {
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distX(1, 750);
	std::uniform_int_distribution<> distY(1, 550);
	std::uniform_int_distribution<> distR(10, 50);

	float x = 0, y = 0, R = 0;
	N = Nt;
	gwiazdy = new sf::CircleShape[N];

	for (int i = 0; i < N; i++) {
		x = distX(gen);
		y = distY(gen);
		R = distR(gen);

		gwiazdy[i] = sf::CircleShape(R);
		gwiazdy[i].setPosition(sf::Vector2f(x, y));
		gwiazdy[i].setScale(sf::Vector2f(0.03f, 0.03f));


	}
}

void gwiazdozbior::draw(sf::RenderWindow& window) {
	for (int i = 0; i < N; i++)
	{
		window.draw(gwiazdy[i]);
	}
}

void gwiazdozbior::move() {
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distX(1, 800);
	std::uniform_int_distribution<> distY(1, 600);
	std::uniform_int_distribution<> distXl(-20, 20);
	std::uniform_int_distribution<> distYl(-20, 20);
	for (int i = 0; i < N; i++)
	{
		gwiazdy[i].move(sf::Vector2f(distXl(gen), distYl(gen)));
		sf::Vector2f position = gwiazdy[i].getPosition();
		if (position.x > 800 || position.x < 0 || position.y > 600 || position.y < 0)
			gwiazdy[i].setPosition(distX(gen), distY(gen));
	}
}