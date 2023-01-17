#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include<random>
#include<iostream>
#include <string>
#include"Menu.h"


Menu::Menu(sf::Vector2f wymiary) {
	this->wymiary.x = wymiary.x;
	this->wymiary.y = wymiary.y;
	sf::Vector2f window_size(800.f, 600);
	init(window_size);
}
Menu::~Menu() {
	delete prostokat;
	prostokat = NULL;
	delete Nowa;
	Nowa = NULL;
	delete Wyniki;
	Wyniki = NULL;
	delete Wyjscie;
	Wyjscie = NULL;
	delete tlo;
	tlo = NULL;

}
void Menu::draw(sf::RenderWindow& window) {
	window.draw(*tlo);
	window.draw(*prostokat);
	window.draw(*Nowa);
	window.draw(*Wyniki);
	window.draw(*Wyjscie);

	
}

void Menu::setText(sf::Text* Nowa, sf::Text* Wyniki, sf::Text* Wyjscie) {

	font = new sf::Font;
	font->loadFromFile("arial.ttf");
	Nowa->setFont(*font);
	Wyniki->setFont(*font);
	Wyjscie->setFont(*font);

	Nowa->setString("1.NOWA GRA");
	Nowa->setFillColor(sf::Color(0, 0, 0));
	Nowa->setPosition(300.f, 200.f);
	
	Wyniki->setString("2.WYNIKI");
	Wyniki->setFillColor(sf::Color(0, 0, 0));
	Wyniki->setPosition(300.f, 280.f);

	Wyjscie->setString("3.EXIT");
	Wyjscie->setFillColor(sf::Color(0, 0, 0));
	Wyjscie->setPosition(300.f, 360.f);
}

void Menu::init(sf::Vector2f window_size) {

	Nowa = new sf::Text;
	Wyniki = new sf::Text;
	Wyjscie = new sf::Text;
	prostokat = new sf::RectangleShape;
	tlo = new sf::RectangleShape;
	
	prostokat->setPosition(20.f, 50.f);
	prostokat->setSize(wymiary);
	prostokat->setFillColor(sf::Color(10, 200, 10));

	tlo->setPosition(0.f, 0.f);
	tlo->setSize(sf::Vector2f(800.f,600.f));
	tlo->setFillColor(sf::Color(0, 0, 0));

	setText(Nowa, Wyniki, Wyjscie);

}