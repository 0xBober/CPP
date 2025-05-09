
#include <vector>
#include <string>
#include <iostream>

#include "funkcje.h"
#include "struktury.h"

int main()
{
	const std::string PLIK_PUNKTY{"punkty.txt"};
	const int LICZBA_PUNKTOW{1000};
	generuj_punkty(PLIK_PUNKTY, LICZBA_PUNKTOW);

	//////////////////////
	std::vector<punkt> punkty = wczytaj_punkty(PLIK_PUNKTY);
	std::cout << "wczytane punkty: " << std::endl;
	for (const punkt &p : punkty)
		wypisz_punkty(p);

	//////////////////////
	// wyznaczny odleglosc euklidesowa pomiedzy dwoma punktami
	punkt pierwszy = punkty.front();
	punkt ostatni = punkty.back();
	double odleglosc = euklides(pierwszy, ostatni); // pierwszy i ostatni punkt
	std::cout << "losowe punkty:" << std::endl;
	wypisz_punkty(punkty.front());
	wypisz_punkty(punkty.back());
	std::cout << "odlegosc: " << odleglosc << std::endl;
	std::cout << std::endl;

	//////////////////////
	punkt A = punkty[punkty.size() / 4];
	punkt B = punkty[punkty.size() * 3 / 4];

	odcinek AB{A, B};
	std::cout << "losowy odcinek" << std::endl;
	wypisz_odcinek(AB);
	std::cout << "dlugosc: " << dlugosc(AB) << std::endl;
	std::cout << std::endl;

	//////////////////////
	// wyszukujemy najdluzszy odcinek miedzy punktami
	odcinek najdluzszy = najdluzszy_odcinek(punkty);
	std::cout << "najdluzszy odcinek:" << std::endl;
	wypisz_odcinek(najdluzszy);
	std::cout << "dlugosc: " << dlugosc(najdluzszy) << std::endl;
	std::cout << std::endl;

	//////////////////////
	// obwod trojkata:
	trojkat ABC{punkty[punkty.size() / 4],
				punkty[punkty.size() / 2],
				punkty[punkty.size() * 3 / 4]};
	double obwod_ABC = obwod(ABC);
	std::cout << "losowy trojkat" << std::endl;
	wypisz_trojkat(ABC);
	std::cout << "obwod trojkata: " << obwod_ABC << std::endl;
	std::cout << std::endl;

	//////////////////////
	// wyszukujemy trojkat o najdluzszym obwodzie ze wszystkich mozliwych trojkatow, zbudowanych w zbiorze punktow
	trojkat najwiekszy = najwiekszy_trojkat(punkty);
	std::cout << "trojkat o najwiekszym obwodzie:" << std::endl;
	wypisz_trojkat(najwiekszy);
	std::cout << "obwod trojkata: " << obwod(najwiekszy) << std::endl;

	return 0;
}
