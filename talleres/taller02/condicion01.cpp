/*
 * fichero: condicion01.cpp
 * compilar: $ g++ -o condicion01 condicion01.cpp
 *           $ make condicion01
 * ejecutar: $ ./condicion01
 */
#include <iostream>
#include <stdio.h>
using namespace std;

int
main() {
   int c;
   cin >> c ? c == 0 ? cout << "el usuario digito un valor de 0 "<<endl : cout << "el usuario digito un valor diferente de 0 "<< endl: cout << "no leyo bien "<<endl;
   return 0;
}
