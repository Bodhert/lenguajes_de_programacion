#include "Difusores.h"
#include <iostream>
using namespace std;

int main(){
  DifusorCentral obj(10,15);
  cout << obj.potenciaDifusion(10) << endl;
  return 0;
}
