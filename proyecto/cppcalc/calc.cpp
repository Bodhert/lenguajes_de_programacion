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
  bool amb = true;
  calc = new Calculator();
  
  calc -> amb(env);
  
  pref = false;
  
  for(int i = 1; i < argc; i++){
    comand = argv[i];  
    if(comand == "-e"){
      pref = true;
    }else if(comand == "-v"){
      i++;
      string v = argv[i];
      if(pref){
	if(!(calc -> vars(v))){
	  size_t cut = v.find("=");
	  string asi = v.substr(0,cut);
	  string gn = v.substr(cut+1,v.size());
	  istringstream buffer(gn);
	  int value;
	  buffer >> value;
	  calc -> assignate(asi,value);
	}
      }else{
	size_t cut = v.find("=");
	string asi = v.substr(0,cut);
	string gn = v.substr(cut+1,v.size());
	istringstream buffer(gn);
	int value;
	buffer >> value;
	calc -> assignate(asi,value);
      }
    }

    int max =200;
    size_t found = comand.find(".");
    if(found != string::npos){
      amb = false;
      char n[max];
      ifstream file(argv[i]);
      while(file.getline(n,max)){
       	string ton(n);
       	calc -> eval(ton);
      }	
      file.close();
    }
  }
  
  
  
  while(amb){
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
