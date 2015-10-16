#include <iostream>

using namespace std;
int main(){
  double l1 ,l2 ,l3;
  cin >> l1 >> l2 >> l3;
  if(l1 == l2 && l2 == l3){
    cout << "equilatero" << endl;
  }else if(l1 != l2 && l2 != l3 && l3 != l1 ){
    cout << "escaleno" << endl;
  }else
    cout << "isoceles" << endl;
  return 0;
}
