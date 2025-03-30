
#include <iostream>   // operacje wejscia/wyjscia, pisanie na ekranie, czytanie z klawiatury


int main ()
{
   int W, K;
   int zadanie { 0 };
   
   std::cout << "Podaj rozmiary prostokata: ";
   std::cin >> W >> K;
   
   ///////////////////////////////////////////////////////////////
   std::cout << std::endl << "ZADANIE " << zadanie++ << std::endl;
   
   
   // Prosze napisac fragment kodu, ktory zapisuje iksami prostokat
   // o rozmiarach W na K. 
   
   for (int w = 0; w < W; w++)
   {
      for (int k = 0; k < K; k++)
      {
         std::cout << 'X';
      }
      std::cout << std::endl;
   }
   
   ///////////////////////////////////////////////////////////////
   std::cout << std::endl << "ZADANIE " << zadanie++ << std::endl;
      
   // Prosze napisac fragment kodu, ktory wypelnia prostokat poziomymi
   // pasami o wysokosci 1 znaku. Pasy sa zbudowane za zmiane z 'X' i '.'.

   for(int i = 0; i < W; i++){
      for(int j = 0; j < K; j++){
         if(i % 2 == 0){
            std::cout << "X";
         }else{
            std::cout << ".";
         }
      }
      std::cout << std::endl;
   }
         
   ///////////////////////////////////////////////////////////////
   std::cout << std::endl << "ZADANIE " << zadanie++ << std::endl;
   
   // Prosze napisac fragment kodu, ktory wypelnia prostokat pionowymi
   // pasami o szerokosci 1 znaku. Pasy sa zbudowane za zmiane z 'X' i '.'.
   
   for(int i = 0; i < W; i++){
      for(int j = 0; j < K; j++){
         if(j % 2 == 0){
            std::cout << "X";
         }else{
            std::cout << ".";
         }
      }
      std::cout << std::endl;
   }
   
   ///////////////////////////////////////////////////////////////
   std::cout << std::endl << "ZADANIE " << zadanie++ << std::endl;
   
   // Prosze napisac fragment kodu, ktory wypelnia prostokat
   // w szachownice iksow i kropek.
   
   for(int i = 0; i < W; i++){
      for(int j = 0; j < K; j++){
         if((i+j)%2 == 0){
            std::cout << "X";
         }else{
            std::cout << ".";
         }
      }
      std::cout << std::endl;
   }


   ///////////////////////////////////////////////////////////////
   std::cout << std::endl << "ZADANIE " << zadanie++ << std::endl;
   
   // Prosze napisac fragment kodu, ktory rysuje ramke prostokata z iksow.

   for (int i = 0; i < W; i++){
   if(i == 0 || i == W-1){
      for(int j = 0; j < K; j++){
         std::cout << "X";
         if(j == K-1){std::cout << std::endl;}
      }
      continue;
   }

   for(int j = 0; j < K; j++){
      if(j == 0 || j == K-1){
         std::cout << "X";
         if(j == K-1){std::cout << std::endl;}
      }
      else{
         std::cout << " ";
      }
   }
}
   

   ///////////////////////////////////////////////////////////////
   std::cout << std::endl << "ZADANIE " << zadanie++ << std::endl;
   
   // Prosze napisac fragment kodu, ktory rysuje szachownice zbudowana 
   // z czterech cwierci (z dokladnoscia do jednego znaku). 

   for(int i = 0; i < W; i++){
      for(int j = 0; j < K; j++){
         if(i < (W/2) && j < (K/2)){
            std::cout << "X";
         }else{
            std::cout << ".";
         }
      }
      std::cout << std::endl;
         
   }
   
    
   ///////////////////////////////////////////////////////////////
   std::cout << std::endl << "ZADANIE " << zadanie++ << std::endl;
   
   // Prosze napisac fragment kodu, ktory rysuje katy zbudowane z 'X' i ' '.
   // Przyklad:
   //    XXXXXXXX
   //    X    
   //    X XXXXXX
   //    X X 
   //    X X XXXX 
   //    X X X
   //    X X X XX 
   //    X X X X
   
      
   return 0;

}
