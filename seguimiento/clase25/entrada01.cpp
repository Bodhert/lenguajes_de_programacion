
/*
 * fichero: entrada01.cpp
 * compilar: $ g++ -o entrada01 entrada01.cpp
 * ejecutar: $ ./entrada01
 *
 * proposito: Mostrar como se leen datos de la entrada estandar
 *            de los tipos de datos b&aacute;sicos
 */
#include <iostream>
#include <limits>

using namespace std;

int
main() {

  int unEntero;
  long unLargo;
  double unDoble;
  float unFlotante;
  bool unBooleano;
  char unCaracter;

  cout << "leer un entero (" << numeric_limits<int>::min()
       << "," << numeric_limits<int>::max() << "): ";
  cin >> unEntero;

  cout << "leer un entero largo (" << numeric_limits<long>::min()
       << "," << numeric_limits<long>::max() << "): ";
  cin >> unLargo;

  cout << "leer un valor doble (" << numeric_limits<double>::min()
       << "," << numeric_limits<double>::max() << "): ";
  cin >> unDoble;

  cout << "leer un valor flotante (" << numeric_limits<float>::min()
       << "," << numeric_limits<float>::max() << "): ";
  cin >> unFlotante;

  cout << "leer un valor booleano (" << numeric_limits<bool>::min()
       << "," << numeric_limits<bool>::max() << "): ";
  cin >> unBooleano;

  cout << "leer un valor caracter (" << numeric_limits<char>::min()
       << "," << numeric_limits<char>::max() << "): ";
  cin >> unCaracter;

  cout << "\n\nentero leido:\t" << unEntero << endl;
  cout << "entero largo leido:\t" << unLargo << endl;
  cout << "doble leido:\t" << unDoble << endl;
  cout << "flotante leido:\t" << unFlotante << endl;
  cout << "booleano leido:\t" << unBooleano << endl;
  cout << "caracter leido:\t" << unCaracter << endl;

  return 0;
}
