
/*
 * fichero: apuntadores02.cpp
 *
 * compilar: $ g++ -o apuntadores02 apuntadores02.cpp9
 * ejecutar: $ ./apuntadores
 *
 * proposito: Apuntadores de varios tipos
 */
#include <iostream>

using namespace std;

void print(int *);
void print(char *);
void print(double *);
void print(void *);

int
main(void) {
  int i = 10;
  char c = 'a';
  double d = 78.3e-100;

  int* pI = &i;
  char* pC = &c;
  double *pD = &d;

  print(pI);
  print(pC);
  print(pD);
  
  print((void *)pI);
    print((void *)pC);
    print((void *)pD);

    cout << "Tmano de apuntador entero: " << sizeof(pI) << endl;
    cout << "Tmano de apuntador caracter: " << sizeof(pC) << endl;
    cout << "Tmano de apuntador double: " << sizeof(pD) << endl;
    cout << "Tmano de apuntador void:  " << sizeof(void *) << endl;
    
    
    
  return 0;
}

void print(int *p) {

  cout << "Direccion: " << p
       << " contenido: " << *p
       << endl;
  return;
}

void print(char *p) {

  cout << "Direccion: " << p
       << " contenido: " << *p
       << endl;
  return;
}

void print(double *p) {

  cout << "Direccion: " << p
       << " contenido: " << *p
       << endl;
  return;
}

void print(void *p) {

  cout << "Direccion: " << p
       << endl;
  return;
}
