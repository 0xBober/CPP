

// DEFINICJE FUNCJI

#include <vector>
#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>

#include "funkcje.h"

std::vector<int> generuj_wektor()
{
    const int MIN{-10};
    const int MAX{10};

    const int ROZMIAR_MIN{10};
    const int ROZMIAR_MAX{20};

    static std::default_random_engine silnik(std::chrono::system_clock::now().time_since_epoch().count());
    static std::uniform_int_distribution<int> rozklad(MIN, MAX);
    static std::uniform_int_distribution<int> rozklad_rozmiaru(ROZMIAR_MIN, ROZMIAR_MAX);

    const int rozmiar = rozklad_rozmiaru(silnik);

    std::vector<int> liczby;
    for (int i = 0; i < rozmiar; i++)
        liczby.push_back(rozklad(silnik));

    return liczby;
}

void wypisz(const std::vector<int> &tablica)
{
    for (const auto &liczba : tablica)
        std::cout << liczba << "\t";
    std::cout << std::endl;
}

int zsumuj(const std::vector<int> &tablica)
{
    int suma = 0;
    for (auto &liczba : tablica)
        suma += liczba;

    return suma;
}

void dodaj_do_wszystkich(std::vector<int> &tablica, int dodajnik)
{
    for (auto &liczba : tablica)
        liczba += dodajnik;
}

// std::vector<int> dodaj(const std::vector<int> &lewe, const std::vector<int> &prawe)
// {
//     std::vector<int> tablica_lewa_prawa;

//     int max = (lewe.size() > prawe.size()) ? prawe.size() : lewe.size();

//     for (int i = 0; i < max; ++i)
//     {
//         tablica_lewa_prawa.push_back(lewe[i] + prawe[i]);
//     }

//     if (lewe.size() > prawe.size())
//     {
//         for (int i = max; i < lewe.size(); ++i)
//         {
//             tablica_lewa_prawa.push_back(lewe[i]);
//         }
//     }
//     else
//     {
//         for (int i = max; i < prawe.size(); ++i)
//         {
//             tablica_lewa_prawa.push_back(prawe[i]);
//         }
//     }
//     return tablica_lewa_prawa;
// }

std::vector<int> dodaj(const std::vector<int> &lewe, const std::vector<int> &prawe)
{
    std::vector<int> lewa_prawa_tablica;

    for (auto &liczba : lewe)
    {
        if (std::find(lewa_prawa_tablica.begin(), lewa_prawa_tablica.end(), liczba) == lewa_prawa_tablica.end())
            lewa_prawa_tablica.push_back(liczba);
    }

    for (auto &liczba : prawe)
    {
        if (std::find(lewa_prawa_tablica.begin(), lewa_prawa_tablica.end(), liczba) == lewa_prawa_tablica.end())
            lewa_prawa_tablica.push_back(liczba);
    }

    return lewa_prawa_tablica;
}

std::vector<int> odejmij(const std::vector<int> &lewe, const std::vector<int> &prawe)
{
    std::vector<int> lewa_prawa_tablica;

    for (auto &liczba : lewe)
    {
        if (std::find(lewa_prawa_tablica.begin(), lewa_prawa_tablica.end(), liczba) == lewa_prawa_tablica.end())
            if (std::find(prawe.begin(), prawe.end(), liczba) == prawe.end())
                lewa_prawa_tablica.push_back(liczba);
    }

    return lewa_prawa_tablica;
}

std::vector<int> przetnij(const std::vector<int> &lewe, const std::vector<int> &prawe)
{
    std::vector<int> lewa_prawa_tablica;

    for (auto &liczba : lewe)
    {
        if (std::find(lewa_prawa_tablica.begin(), lewa_prawa_tablica.end(), liczba) == lewa_prawa_tablica.end())
            if (std::find(prawe.begin(), prawe.end(), liczba) != prawe.end())
                lewa_prawa_tablica.push_back(liczba);
    }

    return lewa_prawa_tablica;
}

std::vector<int> unikalne(const std::vector<int> &tablica)
{
    std::vector<int> unikalne_liczby;

    for (auto it = tablica.begin(); it != tablica.end(); ++it)
    {
        if (std::find(tablica.begin(), it, *it) == it && std::find(it + 1, tablica.end(), *it) == tablica.end())
            unikalne_liczby.push_back(*it);
    }

    return unikalne_liczby;
}

void wydziel_parzyste_nieparzyste(const std::vector<int> &liczby, std::vector<int> &parzyste, std::vector<int> &nieparzyste)
{

    for (auto &liczba : liczby)
    {
        if (liczba % 2 == 0)
        {
            parzyste.push_back(liczba);
        }
        else
        {
            nieparzyste.push_back(liczba);
        }
    }
}