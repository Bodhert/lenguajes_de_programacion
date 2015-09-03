
/* Ejemplo maxmin_sig_un_int.cpp
 *
 * compilar: $ g++ -o maxmin_sig_un_int maxmin_sig_un_int.cpp
 * ejecutar: $ ./maxmin_sig_un_int
 *
 * Proposito: muestra los tipos enteros con signo y sin signo con
 *            valores min y max
 */

#include <iostream>
#include <limits>

int main() {

  std::cout << "min unsigned int = "
	    << std::numeric_limits<unsigned int>::min()
            << std::endl;
  std::cout << "max unsigned int = "
	    << std::numeric_limits<unsigned int>::max()
            << std::endl;

  std::cout << "min signed int = "
	    << std::numeric_limits<signed int>::min()
            << std::endl;
  std::cout << "max signed int = "
	    << std::numeric_limits<signed int>::max()
            << std::endl;

  std::cout << "min int = "
	    << std::numeric_limits<int>::min()
            << std::endl;
  std::cout << "max int = "
	    << std::numeric_limits<int>::max()
            << std::endl;

  std::cout << "min unsigned long = "
	    << std::numeric_limits<unsigned long>::min()
            << std::endl;
  std::cout << "max unsigned long = "
	    << std::numeric_limits<unsigned long>::max()
            << std::endl;

  std::cout << "min signed long = "
	    << std::numeric_limits<signed long>::min()
            << std::endl;
  std::cout << "max signed long = "
	    << std::numeric_limits<signed long>::max()
            << std::endl;

  std::cout << "min long = "
	    << std::numeric_limits<signed long>::min()
            << std::endl;
  std::cout << "max long = "
	    << std::numeric_limits<signed long>::max()
            << std::endl;

  std::cout << "min unsigned char = "
	    << int(std::numeric_limits<unsigned char>::min())
            << std::endl;
  std::cout << "max unsigned char = "
	    << int(std::numeric_limits<unsigned char>::max())
            << std::endl;

  std::cout << "min signed char = "
	    << int(std::numeric_limits<char>::min())
            << std::endl;
  std::cout << "max signed char = "
	    << int(std::numeric_limits<char>::max())
            << std::endl;

  std::cout << "min char = "
	    << std::numeric_limits<char>::min()
            << std::endl;
  std::cout << "max char = "
	    << std::numeric_limits<char>::max()
            << std::endl;

  std::cout << "min unsigned short  = "
	    << std::numeric_limits<unsigned short>::min()
            << std::endl;
  std::cout << "max unsigned short  = "
	    << std::numeric_limits<unsigned short>::max()
            << std::endl;

  std::cout << "min signed short  = "
	    << std::numeric_limits<signed short>::min()
            << std::endl;
  std::cout << "max signed short  = "
	    << std::numeric_limits<signed short>::max()
            << std::endl;

  std::cout << "min short  = "
	    << std::numeric_limits<short>::min() << std::endl;
  std::cout << "max short  = "
	    << std::numeric_limits<short>::max() << std::endl;
  return 0;
}
