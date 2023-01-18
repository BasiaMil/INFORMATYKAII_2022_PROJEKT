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
	delete Nowa;
	Nowa = NULL;
	delete Wyniki;
	Wyniki = NULL;
	delete Wyjscie;
	Wyjscie = NULL;
}
void Menu::draw(sf::RenderWindow& window) {

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
	

	Nowa->setString("1.NOWA GRA (N)");
	Nowa->setFillColor(sf::Color(255, 0, 0));
	Nowa->setPosition(300.f, 200.f);
	Nowa->setCharacterSize(40);
	Nowa->Bold;
	
	Wyniki->setString("2.WYNIKI (S)");
	Wyniki->setFillColor(sf::Color(255, 0, 0));
	Wyniki->setPosition(300.f, 280.f);
	Wyniki->setCharacterSize(40);
	Wyniki->Bold;

	Wyjscie->setString("3.EXIT(W)");
	Wyjscie->setFillColor(sf::Color(255, 0, 0));
	Wyjscie->setPosition(300.f, 360.f);
	Wyjscie->setCharacterSize(40);
	Wyjscie->Bold;
}

void Menu::init(sf::Vector2f window_size) {

	Nowa = new sf::Text;
	Wyniki = new sf::Text;
	Wyjscie = new sf::Text;
	
	setText(Nowa, Wyniki, Wyjscie);

}