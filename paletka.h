#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include<random>
#include<iostream>
#include <string>

class paletka {
private:
	sf::RectangleShape palletka;
	sf::Vector2f position;
	//sf::Vector2f predkosc;
	//float predkosc.x = 10, predkosc.y = 0;
	

public:
	float Velmax;
	float Veloczekiwany=0;
	float Velteraz=0;
	float przyspieszenie=0.5;
	paletka(float x_in, float y_in, float Velmax);
	sf::RectangleShape getPaletka();
	sf::Vector2f getPos();
	void setPos(float x_i, float y_i);
	float lewa_strona() ;
	float prawa_strona();
	float dol();
	float gora();
	void przesun();
	float predkosc(float Veloczekiwany, float Velteraz, float przyspieszenie);
	void ruch();
	void update();
	
};