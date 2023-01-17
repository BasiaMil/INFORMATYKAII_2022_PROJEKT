#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include<random>
#include <math.h>
#include<iostream>
#include <string>
#include"Pokeball.h"

void Pokeball::cos(sf::Vector2f window_size)
{
		koniec = new sf::Text;
		napis(koniec);
		wygrana = new sf::Text;
		napis_w(wygrana);
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
		pSprite.setOrigin(50, 50);
		pSprite.setScale(0.5,0.5);
		sf::Vector2f window_size(800.f, 600);
		cos(window_size);
		
	}
void Pokeball::setV(float V)
{
	yVel = V;
	xVel = V;
}
void Pokeball::setPos(float  x_i, float y_i)
{
	position.x = x_i;
	position.y = y_i;
	pSprite.setPosition(position);
};
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
void Pokeball::napis_w(sf::Text* wygrana)
	{
		font = new sf::Font;
		font->loadFromFile("arial.ttf");
		wygrana->setFont(*font);
		wygrana->setString("Wygrales!!!");
		wygrana->setCharacterSize(100);
		wygrana->setRotation(-30);
		wygrana->setFillColor(sf::Color(100, 20,255));
		wygrana->setPosition(150.f, 330.f);
	};
void Pokeball::draw(sf::RenderWindow& window)
	{
		window.draw(*koniec);
	}
void Pokeball::draw_w(sf::RenderWindow& window)
{
	yVel = 0;
	xVel = 0;
	window.draw(*wygrana);
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
float Pokeball::lewa_strona() { return getPos().x - 25; };
float Pokeball::prawa_strona() { return getPos().x + 25; };
float Pokeball::dol() { return getPos().y + 25; };
float Pokeball::gora() { return getPos().y - 25; };

void Pokeball:: sprawdzKolizjeSciany() {
		if (lewa_strona() <= 20)
			xVel = -xVel;
		if (prawa_strona()  >= 780)
			xVel = -xVel;
		if (gora() <= 50)
			yVel = -yVel;
		if (dol() >= 550)
		{
			xVel = 0;
			yVel = 0;
		}
	}
void Pokeball::odbicie() {
		yVel = -yVel;
	}

float Pokeball::stop() 
{
	return xVel;
}

void Pokeball::animuj()
	{
		sprawdzKolizjeSciany();
		przesun(xVel, yVel);
	}
void Pokeball::klocek_uderzony(float a) 
{
	
	if (a != -100)
	{
		yVel = -yVel;
	}
}
