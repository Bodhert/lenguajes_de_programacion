
/*
 * fichero: entrada06.cpp
 * compilar: $ g++ -o entrada06 entrada06.cpp
 * ejecutar: $ ./entrada06
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

  cin.getline(cadena, MAXBUF);
  cout << "\n\ncadena:\t" << cadena << endl;

  return 0;
}
