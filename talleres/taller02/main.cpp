#include <iostream>
#include "funciones.h"
using namespace std;

int main(){
  int a = 0, b = 0, c = 0;
  cin >> a >> b >> c;
  cout << sumaEnt(a,sumaEnt(b,multEnt(c,multEnt(sumaEnt(multEnt(a,b),c),restaEnt(a,b))))) << endl;
  return 0;
}
