#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include<random>
#include <math.h>
#include<iostream>
#include <string>

class Pomoc {
protected:
	void init(sf::Vector2f window_size);
	sf::Font* font;
	sf::Text* Instrukcja;
	sf::Text* Kontynuuj;
	sf::Text* Wyjscie;
	sf::Text* restart;
	sf::RectangleShape* prostokat_r;
	sf::RectangleShape* prostokat;
	sf::RectangleShape* prostokat_i;
	sf::RectangleShape* prostokat_k;
	sf::RectangleShape* prostokat_w;
	sf::RectangleShape* tlo;
	sf::Vector2f wymiary;

public:
	void draw(sf::RenderWindow& window);
	void setText(sf::Text* Pomoc, sf::Text* Kontynuuj, sf::Text* Wyjscie, sf::Text* restart);
	Pomoc(sf::Vector2f wymiary);
	~Pomoc();

};
