
/*
 * fichero: entrada03.cpp
 * compilar: $ g++ -o entrada03 entrada03.cpp
 *
 * ejecutar: $ ./entrada03
 * proposito: Mostrar como se leen los datos sin formato
 *            hasta que el caracter '\n' es le&iacute;do o hasta n.
 *            En algunas ocasiones se puede cambiar el caracter
 *            delimitador.
 */
#include <iostream>

using namespace std;

int
main() {
  const streamsize TOTALDATOS = 25;
  char* elementos = new char[TOTALDATOS];

  cout << "Entre la linea 1 (max 24 caracteres): ";
  cin.getline(elementos, TOTALDATOS);

  if (!cin) {
    cerr << "Problemas en el flujo de entrada" << endl;
  }
  else {
    cout << elementos << endl;
  }

  cout << "Entre la linea 2 (max 24 caracteres o la primera 'a'): ";

  cin.getline(elementos, TOTALDATOS, 'a');

  if (!cin) {
    cerr << "Problemas en el flujo de entrada" << endl;
  }
  else {
    cout << elementos << endl;
  }

  cout << "Aqui la linea 3 (max 24 caracteres): ";

  cin.getline(elementos, TOTALDATOS);

  if (!cin) {
    cerr << "Problemas en el flujo de entrada" << endl;
  }
  else {
    cout << elementos << endl;
  }

  return 0;
}
