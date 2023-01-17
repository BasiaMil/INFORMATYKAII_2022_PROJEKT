#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include<random>
#include<iostream>
#include <string>
#include"interfejs.h"


interfejs::interfejs(sf::Vector2f wymiary) {
	this->wymiary.x = wymiary.x;
	this->wymiary.y = wymiary.y;
	sf::Vector2f window_size(800.f, 600);
	init(window_size);
}
interfejs::~interfejs() {
	delete prostokat;
	prostokat = NULL;
	delete lewy;
	lewy = NULL;
	delete prawy;
	prawy = NULL;
	delete dolsrodek;
	dolsrodek = NULL;
	delete gorasrodek;
	gorasrodek = NULL;
}
void interfejs::draw(sf::RenderWindow& window) {
	window.draw(*prostokat);
	window.draw(*lewy);
	window.draw(*prawy);
	window.draw(*dolsrodek);
	window.draw(*gorasrodek);
}

void interfejs::setText(sf::Text* lewy, sf::Text* prawy, sf::Text* dolsrodek, sf::Text* gorasrodek) {

	font = new sf::Font;
	font->loadFromFile("arial.ttf");
	lewy->setFont(*font);
	prawy->setFont(*font);
	dolsrodek->setFont(*font);
	gorasrodek->setFont(*font);

	lewy->setString("Punkty:");
	lewy->setFillColor(sf::Color(45, 8, 210));
	lewy->setPosition(10.f, 5.f);

	prawy->setString("Trudnosc:");
	prawy->setFillColor(sf::Color(24, 200, 55));
	prawy->setPosition(600.f, 5.f);

	dolsrodek->setString("PAUZA/POMOC - F1");
	dolsrodek->setFillColor(sf::Color(80, 250, 8));
	dolsrodek->setPosition(270.f, 550.f);

	gorasrodek->setString("Zycia");
	gorasrodek->setFillColor(sf::Color(40, 80, 160));
	gorasrodek->setPosition(310.f, 5.f);
}

void interfejs::init(sf::Vector2f window_size) {

	lewy = new sf::Text;
	prawy = new sf::Text;
	dolsrodek = new sf::Text;
	gorasrodek = new sf::Text;
	prostokat = new sf::RectangleShape;

	prostokat->setPosition(20.f, 50.f);
	prostokat->setSize(wymiary);
	prostokat->setFillColor(sf::Color(10, 200, 100));

	setText(lewy, prawy, dolsrodek, gorasrodek);

}