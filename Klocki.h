#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include<random>
#include<iostream>
#include <string>
#include <math.h>

class Klocki {
private:
	sf::RectangleShape klocek;
    sf::Vector2f position;
public:
    Klocki();
    float kolizja=0;
    float x();
    float y();
    float lewo();
    float prawo();
    float góra();
    float dó³();
    float znik();
    sf::RectangleShape getklocek();
    sf::Vector2f getPos();
    void setPos(float  x_i, float y_i);
    //float uderzenie(float g, float d);

};