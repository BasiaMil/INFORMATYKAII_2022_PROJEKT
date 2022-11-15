/*
Temat projektu:Pi�ka odbijaj�ca si� od ruchomego pod�o�a, tytu�:"Z�ap je wszystkie!"
Zakres indywidualny: Zadaniem gracza jest odbijanie od paletki, poruszaj�cej si� w osi poziomej u do�u ekranu, pi�ki, kt�r� musi zbija� przeszkody,
by po zniszeniu ich z�apa� potworki. Z�apanie wszystkich stwor�w na planszy pozwoli przej�� na nast�pny poziom. Punkty gracz zdobywa za zbijanie 
przeszk�d i �apanie stwork�w oraz za uko�czenie gry przed limitem czasu. Ujemne punkty otrzymuje si� za upuszczenie pi�ki.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include<random>
#include<iostream>

const int N = 10;
sf::CircleShape tab[N];
class gwiazdozbior {
private:
	std::random_device rd;
public:
	gwiazdozbior(int N);
	void draw(sf::RenderWindow &window);
	void move();

};

gwiazdozbior::gwiazdozbior(int N) {
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distX(1, 750);
	std::uniform_int_distribution<> distY(1, 550);
	std::uniform_int_distribution<> distR(10, 50);
	
	float x = 0, y = 0, R=0;	
	
	
	
	
	for (int i = 0; i < N; i++) {
		x = distX(gen);
		y = distY(gen);
		R = distR(gen);

		tab[i] = sf::CircleShape(R);
		tab[i].setPosition(sf::Vector2f(x, y));
		tab[i].setScale(sf::Vector2f(0.03f, 0.03f));


	}
}

void gwiazdozbior::draw(sf::RenderWindow & window) {
	for (int i = 0; i < N; i++) 
	{
		window.draw(tab[i]);
	}
}

void gwiazdozbior::move() {
	std::mt19937 gen(rd());  
	std::uniform_int_distribution<> distX(1, 750);
	std::uniform_int_distribution<> distY(1, 550);
	std::uniform_int_distribution<> distXl(-20, 20);
	std::uniform_int_distribution<> distYl(-20, 20);
	for (int i = 0; i < N; i++) 
	{
		tab[i].move(sf::Vector2f(distXl(gen), distYl(gen)));
		sf::Vector2f position = tab[i].getPosition();
		if (position.x > 750 || position.x < 0 || position.y > 530 || position.y < 0)
			tab[i].setPosition(distX(gen), distY(gen));
	}
}


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Gwiazdozbior");
	sf::Clock zegar;
	gwiazdozbior td(10);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (zegar.getElapsedTime().asMilliseconds() > 100.0f) {
			td.move();//nowa pozycja Toad'ow		
			zegar.restart();
		}

		window.clear(sf::Color::Blue);
		td.draw(window);//metoda draw() obiektu klasy toads
		window.display();
	}



	return 0;
}

/*
I)Interface:
   -Opcje:	
	Nowa gra
	Wczytaj gre
	Wyniki
	Kolekcja(?)
	Pomoc
	Wyj�cie
   -Zanimowane t�o typu gwiazdy pokazywane na wyk�adzie
 1)Nowa gra:
   -Zaczynamy od poziomu pierwszego
   -Wybieramy trudno��:
    >szeroko�� paletki
	>szybko�� pi�ki
	>czy s� spadaj�ce obiekty
   -Podajemy nick
   -dostajemy ID
 2)Wczytaj gre:
   -Mo�emy wybra� poziom od 1 do ostatnio osi�gni�tego
   -Wybieramy trudno��:
	>szeroko�� paletki
	>szybko�� pi�ki
	>czy s� spadaj�ce obiekty
   -Wy�wiatlaj� sie nasze nick i ID
 3)WYniki:
   -wy�wietlane w fomie tablicy:
    >miejsce
	>Nick
	>ID
	>Punkty
	>Z�apane potworki
 4)Kolekcja:
   -Wy�wietlane obrazki z�apanych ju� stwork�
 5)Pomoc:
   -Sterowanie
   -Za co s� punkty
   -Jak przej�� poziom
 6)Wyj�cie:
   -Pytanie czy na pewno chce si� wy��:
    >Tak-Wyj�cie bez wy�wietlenoa informacji o b��dach
	>Nie-Powr�t do interfejsu
II)Faza rozgrywki:
 1)Elementy graficzne:
	-Na g�rze kolejno od lewej:
	 >czas do ko�ca rundy
	 >punkty
	 >Zmieniaj�cy si� komunikaty:"Z�apany!","Straci�e� �ycie!", "Wszystkie z�apane!"
	 >�ycia
	 >poziom
	-Obw�dka - niewielki odst�p od �cian bocznych i do�u oraz poni�ej napis�w na g�rze
	-t�o: typu "migaj�ce gwiazdy"
	-W ramce na g�rze pojawiaj�ce si� w r�nej konfiguracji zale�nie od poziomu przeszkody (na�o�ony sprite trawy) i stworki r�wnie� sprite
	-Na dole w ramce paletka sterowana klawiszami poruszaj�ca si� poziomo
	-W ramce pi�ke odbijajaca si� od paletki �cian bocznych i g�rnej oraz przeszk�d, po uderzeniu przeskody i stworka przez pi�k�, znikaj�
	-W ramce spadaj�ca z g�ry na d� przeszkoda
	-W lewym dolnym rogu nad wszystkim ikona pomocy
 2)Pomoc:
	-Klikni�cie w lewym dolnym rogu ikony pomoc (lub wci�ni�cie klawisza F1) spowoduje zapauzowanie gry i wy�wietlenie na ekranie zasad
	-Wyj�cie z niej nast�pi przez naci�niecie odpowiedniego przycisku, potem kontynuuje si� gre
 3)Wyj�cie:
	-Wyj�cie nast�pi przez klikni�cie klawisza Esc
	-Przed wyj�ciem nast�pi zapytanie czy na pewno chce si� opu�ci� rozgrywk�:
	 >tak-wyj�cie do interface'u/z gry
	 >nie-wznowienie gry
 4)Rozgrywka:
	-Na planszy umieszczone s� przeszkody i stworki.
	-Uderzenie pi�k� w przeszkod� lub stworka sprawi, �e one znikn�.
	-Ka�da usuni�ta przeszkoda i z�apany stworek daj� pkt odpowiednio +2 i +10.
	-Je�eli zosta�o to wybrane, b�d� niekiedy spada� obiekty, kt�re je�eli dotkn�� paletki, to odejm� 5 pkt.
	-Poziom ko�czy si� wygran�, gdy w okre�lonym czasie zostan� z�apane wszystkie stworki.
	-Pozosta�y czas zostaje zamieniony na pkt dodatkowe 1s->1pkt.
	-S� 3 �ycie. Traci si� je po uderzeniu przez obiekt spadaj�cy lub po nie odbiciu pi�eczki.
	-Przegrana nast�puje poprzez:
	 >stracenie 3 �y�,
	 >up�yw czasu.
	-Po wygraniu mo�na przej�� do nast�pnego poziomu.
	-Raczej nie b�dzie mo�liwo�ci zmiany trudno�ci mi�dzy poziomami ale zobaczymy.
	-Ilo�� dodawanych i odejmowanych pkt b�dzie zale�e� od wybranej trudno�ci.
III)Zapis gry:
 1) Co zapisujemy:
	-nick
	-ilo�� pkt
	-ostatni uko�czony poziom
	-z�apane rodzaje stwork�w(?)
	-ustawion� trudno��
*/