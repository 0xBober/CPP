/*
	PODSTAWY PROGRAMOWANIA KOMPUTEROW

	lab-06: funkcje
 */

#include <iostream>
#include <vector>

#include "funkcje.h"

/////////////////////////////////////////////
int main()
{
	/* 0. generowanie wektora liczb calkowitych */
	std::vector<int> liczby = generuj_wektor();

	/* 1. funkcja wypisujaca liczby na ekranie */
	std::cout << "liczby: " << std::endl;
	wypisz(liczby);

	/* 2. funkcja zwraca sume wartosci liczb w wektorze */
	int suma = zsumuj(liczby);
	std::cout << "suma: " << suma << std::endl;

	// /* 3. funkcja dodaje do wszystkich liczb w wektorze dodajnik */
	int dodajnik = 7;
	dodaj_do_wszystkich (liczby, dodajnik);
	std::cout << "liczby: " << std::endl;
	wypisz(liczby);

	 	/* Generujemy nowe wektory */
	auto lewe  = generuj_wektor();
	auto prawe = generuj_wektor();

	std::cout << "lewe: " << std::endl;
	wypisz(lewe);
	std::cout << "prawe: " << std::endl;
	wypisz(prawe);

	/* 4. Funkcja dodaje dwa wektory w sensie mnogosciowym (dodawania zbiorow).  */
	auto lewe_plus_prawe = dodaj (lewe, prawe);
	std::cout << "lewe + prawe:" << std::endl;
	wypisz(lewe_plus_prawe);

	/* 5. Funkcja odejmuje dwa wektory w sensie mnogosciowym (odejmowania zbiorow).  */
	auto lewe_minus_prawe = odejmij (lewe, prawe);
	std::cout << "lewe \\ prawe:" << std::endl;
	wypisz(lewe_minus_prawe);

	auto prawe_minus_lewe = odejmij (prawe, lewe);
	std::cout << "prawe \\ lewe:" << std::endl;
	wypisz(prawe_minus_lewe);

	/* 6. Funkcje zwraca przeciecie (czesc wspolna) wektorow. */
	auto przeciecie_lewe_prawe = przetnij (lewe, prawe); // czesc wspolna
	std::cout << "lewe przeciecie prawe:" << std::endl;
	wypisz(przeciecie_lewe_prawe);

	/* 7. Funkcja wzraca wektor z unikalnymi liczbami. */
	auto unikalne_liczby = unikalne (liczby); // czesc wspolna
	std::cout << "unikalne liczby:" << std::endl;
	wypisz(unikalne_liczby);

	/* 8. Funkcja kopiuje wartości parzyste do wektora «parzyste», nieparzyste do «nieparzyste». Oryginalny wektor jest niezmieniony. */
	std::vector<int> parzyste, nieparzyste; // puste wektory na liczby parzyste i nieparzyste
	wydziel_parzyste_nieparzyste(liczby, parzyste, nieparzyste); //

	// wypisanie wektorów na ekran
	std::cout << "liczby: " << std::endl;
	wypisz(liczby);
	std::cout << "parzyste:" << std::endl;
	wypisz(parzyste);
	std::cout << "nieparzyste:" << std::endl;
	wypisz(nieparzyste);

	return 0;
}
