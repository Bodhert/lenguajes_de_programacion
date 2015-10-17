#include <iostream>
#include "arreglo02.h"
using namespace std;

void imprimirArreglo (char nombre[], int arreglo[],const int n){
   for(int i = 0; i < n  ; i++){
     cout << nombre  << "pos: " << i << ":" <<"["<< arreglo[i] << "]" << endl;
  }
}

void concatenarArreglos(int dest[], int fuente[], const int n){
 int cont = 0;
 for(int i = 0; i < n  ; i++){
    dest[n+i] = fuente[i];
    cont++;
  }
}
