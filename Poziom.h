#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include<random>
#include <math.h>
#include<iostream>
#include <string>

class Poziom {
protected:
	void init(sf::Vector2f window_size);
	sf::Font* font;
	sf::Text* Sterowanie;
	sf::Text* Pytanie;
	sf::Text* Easy;
	sf::Text* Medium;
	sf::Text* Hard;
	sf::RectangleShape* prostokat;
	sf::RectangleShape* prostokat_s;
	sf::RectangleShape* prostokat_p;
	sf::RectangleShape* prostokat_e;
	sf::RectangleShape* prostokat_m;
	sf::RectangleShape* prostokat_h;
	sf::RectangleShape* tlo;
	sf::Vector2f wymiary;

public:
	void draw(sf::RenderWindow& window);
	void setText(sf::Text* Sterowanie, sf::Text* Pytanie, sf::Text* Easy, sf::Text* Medium, sf::Text* Hard);
	Poziom(sf::Vector2f wymiary);
	~Poziom();

};
