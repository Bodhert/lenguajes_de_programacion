#include <iostream>

using namespace std;
int main(){
  char a[2];
  cin >> a ;
  if(a[0]%2 == 1 && a[1]%2 == 1 || a[0]%2 == 0 && a[1]%2 == 0)
    cout << "blanco"<< endl;
  else 
    cout << "negro" << endl;

  return 0;
}
