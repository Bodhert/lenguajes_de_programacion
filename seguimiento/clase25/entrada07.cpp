
/*
 * fichero: entrada07.cpp
 * compilar: $ g++ -o entrada07 entrada07.cpp
 * ejecutar: $ ./entrada07
 * proposito: Mostrar como se leen datos de la entrada estandar.
 *            utilizando flujos de tipo string
 */
#include <iostream>
#include <string>
#include <sstream>

const int MAXBUF = 256;

using namespace std;

int
main() {

  char buffer[MAXBUF];

  cout << "Digite un entero, un caracter, un entero y una cadena"
       << endl;

  cin.getline(buffer,MAXBUF);

  string buffer2(buffer);

  istringstream ins(buffer2);

  int number1;
  char c;
  int number2;
  char cadena2[MAXBUF];

  ins >> number1 >> c >> number2 >> cadena2;

  cout << "Number1: " << number1
       << " Number2: " << number2
       << " Cadena2: " << cadena2
       << endl;

  return 0;

}
