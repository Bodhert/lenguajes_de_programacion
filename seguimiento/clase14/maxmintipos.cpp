
/* Ejemplo maxmintipos.cpp
 *
 * compilar: $ g++ -o maxmintipos maxmintipos.cpp
 * ejecutar: $ ./maxmintipos
 *
 * Proposito: muestra los tipos de datos basicos y su valores m&aacute;ximos
 */
#include <iostream>
#include <limits>

int main() {

  std::cout << "min int = "
	    << std::numeric_limits<int>::min() << std::endl;
  std::cout << "max bool = "
	    << std::numeric_limits<bool>::max() << std::endl;
  std::cout << "min bool = "
	    << std::numeric_limits<bool>::min() << std::endl;
  std::cout << "max int = "
	    << std::numeric_limits<int>::max() << std::endl;
  std::cout << "min char = "
	    << std::numeric_limits<char>::min() << std::endl;
  std::cout << "max char = "
	    << std::numeric_limits<char>::max() << std::endl;
  std::cout << "min long int = "
	    << std::numeric_limits<long int>::min() << std::endl;
  std::cout << "max long int = "
	    << std::numeric_limits<long int>::max() << std::endl;
  std::cout << "min float = "
	    << std::numeric_limits<float>::min() << std::endl;
  std::cout << "max float = "
	    << std::numeric_limits<float>::max() << std::endl;
  std::cout << "min double = "
	    << std::numeric_limits<double>::min() << std::endl;
  std::cout << "max double = "
	    << std::numeric_limits<double>::max() << std::endl;
  std::cout << "min short int = "
	    << std::numeric_limits<short int>::min() << std::endl;
  std::cout << "max short int = "
	    << std::numeric_limits<short int>::max() << std::endl;
  std::cout << "min long int = "
	    << std::numeric_limits<long int>::min() << std::endl;
  std::cout << "max long int = "
	    << std::numeric_limits<long int>::max() << std::endl;
  std::cout << "min long long = "
	    << std::numeric_limits<long long>::min() << std::endl;
  std::cout << "max long long = "
	    << std::numeric_limits<long long>::max() << std::endl;
  std::cout << "min long double = "
	    << std::numeric_limits<long double>::min() << std::endl;
  std::cout << "max long double = "
	    << std::numeric_limits<long double>::max() << std::endl;
  std::cout << "min short = "
	    << std::numeric_limits<short>::min() << std::endl;
  std::cout << "max short = "
	    << std::numeric_limits<short>::max() << std::endl;
  std::cout << "min long = "
	    << std::numeric_limits<long>::min() << std::endl;
  std::cout << "max long = "
	    << std::numeric_limits<long>::max() << std::endl;
  
  return 0;
}
