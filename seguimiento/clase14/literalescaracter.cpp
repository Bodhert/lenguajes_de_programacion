
/* Ejemplo literalescaracter.cpp
 *
 * compilar: $ g++ -o literalescaracter literalescaracter.cpp
 * ejecutar: $ ./literalescaracter
 * Proposito: Mostrar los literales de caracteres.
 */

#include <iostream>

// Esta es una definicion y declaracion
int
main() {
  char c; // Declara variable
  std::cin >> c;
  std::cout << "el valor de '" << c
	    << "' es " << int(c) << std::endl;

  // Establecer un literal de caracter
  c = 'a';
  std::cout << "el valor de " << c << std::endl;

  // Establecer un literal de caracter con un valor octal
  c = '\101';
  std::cout << "el valor de " << c << std::endl;

  // Establecer un literal de caracter con un valor hexadecimal
  c = 0x42;
  std::cout << "el valor de " << c << std::endl;

  c = 67;
  std::cout << "el valor de " << c << std::endl;

  return 0;
}
