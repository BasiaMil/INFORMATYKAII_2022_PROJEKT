#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include<random>
#include<iostream>
#include <string>
#include"Pokeball.h"

void Pokeball::cos(sf::Vector2f window_size)
{
		koniec = new sf::Text;
		napis(koniec);
};
Pokeball::Pokeball(float x_in, float y_in, float x_a, float y_b)
	{
		position.x = x_in;
		position.y = y_in;
		rozmiar_okna.x = x_a;
		rozmiar_okna.y = y_b;
		tekstura.loadFromFile("pokeball.png");
		pSprite.setTexture(tekstura);
		pSprite.setPosition(position);
		sf::Vector2f window_size(800.f, 600);
		cos(window_size);
	}
void Pokeball:: napis(sf::Text* koniec)
	{
		font = new sf::Font;
		font->loadFromFile("arial.ttf");
		koniec->setFont(*font);
		koniec->setString("Koniec gry!!!");
		koniec->setCharacterSize(75);
		koniec->setRotation(-45);
		koniec->setFillColor(sf::Color(200, 20, 20));
		koniec->setPosition(200.f, 350.f);
	}
void Pokeball::draw(sf::RenderWindow& window)
	{
		window.draw(*koniec);
	}
void Pokeball::przesun(float x_in, float y_in) 
{
		sf::Vector2f pos;
		pos.x = x_in;
		pos.y = y_in;
		pSprite.move(pos);
		position = pSprite.getPosition();
}
sf::Sprite Pokeball::getPokeball() {
		return pSprite;
	}
sf::Vector2f Pokeball:: getPos() {
		return pSprite.getPosition();
	}
void Pokeball:: sprawdzKolizjeSciany() {
		if (position.x <= 20)
			xVel = 3;
		if (position.x >= 680)
			xVel = -2;
		if (position.y <= 50)
			yVel = 2;
		if (position.y >= 450)
		{
			xVel = 0;
			yVel = 0;
		}
	}
void Pokeball::odbicie() {
		yVel = -yVel;
	}

float Pokeball::stop() {

		return xVel;
	}

void Pokeball::animuj()
	{
		sprawdzKolizjeSciany();
		przesun(xVel, yVel);
	}
