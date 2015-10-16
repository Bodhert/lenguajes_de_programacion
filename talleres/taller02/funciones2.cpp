#include "funciones2.h"
#include <iostream>

using namespace std;

int mcd (int a, int b){
  int r = 1;
  while(r != 0){
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

void simpFrac(int a, int b){
  int MCD = mcd(a,b);
  cout << a/MCD<<"/"<< b/MCD <<endl;;
 }

