

// DEFINICJE (IMPLEMENTACJE) FUNKCJI

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <random>
#include <chrono>

#include "struktury.h"
#include "funkcje.h"

void generuj_punkty(const std::string &PLIK_PUNKTY, const int LICZBA_PUNKTOW)
{
	const int PREC{8};
	std::ofstream plik(PLIK_PUNKTY);
	if (plik)
	{
		for (int i = 0; i < LICZBA_PUNKTOW; i++)
		{
			plik << std::setprecision(PREC) << los() << '\t'
				 << std::setprecision(PREC) << los() << std::endl;
		}
	}
}

double los()
{
	static std::default_random_engine silnik(std::chrono::system_clock::now().time_since_epoch().count());
	static std::normal_distribution<double> gauss{0, 100};

	return gauss(silnik);
}

std::vector<punkt> wczytaj_punkty(const std::string &PLIK_PUNKTY)
{
	std::ifstream plik(PLIK_PUNKTY);
	std::vector<punkt> punkty;
	if (plik)
	{
		punkt p;
		while (plik >> p.x >> p.y)
		{
			punkty.push_back(p);
		}
	}
	return punkty;
}

void wypisz_punkty(const punkt &p)
{
	std::cout << std::setprecision(8) << p.x << '\t' << p.y << std::endl;
}

void wypisz_odcinek(const odcinek &odc)
{
	std::cout << "odcinek: (" << odc.A.x << ", " << odc.A.y << ") do (" << odc.B.x << ", " << odc.B.y << ")" << std::endl;
}

double dlugosc(const odcinek &odc)
{
	return euklides(odc.A, odc.B);
}

double euklides(const punkt &A, const punkt &B)
{
	return std::sqrt(std::pow(A.x - B.x, 2) + std::pow(A.y - B.y, 2));
}

odcinek najdluzszy_odcinek(const std::vector<punkt> &punkty)
{
	odcinek najdluzszy;
	double max_dlugosc = 0;

	for (size_t i = 0; i < punkty.size(); ++i)
	{
		for (size_t j = i + 1; j < punkty.size(); ++j)
		{
			odcinek odc{punkty[i], punkty[j]};
			double dlugosc_odcinka = euklides(odc.A, odc.B);
			if (dlugosc_odcinka > max_dlugosc)
			{
				max_dlugosc = dlugosc_odcinka;
				najdluzszy = odc;
			}
		}
	}
	return najdluzszy;
}

double obwod(const trojkat &ABC)
{
	return dlugosc({ABC.A, ABC.B}) + dlugosc({ABC.B, ABC.C}) + dlugosc({ABC.C, ABC.A});
}

void wypisz_trojkat(const trojkat &t)
{
	std::cout << "trojkat: (" << t.A.x << ", " << t.A.y << "), ("
			  << t.B.x << ", " << t.B.y << "), ("
			  << t.C.x << ", " << t.C.y << ")" << std::endl;
}

trojkat najwiekszy_trojkat(std::vector<punkt> &punkty)
{
	trojkat najwiekszy;
	double max_obwod = 0;

	for (size_t i = 0; i < punkty.size(); ++i)
	{
		for (size_t j = i + 1; j < punkty.size(); ++j)
		{
			for (size_t k = j + 1; k < punkty.size(); ++k)
			{
				trojkat t{punkty[i], punkty[j], punkty[k]};
				double obwod_trojkata = obwod(t);
				if (obwod_trojkata > max_obwod)
				{
					max_obwod = obwod_trojkata;
					najwiekszy = t;
				}
			}
		}
	}
	return najwiekszy;
}