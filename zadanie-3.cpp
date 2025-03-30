/*
	PODSTAWY PROGRAMOWANIA KOMPUTERÓW
	lab-05

	wektory
 */

#include <iostream>
#include <random>
#include <chrono>
#include <vector>   // biblioteka definiująca wektor
#include <cmath>
#include <algorithm>

int main ()
{
	int NR_Zadania = 1;

	/* 1. Proszę zadeklarować wektor liczb całkowitych o nazwie «calkowite». */
	std::cout << "Zadanie nr " << NR_Zadania++ << std::endl;
	std::vector<int> calkowite;

	/* 2. Proszę zdefiniować zmienną n i ją zainicjować. Proszę wypełnić wektor «calkowite» n liczbami losowymi. */

	std::cout << "Zadanie nr " << NR_Zadania++ << std::endl;
	const int MAX { 100 };
	std::default_random_engine silnik;
	silnik.seed(std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_int_distribution rozklad { 0, MAX - 1};

	const int N = 500;

	for(int i = 0; i < N; i++){
		calkowite.push_back(rozklad(silnik));
	}


	/* 3. Proszę wypisać liczby w wektorze. Proszę skorzystać z zakresowej pętli for. */

	std::cout << "Zadanie nr " << NR_Zadania++ << std::endl;
	std::cout << "Lista Liczby Calkowitych:" << std::endl;
	for(int liczba : calkowite){
		std::cout << liczba << " ";
	}
	std::cout << std::endl;

	/* 4. Proszę stworzyć wektory: «parzyste» i «nieparzyste». */

	std::cout << "Zadanie nr " << NR_Zadania++ << std::endl;
	std::vector<int> parzyste;
	std::vector<int> nie_parzyste;

	/* 5. Proszę skopiować do wektora «parzyste» parzyste liczby z wektora «całkowite», a nieparzyste do wektora «nieparzyste». Proszę skorzystać z pętli for z indeksem. */

	std::cout << "Zadanie nr " << NR_Zadania++ << std::endl;
	for(int liczba : calkowite){
		if(liczba % 2 == 0){
			parzyste.push_back(liczba);
		}else{
			nie_parzyste.push_back(liczba);
		}
	}

	/* 6. Proszę wypisać wektory «parzyste» i «nieparzyste». */

	std::cout << "Zadanie nr " << NR_Zadania++ << std::endl;
	std::cout << "LICZBY PARZYSTE:" <<std::endl;
	for(int liczba : parzyste){
		std::cout << liczba << " ";
	}
	std::cout << std::endl;

	std::cout << "LICZBY NIE PARZYSTE:" <<std::endl;
	for(int liczba : nie_parzyste){
		std::cout << liczba << " ";
	}
	std::cout << std::endl;

	/* 7. Proszę zanegować liczby w wektorze «nieparzyste». Proszę skorzystać z zakresowej pętli for, ...  */

	std::cout << "Zadanie nr " << NR_Zadania++ << std::endl;
	for(int i = 0; i < nie_parzyste.size(); i++){
		nie_parzyste[i] = not nie_parzyste[i];
	}
	
	/* ... i proszę wypisać «nieparzyste».  */ 		

	std::cout << "LICZBY NIE PARZYSTE PO NEGACJII:" <<std::endl;
	for(int liczba : nie_parzyste){
		std::cout << liczba << " ";
	}
	std::cout << std::endl;

	/* 8. Proszę znaleźć maksimum w wektorze «parzyste». */

	std::cout << "Zadanie nr " << NR_Zadania++ << std::endl;
	int MAXIMUM_PARZYSTY = 0;

	for(int i = 0; i < parzyste.size(); i++){
		MAXIMUM_PARZYSTY = (MAXIMUM_PARZYSTY < parzyste[i]) ? parzyste[i] : MAXIMUM_PARZYSTY;
	}

	std::cout << "MAXIMUM:" << MAXIMUM_PARZYSTY << std::endl;

	/* 9. Proszę znaleźć największą bezwzględną różnicę między dwiema sąsiednimi liczbami w «parzystych». Np. Jeżeli wektor zawiera liczby [ 4 34 78 12 6 90 ], największa bezwględna różnica wynosi 84 (tzn. 90 - 6). */

	std::cout << "Zadanie nr " << NR_Zadania++ << std::endl;
	int Najwieksza_roznica = 0;
	int roznica;

	for(int i = 0; i < parzyste.size() - 1; i++){
		roznica = abs(parzyste[i] - parzyste[i+1]);
		Najwieksza_roznica = (Najwieksza_roznica < roznica) ? roznica: Najwieksza_roznica;
	}

	std::cout << "Najwieksza roznica wynosi: " << Najwieksza_roznica << std::endl;



	/* 10. Proszę znaleźć największą bezwzględną różnicę między dwiema liczbami w «parzystych». Np. Jeżeli wektor zawiera liczby [ 4 34 78 12 6 90 ], największa bezwględna różnica wynosi 86 (tzn. 90 - 4). */

	std::cout << "Zadanie nr " << NR_Zadania++ << std::endl;
	int MINIMUM_PARZYSTY = 0;

	for(int i = 0; i < parzyste.size(); i++){
		MINIMUM_PARZYSTY = (MINIMUM_PARZYSTY > parzyste[i]) ? parzyste[i] : MINIMUM_PARZYSTY;
	}

	int ROZNICA_MIN_MAX_BEZW = abs(MAXIMUM_PARZYSTY - MINIMUM_PARZYSTY);
	std::cout << "Najwieksza bezwzgledna roznica miedzy liczbami wynosi: " << ROZNICA_MIN_MAX_BEZW << std::endl;

	/* 11. Proszę wyczyścić wektory «nieparzyste» i «parzyste». */

	std::cout << "Zadanie nr " << NR_Zadania++ << std::endl;
	while(!parzyste.empty()){
		parzyste.pop_back();
	}

	while(!nie_parzyste.empty()){
		nie_parzyste.pop_back();
	}

	if(parzyste.empty()){
		std::cout << "Vektor Parzysty jest pusty" << std::endl;
	}else{
		std::cout << "Vektor Parzysty jest nie pusty" << std::endl;
	}

	if(nie_parzyste.empty()){
		std::cout << "Vektor Nie Parzysty jest pusty" << std::endl;
	}else{
		std::cout << "Vektor Nie Parzysty jest nie pusty" << std::endl;
	}
	/* 12. Proszę dodać do «nieparzystych» kolejne rosnące liczby nieparzystych (od 1), a do «parzystych» kolejne rosnące liczby parzystej. Oba wektory powinny liczyć po n liczb. */

	std::cout << "Zadanie nr " << NR_Zadania++ << std::endl;
	for(int i = 0; i < N; i++){
		if(i % 2 == 0){
			parzyste.push_back(i);
		}else{
			nie_parzyste.push_back(i);
		}
	}

	/* ... proszę wypisać oba wektory ...  */

	std::cout << "LICZBY PARZYSTE:" <<std::endl;
	for(int liczba : parzyste){
		std::cout << liczba << " ";
	}
	std::cout << std::endl;

	std::cout << "LICZBY NIE PARZYSTE:" <<std::endl;
	for(int liczba : nie_parzyste){
		std::cout << liczba << " ";
	}
	std::cout << std::endl;


	/* 13. Proszę scalić wartości wektorów «parzyste» i «nieparzyste» w jeden wektor «scalone» zawierający liczby w porządku rosnącym. */

	std::cout << "Zadanie nr " << NR_Zadania++ << std::endl;
	
	std::vector<int> scalone;

	for(int i = 0; i < parzyste.size(); i++){
		scalone.push_back(parzyste.at(i));
		scalone.push_back(nie_parzyste.at(i));
	}

	/* ... i wypisać «scalone». */

	std::cout << "Vektor Scalone:" <<std::endl;
	for(int liczba : scalone){
		std::cout << liczba << " ";
	}
	std::cout << std::endl;

	/* 14. Proszę stworzyć dwa wektory (A i B) liczb całkowitych i wypełnić je n liczbami losowymi.  */

	std::cout << "Zadanie nr " << NR_Zadania++ << std::endl;
	std::vector<int> A, B;

	for(int i = 0; i < N/10; i++){
		A.push_back(rozklad(silnik));
	}

	for(int i = 0; i < N/10; i++){
		B.push_back(rozklad(silnik)  * 2);
	}
	/* .... proszę przemożyć każdą wartość w B przed 2 ...  */

	std::cout << "Vektor A przed sortowaniem:" <<std::endl;
	for(int liczba : A){
		std::cout << liczba << " ";
	}
	std::cout << std::endl;

	std::cout << "Vektor B przed sortowaniem:" <<std::endl;
	for(int liczba : B){
		std::cout << liczba << " ";
	}
	std::cout << std::endl;

	/* ... sortujemy oba wektory ...  */

	std::sort(A.begin(), A.end());
	std::sort(B.begin(), B.end());

	/* ... proszę wypisać oba wektory ... */

	std::cout << "Vektor A po sortowaniu:" <<std::endl;
	for(int liczba : A){
		std::cout << liczba << " ";
	}
	std::cout << std::endl;

	std::cout << "Vektor B po sortowaniu:" <<std::endl;
	for(int liczba : B){
		std::cout << liczba << " ";
	}
	std::cout << std::endl;

	/* ... proszę scalić posortowane wektory A i B w jeden posortowany wektor «wszystkie». */

	std::vector<int> wszystkie;
	int iterator_A = 0;
	int iterator_B = 0;

	while(iterator_A < A.size() and iterator_B < B.size()){
		if(A.at(iterator_A) < B.at(iterator_B)){
			wszystkie.push_back(A.at(iterator_A));
			iterator_A++;
		}else{
			wszystkie.push_back(B.at(iterator_B));
			iterator_B++;
		}
	}

	/* ... i wypisujemy kontrolnie «wszystkie»  */

	std::cout << "WSZYSTKIE(A+B)" << std::endl;
	for(int liczba : wszystkie){
		std::cout << liczba << " ";
	}
	
	
	/* 15. Proszę usunąć zawartość wektorów A i B, a następnie wypełnić je n wartościami losowymi. */
  
	std::cout << "Zadanie nr " << NR_Zadania++ << std::endl;
        /* ... proszę stworzyc wektor I będący przecięciem wektorów A i B. */
        
        /* ... wypiszymy A, B i I. */

	

   return 0;
} 

