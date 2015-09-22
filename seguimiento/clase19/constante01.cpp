
/* fichero: constante01.cpp
 *
 * compilar: $ g++ -o constante01 constante01.cpp
 * nota: compila con errores
 * prop&oacute;sito: Mostrar como el compilador controla
 */
void
f(const int* p) {
  *p = 10;
}

int
main() {
  int a;
  a = 40;

  f(&a);

  return 0;

}
