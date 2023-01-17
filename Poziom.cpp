#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include<random>
#include <math.h>
#include<iostream>
#include <string>
#include"Poziom.h"


Poziom::Poziom(sf::Vector2f wymiary) {
	this->wymiary.x = wymiary.x;
	this->wymiary.y = wymiary.y;
	sf::Vector2f window_size(800.f, 600);
	init(window_size);
}
Poziom::~Poziom() {
	delete prostokat;
	prostokat = NULL;
	delete prostokat_p;
	prostokat_p = NULL;
	delete prostokat_s;
	prostokat_s = NULL;
	delete prostokat_e;
	prostokat_e = NULL;
	delete prostokat_m;
	prostokat_m = NULL;
	delete prostokat_h;
	prostokat_h = NULL;
	delete Pytanie;
	Pytanie = NULL;
	delete Sterowanie;
	Sterowanie = NULL;
	delete Easy;
	Easy = NULL;
	delete Medium;
	Medium = NULL;
	delete Hard;
	Hard = NULL;
	delete tlo;
	tlo = NULL;

}
void Poziom::draw(sf::RenderWindow& window) {
	window.draw(*tlo);
	window.draw(*prostokat);
	window.draw(*prostokat_s);
	window.draw(*prostokat_p);	
	window.draw(*prostokat_e);
	window.draw(*prostokat_m);
	window.draw(*prostokat_h);
	window.draw(*Sterowanie);
	window.draw(*Pytanie);	
	window.draw(*Easy);
	window.draw(*Medium);
	window.draw(*Hard);
}

void Poziom::setText(sf::Text* Sterowanie, sf::Text* Pytanie, sf::Text* Easy, sf::Text* Medium, sf::Text* Hard) {

	font = new sf::Font;
	font->loadFromFile("arial.ttf");
	Sterowanie->setFont(*font);
	Pytanie->setFont(*font);
	Easy->setFont(*font);
	Medium->setFont(*font);
	Hard->setFont(*font);

	Sterowanie->setString("Odbij pilke paletka by zbic klocki. Poruszaj klawiszami A i D.");
	Sterowanie->setFillColor(sf::Color(0, 0, 0));
	Sterowanie->setPosition(38.f, 103.f);
	Sterowanie->setCharacterSize(27);
	
	Pytanie->setString("Jaki poziom trudnosci gry wybierasz?");
	Pytanie->setFillColor(sf::Color(0, 0, 0));
	Pytanie->setPosition(130.f, 190.f);

	Easy->setString("EASY (E)");
	Easy->setFillColor(sf::Color(0, 0, 0));
	Easy->setPosition(120.f, 300.f);

	Medium->setString("MEDIUM (M)");
	Medium->setFillColor(sf::Color(0, 0, 0));
	Medium->setPosition(315.f, 300.f);

	Hard->setString("HARD (H)");
	Hard->setFillColor(sf::Color(0, 0, 0));
	Hard->setPosition(550.f, 300.f);
}

void Poziom::init(sf::Vector2f window_size) {

	Sterowanie= new sf::Text;
	Pytanie = new sf::Text;
	Easy = new sf::Text;
	Medium = new sf::Text;
	Hard = new sf::Text;
	prostokat = new sf::RectangleShape;
	prostokat_s = new sf::RectangleShape;
	prostokat_p = new sf::RectangleShape;
	prostokat_e = new sf::RectangleShape;
	prostokat_m = new sf::RectangleShape;
	prostokat_h = new sf::RectangleShape;
	tlo = new sf::RectangleShape;

	prostokat->setPosition(20.f, 50.f);
	prostokat->setSize(wymiary);
	prostokat->setFillColor(sf::Color(10, 200, 10));

	prostokat_s->setPosition(26.f, 90.f);
	prostokat_s->setSize({ 748,65 });
	prostokat_s->setFillColor(sf::Color(250, 200, 10));
	prostokat_s->setOutlineColor({ 0,0,0 });
	prostokat_s->setOutlineThickness(5);

	prostokat_p->setPosition(125.f, 180.f);
	prostokat_p->setSize({ 513,65 });
	prostokat_p->setFillColor(sf::Color(250, 200, 10));
	prostokat_p->setOutlineColor({ 0,0,0 });
	prostokat_p->setOutlineThickness(5);

	prostokat_e->setPosition(110.f, 285.f);
	prostokat_e->setSize({ 145,65 });
	prostokat_e->setFillColor(sf::Color(250, 200, 10));
	prostokat_e->setOutlineColor({ 0,0,0 });
	prostokat_e->setOutlineThickness(5);

	prostokat_m->setPosition(310.f, 285.f);
	prostokat_m->setSize({ 185,65 });
	prostokat_m->setFillColor(sf::Color(250, 200, 10));
	prostokat_m->setOutlineColor({ 0,0,0 });
	prostokat_m->setOutlineThickness(5);

	prostokat_h->setPosition(545.f, 285.f);
	prostokat_h->setSize({ 145,65 });
	prostokat_h->setFillColor(sf::Color(250, 200, 10));
	prostokat_h->setOutlineColor({ 0,0,0 });
	prostokat_h->setOutlineThickness(5);

	tlo->setPosition(0.f, 0.f);
	tlo->setSize(sf::Vector2f(800.f, 600.f));
	tlo->setFillColor(sf::Color(0, 0, 0));

	setText(Sterowanie, Pytanie, Easy, Medium, Hard);

}