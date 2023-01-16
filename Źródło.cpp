/*
Temat projektu:Pi³ka odbijaj¹ca siê od ruchomego pod³o¿a, tytu³:"a'la Arcanoid!"
Zakres indywidualny: Zadaniem gracza jest odbijanie od paletki, poruszaj¹cej siê w osi poziomej u do³u ekranu, pi³ki, któr¹ musi zbijaæ przeszkody,
by po zniszeniu ich z³apaæ potworki. Z³apanie wszystkich stworów na planszy pozwoli przejœæ na nastêpny poziom. Punkty gracz zdobywa za zbijanie 
przeszkód i ³apanie stworków oraz za ukoñczenie gry przed limitem czasu. Ujemne punkty otrzymuje siê za upuszczenie pi³ki.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include<random>
#include <math.h>
#include<iostream>
#include <string>
#include"interfejs.h"
#include"gwiazdozbior.h"
#include"paletka.h"
#include"Pokeball.h"
#include"Menu.h"
#include "Klocki.h"

int main(){
	using namespace std;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Gwiazdozbior");
	sf::Clock zegar;	
	interfejs p1(sf::Vector2f(760.f, 500.f));
	gwiazdozbior tlo(1000);
	Pokeball pb(200, 250, 760, 500);
	paletka pal(320,504,5);
	Menu menu(sf::Vector2f(760.f, 500.f));
	Klocki tab[30];
	int flaga = 0;
	pal.Veloczekiwany = 0;
	int punkty = 0;
	
	while (window.isOpen())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) break;
		sf::Event event;
		while (window.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed )
				window.close();			
			
			if (event.type == sf::Event::KeyPressed)
			{	
						
				if (event.key.code == sf::Keyboard::A)
				{
					pal.Veloczekiwany = -pal.Velmax;
					
					
				}
				if (event.key.code == sf::Keyboard::D)
				{
					pal.Veloczekiwany = pal.Velmax;
					
				}		
			}

			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::A)
				{
					pal.Veloczekiwany = 0;
					
				}
				if (event.key.code == sf::Keyboard::D)
				{
					pal.Veloczekiwany = 0;
					
				}
			}			
			
		}

		if (flaga==1)
		{
			//cout << "Velmax:" << pal.Velmax << "..." <<"Veloczekiwany:"<< pal.Veloczekiwany  << "..." << "Velteraz:" << pal.Velteraz << "..."<<"przyspieszenie:" << pal.przyspieszenie << endl;
			if (zegar.getElapsedTime().asMilliseconds() > 5.0f) 
			{
			pal.update();	
			pal.ruch();
			tlo.move();	
			pb.animuj();
			zegar.restart();
			if (pal.lewa_strona()<20) {
				pal.setPos(25,504);
			}
			if (pal.prawa_strona() > 780) {
				pal.setPos(689, 504);
			}
				
			if (pb.getPos().x >= pal.lewa_strona() && pb.getPos().x <= pal.prawa_strona() && pb.dol() >= pal.gora() && pb.dol() <= pal.gora() + 2)
		{
			pb.odbicie();
		}
			
		}
					
		
			window.clear(sf::Color::Black);
		tlo.draw(window);
		p1.draw(window);		
		window.draw(pal.getPaletka());
		window.draw(pb.getPokeball());
		
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 5; j++) {
				if (tab[5 * i + j].getklocek().getGlobalBounds().intersects(pb.getPokeball().getGlobalBounds()))
				{					
					tab[5 * i + j].kolizja = 1;
					tab[5 * i + j].setPos(-100,-100);
					pb.klocek_uderzony( tab[i].x());
					punkty = punkty + 1;
					cout << "Punkty: " << punkty << "\n";
				}
				//cout <<"nr: " << 5 * i + j <<" wynosi "<< tab[5 * i + j].kolizja << "\n";
				
				//punkty += 1;
				//cout << "Punkty: " << punkty << "\n";
				
				
				if(tab[5 * i + j].kolizja==0)
				{
				tab[5 * i + j].setPos(60+150*j,70+i*50);
				window.draw(tab[5 * i + j].getklocek());
				}
				
			}

		}
		
		
		if (pb.getPos().y >= 520) 
		{
			pb.draw(window);
		}
		}
		if (flaga==0)	menu.draw(window);
		if (flaga == 2)	menu.draw(window);
		if (flaga == 3)	menu.draw(window);
		if (flaga == 4)	menu.draw(window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) flaga = 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) flaga = 0;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::T)) flaga = 2;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Y)) flaga = 3;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) flaga = 4;
		window.display();
	}


	return 0;
}


