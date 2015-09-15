
/*
 * fichero: estructura01
 *
 * compilar: $ g++ -o estructura01 estructura01.cpp
 * ejecutar: $ ./estructura01
 *
 * proposito: Mostrar estructuras 
 */
#include <iostream>

using namespace std;
struct Empleado {
  char nombre[30];
  char id[30];
  int tipoID;
};

struct Empleado2 {
  char *nombre;
  char *id;
  int tipoID;
};

int
main() {

  struct Empleado emp1 = { "Juan", "XXXX", 1 };
  Empleado emp2 = { "Diego", "YYYY", 1 };
  Empleado2 emp3 = { "Alejandro", "WWWW", 1 };
  Empleado* pEmp;

  pEmp = &emp1;
  pEmp->tipoID = 2;
  cout << pEmp->nombre << " " << pEmp->tipoID << endl;

  pEmp = &emp2;
  
  pEmp->tipoID = 2;
  cout << pEmp->nombre << " " << pEmp->tipoID << endl;

  pEmp = &emp1;

  pEmp->nombre[0] = 'j';
  cout << pEmp->nombre << " " << pEmp->tipoID << endl;

  Empleado2 *pEmp2;
   pEmp2 = &emp3;

  pEmp2->nombre[0] = 'a';
  cout << pEmp2->nombre << " " << pEmp2->tipoID << endl; 
  return 0;
}
