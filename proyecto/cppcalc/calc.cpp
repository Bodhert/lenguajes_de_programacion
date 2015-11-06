#include <iostream>
#include <sstream>
#include <string>
#include "calcex.h"
#include "calculator.h"
using namespace std;

Calculator* calc;

int main(int argc, char* argv[]) {
  string line;
  calc = new Calculator();
  while(true){
    try {
      
      cout << ">  ";
      
      getline(cin, line);
      
      // line + '\n';
      if(!cin.eof()){               // 
	//calc = new Calculator();
	
	int result = calc->eval(line);
	
	cout << "=>  " << result << endl;
	
	//delete calc;
      }else
	break;      
    }
    catch(Exception ex) {
      cout << "Program Aborted due to exception!" << endl;
    }
  }
  delete calc;
}
