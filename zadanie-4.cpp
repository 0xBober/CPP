/*
	PODSTAWY PROGRAMOWANIA KOMPUTERÓW
	lab-04

	tablice
 */

#include <iostream>
#include <random>
#include <chrono>
#include <array>

int main()
{
	// TABLICE JEDNOWYMIAROWE

	/* 1. Proszę zadeklarować stałą N i tablicę «calkowite» liczba całkowitych. */

	const int N{100};
	std::array<int, N> calkowite;

	/* 2. Proszę napisać kod wypisujący tablicę «calkowite» na ekran. */

	std::cout << "Tablica calkowite: " << std::endl;
	for (int liczba : calkowite)
	{
		std::cout << liczba << "\t";
	}
	std::cout << "\n" << std::endl;

	/* 3. Proszę napisać kod, który wypełnia tablicę «całkowite» liczbami losowymi. */

	std::default_random_engine silnik;										  // silnik do generowania liczb losowych
	silnik.seed(std::chrono::system_clock::now().time_since_epoch().count()); // ustawienie ziarna silnika z użyciem aktualnego czasu

	const int MAX{50};
	std::uniform_int_distribution<int> rozklad{0, MAX - 1};

	int losowa = rozklad(silnik); // wylosowanie liczby losowej :-)

	for (int i = 0; i < N; i++)
	{
		calkowite.at(i) = rozklad(silnik);
	}

	/* ... i wypisać tablicę na ekran.  */

	std::cout << "Tablica calkowite wypelniona losowymi wartosciami: " << std::endl;

	for (int liczba : calkowite)
	{
		std::cout << liczba << "\t";
	}
	std::cout << std::endl;

	/* 4. Proszę policzyć, ile razy w tablicy «całkowite» występuje każda wartość. Wynik, proszę wpisać do tablicy «licznik» w odpowiednie miejsce, tzn. do komórki k-tej «licznika» proszę wpisać, ile razy wartość k występuje w tablicy «całkowite».  */

	std::array<int, MAX> licznik{0};

	for (int liczba : calkowite)
	{
		licznik.at(liczba)++;
	}
	std::cout << std::endl;

	/* 5. Proszę wypisać indeks i  wartości spod indeksu dla tablicy «licznik». */

	for (int i = 0; i < MAX; i++)
	{
		if (licznik.at(i) > 0)
		{
			std::cout << "Wartosc " << i << " wystepuje " << licznik.at(i) << " razy." << std::endl;
		}
	}

	// TABLICE DWUWYMIAROWE

	/* 6. Proszę zdefiniować tablicę dwuwymiarową «t2» liczb całkowitych o rozmiarach W wierszy i K kolumn.  */

	const int W{5};
	const int K{10};
	std::array<std::array<int, K>, W> t2;

	/* 8. Proszę wypisać tablicę. */

	std::cout << "\nTablica t2: " << std::endl;

	for (const auto &wiersz : t2)
	{
		for (int liczba : wiersz)
		{
			std::cout << liczba << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	/* 7. Proszę wypełnić tablicę wartościami od 1 do W * K wierszami od góry do dołu i w wierszu od lewej do prawej */

	int wartosc = 1;

	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < K; j++)
		{
			t2.at(i).at(j) = wartosc++;
		}
	}
	std::cout << std::endl;

	/* ... i wypisać tablicę: */

	std::cout << "Tablica t2 wypelniona wartosciami od 1 do W * K: " << std::endl;

	for (const auto &wiersz : t2)
	{
		for (int liczba : wiersz)
		{
			std::cout << liczba << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	/* 8. Proszę wypełnić tablicę wartościami od 1 do W * K bustrofedonem. */

	wartosc = 1;

	for (int i = 0; i < W; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < K; j++)
			{
				t2.at(i).at(j) = wartosc++;
			}
		}
		else
		{
			for (int j = K - 1; j >= 0; j--)
			{
				t2.at(i).at(j) = wartosc++;
			}
		}
	}
	std::cout << std::endl;

	/* ... i wypisać tablicę: */

	std::cout << "Tablica t2 wypelniona wartosciami od 1 do W * K bustrofedonem: " << std::endl;

	for (const auto &wiersz : t2)
	{
		for (int liczba : wiersz)
		{
			std::cout << liczba << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	/* 9. Proszę utworzyć tablicę jednowymiarową «srednie» o rozmiarze W i wpisać do niej średnią z każdego wiersza tablicy «t2». */

	std::array<double, W> srednie{0.0};

	for (int i = 0; i < W; i++)
	{
		int suma = 0;
		for (int j = 0; j < K; j++)
		{
			suma += t2.at(i).at(j);
		}
		srednie.at(i) = static_cast<double>(suma) / K;
	}

	/* ... i wypisać wartości srednich. */
	for (int i = 0; i < W; i++)
	{
		std::cout << "Srednia wiersza " << i << " wynosi: " << srednie.at(i) << std::endl;
	}

	/* 10. Proszę wypełnić tablicę «t2» wartościami losowymi i ją wypisać, ... */

	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < K; j++)
		{
			t2.at(i).at(j) = rozklad(silnik);
		}
	}

	std::cout << std::endl;
	std::cout << "Tablica t2 wypelniona losowymi wartosciami: " << std::endl;

	for (const auto &wiersz : t2)
	{
		for (int liczba : wiersz)
		{
			std::cout << liczba << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	/* ... wyznaczyć maksimum każdej kolumny i zapisać wartości to tablicy «maksima» ... */

	std::array<int, K> maksima{0};

	int max;

	for (int j = 0; j < K; j++)
	{
		max = t2.at(0).at(j);
		for (int i = 1; i < W; i++)
		{
			max = (t2.at(i).at(j) > max) ? t2.at(i).at(j) : max;
		}
		maksima.at(j) = max;
	}
	/* ... i wypisać «maksima». */

	for (int i = 0; i < K; i++)
	{
		std::cout << "Maksimum kolumny " << i << " wynosi: " << maksima.at(i) << std::endl;
	}

	return 0;
}
