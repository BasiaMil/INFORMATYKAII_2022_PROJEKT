#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include<random>
#include<iostream>
#include <string>

class Klocki {
private:
	sf::RectangleShape klocek;    
public:
    float x() { return klocek.getPosition().x; }
    float y() { return klocek.getPosition().y; }
    float lewo() { return x() - klocek.getSize().x / 2.f; }
    float prawo() { return x() + klocek.getSize().x / 2.f; }
    float góra() { return y() - klocek.getSize().y / 2.f; }
    float dó³() { return y() + klocek.getSize().y / 2.f; }

};