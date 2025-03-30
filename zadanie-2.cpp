/*
	PODSTAWY PROGRAMOWANIA KOMPUTERÓW
	lab-04

	tablice
 */

#include <iostream>
#include <random>
#include <chrono>
#include <limits>

int main ()
{
   // TABLICE 
	
	std::default_random_engine silnik; // silnik do generowania liczb losowych
	silnik.seed(std::chrono::system_clock::now().time_since_epoch().count()); // ustawienie ziarna silnika z użyciem aktualnego czasu

	std::normal_distribution<double> rozklad {12.3, 2.0};

	const int N { 50 };
	double liczby[N];

	// wypelnienie tablicy liczbami pseudolosowymi:
	for (int i = 0; i < N; i++)
		liczby[i] = rozklad(silnik);
	
	/* 0. Prosze wypisac liczby z tablicy liczby na ekran. */
	
	std::cout <<"Liczby:" << std::endl;
	for (int i = 0; i < N; i++)
	{
		std::cout << liczby[i] << "\t";
		if((i+1) % 10 == 0){std::cout << std::endl;}
	}
	std::cout << std::endl;

	/* 1. Prosze znalezc wartosc maksymalna w tablicy liczb. */
	double maksimum = liczby[0];

	for(int i = 1; i < N; i++){
		maksimum = (liczby[i] > maksimum) ? liczby[i] : maksimum;
	}
	
	std::cout << "maksimum: " << maksimum <<  std::endl;

	/* 2. Prosze wyznaczyc srednia wartosci w tablicy. */
	double srednia = 0.0;
	
	for(int i = 0; i < N; i++){
		srednia += liczby[i];
	}
	
	srednia /= N;
	
	
	std::cout << "srednia: " << srednia <<  std::endl;
	
	/* 3. Prosze odwrocic wartosci w tablicy */
	std::cout << "odwrocone:" << std::endl;
	for (int i = N-1; i >= 0; i--)
	{
		std::cout << liczby[i] << "\t";
		if(i % 10 == 0){std::cout << std::endl;}
	}
	std::cout << std::endl;

	/* 4. Prosze wyznaczyc liczbe elementow o wartosci mniejszej niz PROG. */
	double PROG {10};
    int ile {0};
	
	for(int i = 0; i < N; i++){
		if(liczby[i] < PROG){ile++;}
	}
	
	std::cout << "ponizej progu " << PROG << ": " << ile <<  std::endl;
	
	/* 5. Prosze wpisac do tablicy skumulowane skumulowane wartosci z tablicy liczby. */
	
	double skumulowane[N];
	
	std::cout << "liczby przed:" << std::endl;
	for (int i = 0; i < N; i++)
	{
		std::cout << liczby[i] << " ";
		if((i+1) % 10 == 0){std::cout << std::endl;}
	}
	std::cout << std::endl;
	
	std::cout << "skumulowane:" << std::endl;
	for (int i = 0; i < N; i++)
	{
		skumulowane[i] = 0.0;
		for(int j = 0; j <= i; j++){
			skumulowane[i] += liczby[j];
		}
		std::cout << skumulowane[i] << " ";
		if((i+1) % 10 == 0){std::cout << std::endl;}
	}
	std::cout << std::endl;
	
	/* 5. Prosze wyznaczyc liczbe elementow tablicy skumulowane zanim wartosc elementu przekroczy PROG. */
	PROG = 30;
	int pod_progiem = 0;
	
	while(skumulowane[pod_progiem] < PROG && pod_progiem < N){
		pod_progiem++;
	}

	std::cout << "przed progiem " << PROG << ": ";
	std::cout << pod_progiem << std::endl;
	
    /* 6. Prosze wypisac roznice miedzy kolejnymi elementami tablicy liczby. */	
    
	double tablica_roznice[N-1];

	for(int i = 0; i < N-1; i++){
		tablica_roznice[i] = liczby[i+1] - liczby[i];
	}

	std::cout << "roznice: " << std::endl;
	for (int i = 0; i < N-1; i++)
	{
		std::cout << tablica_roznice[i] << " ";
		if((i+1) % 10 == 0){std::cout << std::endl;}
	}
	std::cout << std::endl;

    /* 7. Prosze wypisac najwieksza roznice miedzy kolejnymi elementami tablicy liczby. */	
	
	maksimum = std::numeric_limits<double>::min(); // najnizsza mozliwa wartosc
	
	for(int i = 0; i < N-1; i++){
		maksimum = (tablica_roznice[i] > maksimum) ? tablica_roznice[i] : maksimum;
	}	
	
	std::cout << "maksimum: " << maksimum << std::endl;

	
	/* 8. Prosze sprzeskalowac wartosci w tablicy w ten sposob, ze wartosc najmniejsza przyjmie wartosc zero, najwieksza zas jeden. */
	double min_val = liczby[0];
	double max_val = liczby[0];

	// Znajdź minimalną i maksymalną wartość w tablicy
	for(int i = 1; i < N; i++){
		if(liczby[i] < min_val) min_val = liczby[i];
		if(liczby[i] > max_val) max_val = liczby[i];
	}

	// Przeskaluj wartości w tablicy
	for(int i = 0; i < N; i++){
		liczby[i] = (liczby[i] - min_val) / (max_val - min_val);
	}

	// Wypisanie tablicy po przeskalowaniu
	std::cout << "przeskalowane" << std::endl;
	for (int i = 0; i < N; i++)
	{
		std::cout << liczby[i] << " ";
		if((i+1) % 10 == 0){std::cout << std::endl;}
	}
	std::cout << std::endl;

	
	/* 9. Prosze wypelnic tablice licznik w nastepujacy sposob:
	 komorka 0 zawiera liczbe liczb z przedzialu [0.0, 0.1)
	 komorka 1 zawiera liczbe liczb z przedzialu [0.1, 0.2)
	 komorka 2 zawiera liczbe liczb z przedzialu [0.2, 0.3)
	 ...
	 komorka 9 zawiera liczbe liczb z przedzialu [0.9, 1.0]
	 */
	
	const int L {10};
	int licznik[L] = {};

	for (int i = 0; i < N; i++)
	{
		licznik[(int)(liczby[i]*10)] += 1;
	}
	
	// wypisanie tablicy licznik
    for (int i = 0; i < L; i++){
		std::cout << i << ": " << licznik[i] << std::endl;
	}
	
	/* 10. Prosze wypisac w pionie tablice licznik i przy kazdym wierszu wypisac liczbe gwiazdek proporcjonalna do wartosic w tablicy licznik. Najwieksza wartosc w tablicy licznik ma G gwiazdek. */
	
	const int G { 70 };

	int maximum = 0;
	for (int i = 0; i < 10; i++)
	{
		if (licznik[i]>maximum)
		{
			maximum = licznik[i];
		}
		
	}
	for (int i = 0; i < 10; i++){
		std::cout << i << ": ";
		for (int j = 0; j < (int)((double)(licznik[i])/maximum*G); j++)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}
	
	return 0;

}