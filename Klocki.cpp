#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include<random>
#include<iostream>
#include <string>
#include "Klocki.h"
#include <math.h>

    Klocki::Klocki() 
    {
        klocek.setPosition(55, 100);
        klocek.setSize(sf::Vector2f(70, 30));
        klocek.setFillColor(sf::Color(255, 0, 255));
        klocek.setOrigin(35, 15);
        klocek.setOutlineThickness(2);
        klocek.setOutlineColor(sf::Color(0, 0, 0));
    }
    
    float Klocki::x() { return klocek.getPosition().x; }
    float Klocki::y() { return klocek.getPosition().y; }
    float Klocki::lewo() { return x() - 35; }
    float Klocki::prawo() { return x() + 35; }
    float Klocki::góra() { return y() - 15; }
    float Klocki::dó³() { return y() + 15; }    
    sf::RectangleShape Klocki::getklocek() { return klocek; }
    sf::Vector2f Klocki::getPos() { return klocek.getPosition(); }
    void Klocki::setPos(float  x_i, float y_i)
    {
        position.x = x_i;
        position.y = y_i;
        klocek.setPosition(position);
    };
   /*float Klocki::uderzenie(float g, float d)
    {
        if (klocek.getGlobalBounds().intersects(g.getGlobalBounds())) 
        {
            return 1;
        } 
        else { return 0; }
    };*/
