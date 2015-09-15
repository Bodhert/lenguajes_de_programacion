
/*
 * fichero: arreglos04.cpp
 *
 * compilar: $ g++ -o arreglos04 arreglos04.cpp
 * ejecutar: $ ./arreglos04
 *
 * proposito: mostrar como se inicializan arreglos de
 *            de caracteres.
 */
#include <iostream>

using namespace std;

int
main(void) {

  char a4[] = { 'a', 'b', 'c', 0 };
  char a5[] = {97,98,99,0};

  cout << a4 << endl;
  cout << "tamano de a4 " <<sizeof(a4) << endl;
  cout << a5 << endl;

  return 0;
}
