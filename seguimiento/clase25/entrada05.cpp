
/*
 * fichero: entrada05.cpp
 * compilar: $ g++ -o entrada05 entrada05.cpp
 * ejecutar: $ ./entrada05
 *
 * proposito: Mostrar como se leen datos de la entrada estandar.
 */
#include <iostream>

const int MAXBUF = 256;

using namespace std;

int
main() {
  char cadena[MAXBUF];

  cout << "Entre una cadena larga: ";
  cin >> cadena;

  cout << "\n\ncadena:\t" << cadena << endl;

  return 0;
}
