#include <iostream>

using namespace std;

int main (){
  int a, b;
  
  while(cin >> a >> b){
    int acum = 0;
    for(int i = a ; i <= b; i++){
      acum += i;
    }
    cout << acum << endl;
  }
  return 0;
}
