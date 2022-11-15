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
	Wyjœcie
   -Zanimowane t³o typu gwiazdy pokazywane na wyk³adzie
 1)Nowa gra:
   -Zaczynamy od poziomu pierwszego
   -Wybieramy trudnoœæ:
    >szerokoœæ paletki
	>szybkoœæ pi³ki
	>czy s¹ spadaj¹ce obiekty
   -Podajemy nick
   -dostajemy ID
 2)Wczytaj gre:
   -Mo¿emy wybraæ poziom od 1 do ostatnio osi¹gniêtego
   -Wybieramy trudnoœæ:
	>szerokoœæ paletki
	>szybkoœæ pi³ki
	>czy s¹ spadaj¹ce obiekty
   -Wyœwiatlaj¹ sie nasze nick i ID
 3)WYniki:
   -wyœwietlane w fomie tablicy:
    >miejsce
	>Nick
	>ID
	>Punkty
	>Z³apane potworki
 4)Kolekcja:
   -Wyœwietlane obrazki z³apanych ju¿ stworkó
 5)Pomoc:
   -Sterowanie
   -Za co s¹ punkty
   -Jak przejœæ poziom
 6)Wyjœcie:
   -Pytanie czy na pewno chce siê wyœæ:
    >Tak-Wyjœcie bez wyœwietlenoa informacji o b³êdach
	>Nie-Powrót do interfejsu
II)Faza rozgrywki:
 1)Elementy graficzne:
	-Na górze kolejno od lewej:
	 >czas do koñca rundy
	 >punkty
	 >Zmieniaj¹cy siê komunikaty:"Z³apany!","Straci³eœ ¿ycie!", "Wszystkie z³apane!"
	 >¿ycia
	 >poziom
	-Obwódka - niewielki odstêp od œcian bocznych i do³u oraz poni¿ej napisów na górze
	-t³o: typu "migaj¹ce gwiazdy"
	-W ramce na górze pojawiaj¹ce siê w ró¿nej konfiguracji zale¿nie od poziomu przeszkody (na³o¿ony sprite trawy) i stworki równie¿ sprite
	-Na dole w ramce paletka sterowana klawiszami poruszaj¹ca siê poziomo
	-W ramce pi³ke odbijajaca siê od paletki œcian bocznych i górnej oraz przeszkód, po uderzeniu przeskody i stworka przez pi³kê, znikaj¹
	-W ramce spadaj¹ca z góry na dó³ przeszkoda
	-W lewym dolnym rogu nad wszystkim ikona pomocy
 2)Pomoc:
	-Klikniêcie w lewym dolnym rogu ikony pomoc (lub wciœniêcie klawisza F1) spowoduje zapauzowanie gry i wyœwietlenie na ekranie zasad
	-Wyjœcie z niej nast¹pi przez naciœniecie odpowiedniego przycisku, potem kontynuuje siê gre
 3)Wyjœcie:
	-Wyjœcie nast¹pi przez klikniêcie klawisza Esc
	-Przed wyjœciem nast¹pi zapytanie czy na pewno chce siê opuœciæ rozgrywkê:
	 >tak-wyjœcie do interface'u/z gry
	 >nie-wznowienie gry
 4)Rozgrywka:
	-Na planszy umieszczone s¹ przeszkody i stworki.
	-Uderzenie pi³k¹ w przeszkodê lub stworka sprawi, ¿e one znikn¹.
	-Ka¿da usuniêta przeszkoda i z³apany stworek daj¹ pkt odpowiednio +2 i +10.
	-Je¿eli zosta³o to wybrane, bêd¹ niekiedy spadaæ obiekty, które je¿eli dotkn¹³ paletki, to odejm¹ 5 pkt.
	-Poziom koñczy siê wygran¹, gdy w okreœlonym czasie zostan¹ z³apane wszystkie stworki.
	-Pozosta³y czas zostaje zamieniony na pkt dodatkowe 1s->1pkt.
	-S¹ 3 ¿ycie. Traci siê je po uderzeniu przez obiekt spadaj¹cy lub po nie odbiciu pi³eczki.
	-Przegrana nastêpuje poprzez:
	 >stracenie 3 ¿yæ,
	 >up³yw czasu.
	-Po wygraniu mo¿na przejœæ do nastêpnego poziomu.
	-Raczej nie bêdzie mo¿liwoœci zmiany trudnoœci miêdzy poziomami ale zobaczymy.
	-Iloœæ dodawanych i odejmowanych pkt bêdzie zale¿eæ od wybranej trudnoœci.
III)Zapis gry:
 1) Co zapisujemy:
	-nick
	-iloœæ pkt
	-ostatni ukoñczony poziom
	-z³apane rodzaje stworków(?)
	-ustawion¹ trudnoœæ
*/