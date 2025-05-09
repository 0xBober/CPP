
#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <vector>

// DEKLARACJE FUNCJI

std::vector<int> generuj_wektor();

/** Funkcja wypisuje wektor na ekran.
 @param tablica wektor do wypisania */
void wypisz(const std::vector<int> &tablica);

int zsumuj(const std::vector<int> &tablica);

void dodaj_do_wszystkich(std::vector<int> &tablica, int dodajnik);

std::vector<int> dodaj(const std::vector<int> &lewe, const std::vector<int> &prawe);

std::vector<int> odejmij(const std::vector<int> &lewe, const std::vector<int> &prawe);

std::vector<int> przetnij(const std::vector<int> &lewe, const std::vector<int> &prawe);

std::vector<int> unikalne(const std::vector<int> &tablica);

void wydziel_parzyste_nieparzyste(const std::vector<int> &liczby, std::vector<int> &parzyste, std::vector<int> &nieparzyste);

#endif
