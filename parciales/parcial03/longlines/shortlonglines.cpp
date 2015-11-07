#include <iostream>
#include <string>

using namespace std;

// string v(string n){
//   string result;
//   if(in[in.size()-1] == 92 && !cin.eof()){
//     result += in.substr(0,in.size()-1);
//   }
//   return result;
// }

int
main() {
  string in;
  string result;
  while(cin >> in){
    if(in[in.size()-1] == 92){
      result += in.substr(0,in.size()-1);
      cout << result << endl; 
    }else{
      cout << in << endl;
    }

    if(!cin.eof()) break;
        
  }
  return 0;
}
