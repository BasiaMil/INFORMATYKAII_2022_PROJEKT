#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include<random>
#include<iostream>
#include <string>
#include "paletka.h"

paletka::paletka(float x_in, float y_in, float Vm)
	{
		position.x = x_in;
		position.y = y_in;
		Velmax = Vm;
		palletka.setFillColor(sf::Color(10, 50, 150));
		palletka.setSize(sf::Vector2f(80, 30));
		palletka.setOutlineThickness(10);
		palletka.setOutlineColor(sf::Color(0, 0, 0));
		palletka.setPosition(position);
		
	};
float paletka::predkosc(float Veloczekiwan, float Veltera, float przyspieszeni)
{ 

	float roznica = Veloczekiwan - Veltera+0.5;
	
	if (roznica > przyspieszeni)
	{
		return Veltera + przyspieszeni;
	}
	if (roznica < przyspieszeni)
	{
		return Veltera - przyspieszeni;
	}
	else 
	{
		return Veloczekiwan;
	}
};
void paletka::setPos(float  x_i, float y_i)
{
	position.x = x_i;
	position.y = y_i;
	palletka.setPosition(position);
};
sf::RectangleShape paletka::getPaletka() { return palletka;}
sf::Vector2f paletka::getPos() { return palletka.getPosition();}
float paletka::lewa_strona() { return getPos().x - 10; };
float paletka::prawa_strona() { return getPos().x + 90; };
float paletka::dol() { return getPos().y + 40; };
float paletka::gora() { return getPos().y - 10; };
/*void paletka::przesun()
{
	palletka.move(10,0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && prawa_strona()<780)
	{

	}
};*/
void paletka::ruch()
{
	palletka.move(Velteraz, 0);
}
void paletka::update() { Velteraz = predkosc(Veloczekiwany, Velteraz, przyspieszenie); };