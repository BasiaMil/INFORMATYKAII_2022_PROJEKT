#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include<random>
#include <math.h>
#include<iostream>
#include <string>
#include"Pauza.h"


Pomoc::Pomoc(sf::Vector2f wymiary) {
	this->wymiary.x = wymiary.x;
	this->wymiary.y = wymiary.y;
	sf::Vector2f window_size(800.f, 600);
	init(window_size);
}
Pomoc::~Pomoc() {
	delete prostokat;
	prostokat = NULL;
	delete prostokat_r;
	prostokat_r = NULL;
	delete prostokat_i;
	prostokat_i = NULL;
	delete prostokat_k;
	prostokat_k = NULL;
	delete prostokat_w;
	prostokat_w = NULL;
	delete Instrukcja;
	Instrukcja = NULL;
	delete Kontynuuj;
	Kontynuuj = NULL;
	delete Wyjscie;
	Wyjscie = NULL;
	delete tlo;
	tlo = NULL;

}
void Pomoc::draw(sf::RenderWindow& window) {
	window.draw(*tlo);
	window.draw(*prostokat);
	window.draw(*prostokat_i);
	window.draw(*prostokat_k);
	window.draw(*prostokat_w);
	window.draw(*prostokat_r);
	window.draw(*restart);
	window.draw(*Instrukcja);
	window.draw(*Kontynuuj);
	window.draw(*Wyjscie);
}

void Pomoc::setText(sf::Text* Instrukcja, sf::Text* Kontynuuj, sf::Text* Wyjscie, sf::Text* restart) {

	font = new sf::Font;
	font->loadFromFile("arial.ttf");
	Instrukcja->setFont(*font);
	Kontynuuj->setFont(*font);
	Wyjscie->setFont(*font);
	restart->setFont(*font);

	Instrukcja->setString("Twoim zadaniem jest zbicie wszystkich klockow.\n Odbijaj pilke w ich kierunku za pomoca paletki.\n    Paletka steruj za pomoca klawiszy A i D.");
	Instrukcja->setFillColor(sf::Color(255, 255, 255));
	Instrukcja->setPosition(80.f, 120.f);
	Instrukcja->setCharacterSize(31);

	Kontynuuj->setString("Kontynuuj (K)");
	Kontynuuj->setFillColor(sf::Color(255, 255, 255));
	Kontynuuj->setPosition(505.f, 335.f);

	Wyjscie->setString("Wyjdz (Q)");
	Wyjscie->setFillColor(sf::Color(255, 255, 255));
	Wyjscie->setPosition(60.f, 335.f);

	restart->setString("Restart (R)");
	restart->setFillColor(sf::Color(255, 255, 255));
	restart->setPosition(240.f, 335.f);
}

void Pomoc::init(sf::Vector2f window_size) {

	Instrukcja = new sf::Text;
	Kontynuuj = new sf::Text;
	Wyjscie = new sf::Text;
	restart = new sf::Text;
	prostokat_r = new sf::RectangleShape;
	prostokat = new sf::RectangleShape;
	prostokat_i = new sf::RectangleShape;
	prostokat_k = new sf::RectangleShape;
	prostokat_w = new sf::RectangleShape;
	tlo = new sf::RectangleShape;

	prostokat->setPosition(20.f, 50.f);
	prostokat->setSize(wymiary);
	prostokat->setFillColor(sf::Color(0, 0, 153));

	prostokat_i->setPosition(26.f, 90.f);
	prostokat_i->setSize({ 748,170 });
	prostokat_i->setFillColor({ 51, 0, 102 });
	prostokat_i->setOutlineColor({ 0,0,0 });
	prostokat_i->setOutlineThickness(5);

	prostokat_r->setPosition(230.f, 325.f);
	prostokat_r->setSize({ 220,65 });
	prostokat_r->setFillColor({ 51, 0, 102 });
	prostokat_r->setOutlineColor({ 0,0,0 });
	prostokat_r->setOutlineThickness(5);

	prostokat_k->setPosition(485.f, 325.f);
	prostokat_k->setSize({ 220,65 });
	prostokat_k->setFillColor({ 51, 0, 102 });
	prostokat_k->setOutlineColor({ 0,0,0 });
	prostokat_k->setOutlineThickness(5);

	prostokat_w->setPosition(50.f, 325.f);
	prostokat_w->setSize({ 155,65 });
	prostokat_w->setFillColor({ 51, 0, 102 });
	prostokat_w->setOutlineColor({ 0,0,0 });
	prostokat_w->setOutlineThickness(5);

	tlo->setPosition(0.f, 0.f);
	tlo->setSize(sf::Vector2f(800.f, 600.f));
	tlo->setFillColor(sf::Color(0, 0, 0));

	setText(Instrukcja, Kontynuuj, Wyjscie, restart);

}