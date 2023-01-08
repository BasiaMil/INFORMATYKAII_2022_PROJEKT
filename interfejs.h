#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include<random>
#include<iostream>
#include <string>

class interfejs {
protected:
	void init(sf::Vector2f window_size);
	sf::Font* font;	
	sf::Text* lewy;
	sf::Text* prawy;
	sf::Text* dolsrodek;
	sf::Text* gorasrodek;
	sf::RectangleShape* prostokat;
	sf::Vector2f wymiary;

public:
	void draw(sf::RenderWindow& window);//
	void setText(sf::Text* lewy, sf::Text* prawy, sf::Text* dolsrodek, sf::Text* gorasrodek);//
	interfejs(sf::Vector2f wymiary);//
	~interfejs();//

};