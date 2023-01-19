#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include<random>
#include<iostream>
#include <string>

class Menu {
protected:
	void init(sf::Vector2f window_size);
	sf::Font* font;
	sf::Text* Nowa;
	sf::Text* Wyniki;
	sf::Text* Wyjscie;
	sf::Vector2f wymiary;
	sf::RectangleShape* prostokat;
public:
	void draw(sf::RenderWindow& window);//
	void setText(sf::Text* Nowa, sf::Text* Wyniki, sf::Text* Wyjscie);//
	Menu(sf::Vector2f wymiary);//
	~Menu();//

};