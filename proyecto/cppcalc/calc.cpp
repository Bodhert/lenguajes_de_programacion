#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "calcex.h"
#include "calculator.h"
#include <cstddef>

using namespace std;

Calculator* calc;

int main(int argc, char* argv[], char* env[]) {
  string line;
  string comand;
  string toEval;
  int result;
  bool pref;
  calc = new Calculator();
  // cout << "antes de interactivo"<< endl;
  
  for (int j = 1; env[j] != NULL; j++){
    string envi = env[j];
    if(envi.find("CALCVAR")==0){
      toEval = envi.substr(7,envi.size());
      result = calc -> eval(toEval);
    }
  }  
  
  for(int i = 1; i < argc; i++){
    comand = argv[i];
    pref = true;
    if(comand == "-e"){
      for (int j = 1; env[j] != NULL; j++){
	string envi = env[j];
	if(envi.find("CALCVAR")==0){
	  pref = false;
	  toEval = envi.substr(7,envi.size());
	  result = calc -> eval(toEval);
	  i++;
	  comand = argv[i];
	}
      }
    }

    if(comand == "-v" && pref){
      toEval = argv[i+1];
      result = calc -> eval(toEval);
    }

    size_t found = comand.find(".");
    if(found != string::npos ){
      ifstream file(argv[i]);
      if(file.is_open()){
	while(getline(file,toEval)){
	  result = calc -> eval(toEval);
	  // cout << result << endl;
	}
	file.close();
      }
    }
  }
  
  
  while(true){
    try {
      
      cout << ">  ";
      
      getline(cin, line);
      
      // line + '\n';
      if(!cin.eof()){               // 
  	//calc = new Calculator();
	
  	 calc->eval(line);
	
	//cout << result << "[" <<  resultExtl << "]" << endl;

  	//cout << resultExtl << "=>  " << result << endl;
	
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
