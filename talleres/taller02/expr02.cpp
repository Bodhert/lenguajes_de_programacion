#include <iostream>
#include <algorithm>

using namespace std;

int main(){

  int a,b,c;
  cin >> a >> b >> c;
  int minimo = min(min(a,b),c);
  int maximo = max(max(a,b),c);
  int intermedio;
  if(minimo == c) intermedio = min(a,b);
  else intermedio = max(min(a,c),min(c,b));
  cout << minimo << " " << intermedio << " " << maximo << endl;
  
}
