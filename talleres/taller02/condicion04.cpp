#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  double a,b,c;
  cin >> a >> b >> c;
  double minimo = min(min(a,b),c);
  double maximo = max(max(a,b),c);
  double intermedio;
  if(minimo == c) intermedio = min(a,b);
  else intermedio = max(min(a,c),min(c,b));
  cout << minimo << " " << intermedio << " " << maximo << endl;
}
