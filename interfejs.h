#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include<random>
#include<iostream>
#include <string>
#include <sstream>

class interfejs {
protected:
	
	sf::Font* font;	
	sf::Text* lewy;
	sf::Text* prawy;
	sf::Text* dolsrodek;
	sf::Text* gorasrodek;
	sf::RectangleShape* prostokat;
	sf::Vector2f wymiary;
	
	

public:
	void init(sf::Vector2f window_size);
	double pkt;
	double zycia;
	void draw(sf::RenderWindow& window);
	void setText(sf::Text* lewy, sf::Text* prawy, sf::Text* dolsrodek, sf::Text* gorasrodek, double n, double z);
	interfejs(sf::Vector2f wymiary);
	~interfejs();
	std::string punkty(double n);
	std::string zycie(double z);
	void setpkt(double p);
	void setzycie(double z);

};