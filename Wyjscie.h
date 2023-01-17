#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include<random>
#include<iostream>
#include <string>

class Wyjscie{
protected:
	void init(sf::Vector2f window_size);
	sf::Font* font;
	sf::Text* Pytanie;
	sf::Text* Tak;
	sf::Text* Nie;
	sf::RectangleShape* prostokat;
	sf::RectangleShape* prostokat_p;
	sf::RectangleShape* prostokat_t;
	sf::RectangleShape* prostokat_n;
	sf::RectangleShape* tlo;
	sf::Vector2f wymiary;

public:
	void draw(sf::RenderWindow& window);//
	void setText(sf::Text* Pytanie, sf::Text* Tak, sf::Text* Nie);//
	Wyjscie(sf::Vector2f wymiary);//
	~Wyjscie();//

};