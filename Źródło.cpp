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
#include <string>




//t�o////////////////////////////////////////////////////////////

class gwiazdozbior {
private:
	std::random_device rd;
	int N;
	sf::CircleShape* gwiazdy;
public:
	gwiazdozbior(int Nt);
	void draw(sf::RenderWindow &window);
	void move();

};

gwiazdozbior::gwiazdozbior(int Nt) {
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distX(1, 750);
	std::uniform_int_distribution<> distY(1, 550);
	std::uniform_int_distribution<> distR(10, 50);
	
	float x = 0, y = 0, R=0;	
	N = Nt;
	gwiazdy = new sf::CircleShape[N];
		
	for (int i = 0; i < N; i++) {
		x = distX(gen);
		y = distY(gen);
		R = distR(gen);

		gwiazdy[i] = sf::CircleShape(R);
		gwiazdy[i].setPosition(sf::Vector2f(x, y));
		gwiazdy[i].setScale(sf::Vector2f(0.03f, 0.03f));


	}
}

void gwiazdozbior::draw(sf::RenderWindow & window) {
	for (int i = 0; i < N; i++) 
	{
		window.draw(gwiazdy[i]);
	}
}

void gwiazdozbior::move() {
	std::mt19937 gen(rd());  
	std::uniform_int_distribution<> distX(1, 800);
	std::uniform_int_distribution<> distY(1, 600);
	std::uniform_int_distribution<> distXl(-20, 20);
	std::uniform_int_distribution<> distYl(-20, 20);
	for (int i = 0; i < N; i++) 
	{
		gwiazdy[i].move(sf::Vector2f(distXl(gen), distYl(gen)));
		sf::Vector2f position = gwiazdy[i].getPosition();
		if (position.x > 800 || position.x < 0 || position.y > 600 || position.y < 0)
			gwiazdy[i].setPosition(distX(gen), distY(gen));
	}
}
//t�o/////////////////////////////////////////////////////////////////////////////////////////
//interface//////
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

interfejs::interfejs(sf::Vector2f wymiary) {
	this->wymiary.x = wymiary.x;
	this->wymiary.y = wymiary.y;
	sf::Vector2f window_size(800.f, 600);
	init(window_size);
}
interfejs::~interfejs() {
	delete prostokat;
	prostokat = NULL;
	delete lewy;
	lewy = NULL;
	delete prawy;
	prawy = NULL;
	delete dolsrodek;
	dolsrodek = NULL;
	delete gorasrodek;
	gorasrodek = NULL;
}
void interfejs::draw(sf::RenderWindow& window) {
	window.draw(*prostokat);
	window.draw(*lewy);
	window.draw(*prawy);
	window.draw(*dolsrodek);
	window.draw(*gorasrodek);
}

void interfejs::setText(sf::Text* lewy, sf::Text* prawy, sf::Text* dolsrodek, sf::Text* gorasrodek) {

	font = new sf::Font;
	font->loadFromFile("arial.ttf");
	lewy->setFont(*font);
	prawy->setFont(*font);
	dolsrodek->setFont(*font);
	gorasrodek->setFont(*font);

	lewy->setString("Punkty:");
	lewy->setFillColor(sf::Color(45, 8, 210));
	lewy->setPosition(10.f, 5.f);

	prawy->setString("Poziom:");
	prawy->setFillColor(sf::Color(24, 200, 55));
	prawy->setPosition(600.f, 5.f);

	dolsrodek->setString("Animowany napis");
	dolsrodek->setFillColor(sf::Color(80, 25, 8));
	dolsrodek->setPosition(310.f, 550.f);

	gorasrodek->setString("Zycia");
	gorasrodek->setFillColor(sf::Color(40, 80, 160));
	gorasrodek->setPosition(310.f, 5.f);
}

void interfejs::init(sf::Vector2f window_size) {

	lewy = new sf::Text;
	prawy = new sf::Text;
	dolsrodek = new sf::Text;
	gorasrodek = new sf::Text;
	prostokat = new sf::RectangleShape;

	prostokat->setPosition(20.f, 50.f);
	prostokat->setSize(wymiary);
	prostokat->setFillColor(sf::Color(10, 200, 100));

	setText(lewy, prawy, dolsrodek, gorasrodek);

}
//interface/////////////////
//gra///////////////////
	//paletka//////////////////////////
class paletka {
private:
	sf::RectangleShape palletka;
	sf::Vector2f position;
	float xVel = 10;
	float yVel = 10;
	
public:
	paletka(float x_in, float y_in)
	{
		position.x = x_in;
		position.y = y_in;
		palletka.setFillColor(sf::Color(10, 50, 150));
		palletka.setSize(sf::Vector2f(80, 30));
		palletka.setOutlineThickness(10);
		palletka.setOutlineColor(sf::Color(0, 0, 0));
		palletka.setPosition(position);
	};
	void przesun(float x_in, float y_in)
	{
		sf::Vector2f pos;
		pos.x = x_in;
		pos.y = y_in;
		palletka.move(pos);
	};
	sf::RectangleShape getPaletka() { return palletka; }
	sf::Vector2f getPos() { return palletka.getPosition(); }
};
	//paletka///////////////////
	//pokeball//////////////////////
