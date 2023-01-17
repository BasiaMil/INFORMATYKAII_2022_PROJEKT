#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include<random>
#include<iostream>
#include <string>

class Pokeball {
private:
	void cos(sf::Vector2f window_size);
	sf::Text* koniec;
	sf::Text* wygrana;
	sf::Font* font;
	sf::Vector2f position;
	float xVel = 2, yVel = 2;
	sf::Texture tekstura;
	sf::Sprite pSprite;
	sf::Vector2f rozmiar_okna;
	float x = 760, y = 500;


public:

	Pokeball(float x_in, float y_in, float x_a, float y_b);
	void setV(float V);
	void napis(sf::Text* koniec);
	void napis_w(sf::Text* wygrana);
	void draw(sf::RenderWindow& window);
	void draw_w(sf::RenderWindow& window);
	void przesun(float x_in, float y_in);
	sf::Sprite getPokeball();
	sf::Vector2f getPos();
	void setPos(float x_i, float y_i);
	void sprawdzKolizjeSciany();
	void odbicie();
	float stop();
	void animuj();
	float lewa_strona() ;
	float prawa_strona() ;
	float dol() ;
	float gora() ;
	void klocek_uderzony(float a);
};
