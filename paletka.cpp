#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include<random>
#include<iostream>
#include <string>
#include "paletka.h"

paletka::paletka(float x_in, float y_in)
	{
		position.x = x_in;
		position.y = y_in;
		palletka.setFillColor(sf::Color(10, 50, 150));
		palletka.setSize(sf::Vector2f(80, 30));
		palletka.setOutlineThickness(10);
		palletka.setOutlineColor(sf::Color(0, 0, 0));
		palletka.setPosition(position);
	};
void paletka::przesun(float x_in, float y_in)
	{
		sf::Vector2f pos;
		pos.x = x_in;
		pos.y = y_in;
		palletka.move(pos);
	};
sf::RectangleShape paletka::getPaletka() { return palletka;}

sf::Vector2f paletka::getPos() { return palletka.getPosition();}