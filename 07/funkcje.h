
// DEKLARACJE (NAGŁÓWKI) FUNKCJI

#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <string>
#include <vector>

#include "struktury.h"

/** Funkcja generuje losowe punkty w przestrzeni dwuwymiarowej i zapisuje je w pliku. Kazda linia pliku oznacza jeden punkt.
  @param PLIK_PUNKTY nazwa pliku do zapisu punktow
  @param LICZBA_PUNKTOW liczba punktow do wygenerowania*/
void generuj_punkty(const std::string &PLIK_PUNKTY, const int LICZBA_PUNKTOW);

/** Funkcja generuje liczbe pseudolosowa z rozkladu normalnego.
  @return wartosc pseudolosowa */
double los();

std::vector<punkt> wczytaj_punkty(const std::string &PLIK_PUNKTY);

void wypisz_punkty(const punkt &p);

void wypisz_odcinek(const odcinek &odc);

double euklides(const punkt &A, const punkt &B);

double dlugosc(const odcinek &odc);

odcinek najdluzszy_odcinek(const std::vector<punkt> &punkty);

double obwod(const trojkat &t);

void wypisz_trojkat(const trojkat &t);

trojkat najwiekszy_trojkat( std::vector<punkt> &punkty);

#endif
