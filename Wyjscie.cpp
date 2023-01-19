#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include<random>
#include<iostream>
#include <string>
#include"Wyjscie.h"


Wyjscie::Wyjscie(sf::Vector2f wymiary) {
	this->wymiary.x = wymiary.x;
	this->wymiary.y = wymiary.y;
	sf::Vector2f window_size(800.f, 600);
	init(window_size);
}
Wyjscie::~Wyjscie() {
	delete prostokat;
	prostokat = NULL;
	delete prostokat_p;
	prostokat_p = NULL;
	delete prostokat_t;
	prostokat_t = NULL;
	delete prostokat_n;
	prostokat_n = NULL;
	delete Pytanie;
	Pytanie = NULL;
	delete Tak;
	Tak = NULL;
	delete Nie;
	Nie = NULL;
	delete tlo;
	tlo = NULL;

}
void Wyjscie::draw(sf::RenderWindow& window) {
	window.draw(*tlo);
	window.draw(*prostokat);
	window.draw(*prostokat_p);
	window.draw(*prostokat_n);
	window.draw(*prostokat_t);
	window.draw(*Pytanie);
	window.draw(*Tak);
	window.draw(*Nie);


}

void Wyjscie::setText(sf::Text* Pytanie, sf::Text* Tak, sf::Text* Nie) {

	font = new sf::Font;
	font->loadFromFile("arial.ttf");
	Pytanie->setFont(*font);
	Tak->setFont(*font);
	Nie->setFont(*font);

	Pytanie->setString("CZY NA PEWNO CHCESZ OPUSCIC GRE?");
	Pytanie->setFillColor(sf::Color(255, 255, 255));
	Pytanie->setPosition(100.f, 200.f);

	Tak->setString("TAK (T)");
	Tak->setFillColor(sf::Color(255, 255, 255));
	Tak->setPosition(200.f, 280.f);

	Nie->setString("NIE (I)");
	Nie->setFillColor(sf::Color(255, 255, 255));
	Nie->setPosition(440.f, 280.f);
}

void Wyjscie::init(sf::Vector2f window_size) {

	Pytanie = new sf::Text;
	Tak = new sf::Text;
	Nie = new sf::Text;
	prostokat = new sf::RectangleShape;
	prostokat_p = new sf::RectangleShape;
	prostokat_t = new sf::RectangleShape;
	prostokat_n = new sf::RectangleShape;
	tlo = new sf::RectangleShape;

	prostokat->setPosition(20.f, 50.f);
	prostokat->setSize(wymiary);
	prostokat->setFillColor(sf::Color(0, 0, 153));
	
	prostokat_p->setPosition(95.f, 180.f);
	prostokat_p->setSize({ 600,65 });
	prostokat_p->setFillColor({ 51, 0, 102 });
	prostokat_p->setOutlineColor({ 0,0,0 });
	prostokat_p->setOutlineThickness(5);

	prostokat_t->setPosition(195.f, 270.f);
	prostokat_t->setSize({120,65});
	prostokat_t->setFillColor({ 51, 0, 102 });
	prostokat_t->setOutlineColor({ 0,0,0 });
	prostokat_t->setOutlineThickness(5);

	prostokat_n->setPosition(435.f, 270.f);
	prostokat_n->setSize({ 120,65 });
	prostokat_n->setFillColor({ 51, 0, 102 });
	prostokat_n->setOutlineColor({ 0,0,0 });
	prostokat_n->setOutlineThickness(5);

	tlo->setPosition(0.f, 0.f);
	tlo->setSize(sf::Vector2f(800.f, 600.f));
	tlo->setFillColor(sf::Color(0, 0, 0));

	setText(Pytanie, Tak, Nie);

}