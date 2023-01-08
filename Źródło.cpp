/*
Temat projektu:Pi³ka odbijaj¹ca siê od ruchomego pod³o¿a, tytu³:"Z³ap je wszystkie!"
Zakres indywidualny: Zadaniem gracza jest odbijanie od paletki, poruszaj¹cej siê w osi poziomej u do³u ekranu, pi³ki, któr¹ musi zbijaæ przeszkody,
by po zniszeniu ich z³apaæ potworki. Z³apanie wszystkich stworów na planszy pozwoli przejœæ na nastêpny poziom. Punkty gracz zdobywa za zbijanie 
przeszkód i ³apanie stworków oraz za ukoñczenie gry przed limitem czasu. Ujemne punkty otrzymuje siê za upuszczenie pi³ki.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include<random>
#include<iostream>
#include <string>
#include"interfejs.h"
#include"gwiazdozbior.h"
#include"paletka.h"
#include"Pokeball.h"

int main(){
	using namespace std;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Gwiazdozbior");
	sf::Clock zegar;
	
	interfejs p1(sf::Vector2f(760.f, 500.f));
	gwiazdozbior td(1000);
	Pokeball pb(400, 10, 760, 500);
	paletka pal(320,504);
	
	int a = 320;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed )
				window.close();
			
			if (event.type == sf::Event::KeyPressed)
		{
			
			if (event.key.code == sf::Keyboard::A && a>30)
			{
				pal.przesun(-10, 0);
				a = a - 10;
			}
			if (event.key.code == sf::Keyboard::D && a<690)
			{
				pal.przesun(10, 0);
				a = a + 10;
			}
			
		
		}

		}

		if (zegar.getElapsedTime().asMilliseconds() > 5.0f) {
			td.move();//nowa pozycja Toad'ow		
			pb.animuj();
			zegar.restart();

			cout << pb.getPos().y << "\n";
			
			
			if (pb.getPos().x+50 >= pal.getPos().x-10 && pb.getPos().x+50 <= pal.getPos().x + 90 && pb.getPos().y+100 >= pal.getPos().y  && pb.getPos().y + 100 <= pal.getPos().y+10 )
		{
			pb.odbicie();
		}
		
			
			
		}
		
		
		
		window.clear(sf::Color::Black);
		td.draw(window);//metoda draw() obiektu klasy toads
		p1.draw(window);
		window.draw(pal.getPaletka());
		window.draw(pb.getPokeball());
		
		if (pb.getPos().y == 450) 
		{
			pb.draw(window);
		}
		window.display();

		
		
		//t³o///////////////////////////////////////////////////////////////////
	}


	return 0;
}