class Pokeball {
private:
	sf::Vector2f position;
	float xVel = 1, yVel = 1;
	sf::Texture tekstura;
	sf::Sprite pSprite;
	sf::Vector2f rozmiar_okna;
	float x = 760, y = 500;

public:
	Pokeball(float x_in, float y_in, float x_a, float y_b) {
		position.x = x_in;
		position.y = y_in;
		rozmiar_okna.x = x_a;
		rozmiar_okna.y = y_b;
		tekstura.loadFromFile("pokeball.png");
		pSprite.setTexture(tekstura);
		pSprite.setPosition(position);

	}
	
	void przesun(float x_in, float y_in) {
		sf::Vector2f pos;
		pos.x = x_in;
		pos.y = y_in;
		pSprite.move(pos);
		position = pSprite.getPosition();
	}
	sf::Sprite getPokeball() {
		return pSprite;
	}
	sf::Vector2f getPos() {
		return pSprite.getPosition();
	}
	void sprawdzKolizjeSciany() {
		if (position.x <= 20)
			xVel = 5;
		if (position.x >= 680)
			xVel = -2;
		if (position.y <= 50)
			yVel = 4;
		if (position.y >= 450)
			yVel = -3;
	}
	void animuj() {
		sprawdzKolizjeSciany();
		przesun(xVel, yVel);
		
	}
};
	//pokeball///////////////////
	// trawa///////////
class obiekty {
private:
	int N, M;
	sf::RectangleShape* oobiekty1;
	sf::RectangleShape* oobiekty2;
	sf::RectangleShape* oobiekty3;
public:
	obiekty( int Nt, int Mt) {
		float x = 0, y = 0;
		M = Mt;
		N = Nt;
		oobiekty1 = new sf::RectangleShape[N];
		oobiekty2 = new sf::RectangleShape[N];
		oobiekty3 = new sf::RectangleShape[N];

		for (int i = 0; i < N; i++) {
			x = 25+i*50;
			
			oobiekty1[i] = sf::RectangleShape(sf::Vector2f(45, 45));
			oobiekty1[i].setPosition(sf::Vector2f(x, 55));
			oobiekty1[i].setFillColor(sf::Color(33, 47, 148));
			oobiekty1[i].setOutlineColor(sf::Color(0,0,0));
			oobiekty1[i].setOutlineThickness(2);
			
			oobiekty2[i] = sf::RectangleShape(sf::Vector2f(45, 45));
			oobiekty2[i].setPosition(sf::Vector2f(x, 105));
			oobiekty2[i].setFillColor(sf::Color(140, 0, 20));
			oobiekty2[i].setOutlineColor(sf::Color(0, 0, 0));
			oobiekty2[i].setOutlineThickness(2);

			oobiekty3[i] = sf::RectangleShape(sf::Vector2f(45, 45));
			oobiekty3[i].setPosition(sf::Vector2f(x, 155));
			oobiekty3[i].setFillColor(sf::Color(0,133, 5));
			oobiekty3[i].setOutlineColor(sf::Color(0, 0, 0));
			oobiekty3[i].setOutlineThickness(2);

		}
	};

	void draw(sf::RenderWindow& window) {
		for (int i = 0; i < N; i++)
		{
			window.draw(oobiekty1[i]);
			window.draw(oobiekty2[i]);
			window.draw(oobiekty3[i]);
		}
	};
};
	// trawa///////////////
	// pokemony////////////////
class pokemon {

};
	// pokemony/////////////
//gra/////////////////
int main(){
	using namespace std;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Gwiazdozbior");
	sf::Clock zegar;
	
	interfejs p1(sf::Vector2f(760.f, 500.f));
	gwiazdozbior td(1000);
	Pokeball pb(400, 10, 760, 500);
	paletka pal(320,504);
	obiekty ob(15,3);
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
			cout << pal.getPos().x<<"...." <<pal.getPos().y<<"..."<< pb.getPos().x << "..." << pb.getPos().y << endl;
			if (pb.getPos().x+50 >= pal.getPos().x-10 && pb.getPos().x+50 <= pal.getPos().x + 90 && pb.getPos().y+100 >= pal.getPos().y - 15 && pb.getPos().y + 100 <= pal.getPos().y - 8)
		{
			cout << "Kolizja";
		}
			
			
		}
		
		
		

		window.clear(sf::Color::Black);
		td.draw(window);//metoda draw() obiektu klasy toads
		p1.draw(window);
		window.draw(pal.getPaletka());
		window.draw(pb.getPokeball());
		ob.draw(window);
		window.display();

		
		
		//t�o///////////////////////////////////////////////////////////////////
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
   -Zanimowane t�o typu gwiazdy
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
   -Wy�wiatlaj� sie nasze nick i ID
 3)WYniki:
   -wy�wietlane w fomie tablicy:
    >miejsce
	>Nick
	>ID
	>Punkty
	>Z�apane potworki
 4)Kolekcja:
   -Wy�wietlane obrazki z�apanych ju� stwork�w
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
	-Napisy
	 >punkty
	 >Zmieniaj�cy si� komunikaty:"Z�apany!","Straci�e� �ycie!", "Wszystkie z�apane!"
	 >Zycia
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
