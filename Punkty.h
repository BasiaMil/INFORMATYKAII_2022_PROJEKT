#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include<random>
#include<iostream>
#include <string>

class Punkty {
private:
	sf::Text Pkt;
	sf::Text Zycia;
	sf::Font font;
public:
	Punkty();
	double lpkt;
	double lzycia;
	std::string punkty(double n);
	std::string zycie(double z);
	void czcionka();
	void zmienna();
};